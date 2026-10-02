#include <stdio.h>
#include <stdlib.h>

#define FILENAME_SIZE 256

int main(void) {
    char filename[FILENAME_SIZE];

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

    int number;
    int count = 0;
    int lowest = 0;
    int highest = 0;


    while (fscanf(file, "%d", &number) == 1) {
        if (count == 0) {
            lowest = number;
            highest = number;
        } else {
            if (number < lowest) {
                lowest = number;
            }
            if (number > highest) {
                highest = number;
            }
        }
        count++;
    }

    if (count > 0) {
        printf("Count of numbers read: %d\n", count);
        printf("Lowest number: %d\n", lowest);
        printf("Highest number: %d\n", highest);
    } else {
        printf("No valid integers were found in '%s'.\n", filename);
    }

    fclose(file);
    return 0;
}