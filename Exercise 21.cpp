//
// Created by Akila Shashiduni on 2026.10.12.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 512

int main(void) {
    char filename[256];

    printf("Enter NMEA file name: ");
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Error reading filename.\n");
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        return 1;
    }

    char line[LINE_SIZE];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *start = strchr(line, '$');
        char *asterisk = strchr(line, '*');

        if (start != NULL && asterisk != NULL && asterisk > start) {
            unsigned char calculated_checksum = 0;


            for (char *ptr = start + 1; ptr < asterisk; ptr++) {
                calculated_checksum ^= (unsigned char)(*ptr);
            }

            unsigned int file_checksum = 0;
            if (sscanf(asterisk + 1, "%2x", &file_checksum) == 1) {
                if (calculated_checksum == (unsigned char)file_checksum) {
                    printf("[ OK ] %s", line);
                } else {
                    printf("[FAIL] %s", line);
                }
            } else {
                printf("[FAIL] %s", line);
            }
        }
    }

    fclose(file);
    return 0;
}