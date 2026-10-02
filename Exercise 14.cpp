//
// Created by Akila Shashiduni on 2026.10.02.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LINE_LEN 81

int main(void) {
    char filename[256];
    char lines[MAX_LINES][MAX_LINE_LEN];
    int line_count = 0;

    printf("Enter a filename: ");
    if (scanf("%255s", filename) != 1) {
        fprintf(stderr, "Error reading filename.\n");
        return 1;
    }


    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        return 1;
    }


    while (line_count < MAX_LINES && fgets(lines[line_count], MAX_LINE_LEN, file) != NULL) {
        line_count++;
    }
    fclose(file);


    for (int i = 0; i < line_count; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            lines[i][j] = (char)toupper((unsigned char)lines[i][j]);
        }
    }


    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s' for writing\n", filename);
        return 1;
    }


    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], file);
    }

    fclose(file);
    printf("Successfully converted %d line(s) to uppercase in '%s'.\n", line_count, filename);

    return 0;
}