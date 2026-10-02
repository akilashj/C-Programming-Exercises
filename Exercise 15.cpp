//
// Created by Akila Shashiduni.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 40
#define LINE_SIZE 128

typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;

int main(void) {
    char filename[256];
    menu_item menu[MAX_ITEMS];
    int item_count = 0;

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

    char line[LINE_SIZE];
    while (item_count < MAX_ITEMS && fgets(line, sizeof(line), file) != NULL) {

        char name_buf[50];
        double price_val;

        if (sscanf(line, " %49[^;];%lf", name_buf, &price_val) == 2) {
            strncpy(menu[item_count].name, name_buf, sizeof(menu[item_count].name) - 1);
            menu[item_count].name[sizeof(menu[item_count].name) - 1] = '\0';
            menu[item_count].price = price_val;
            item_count++;
        }
    }
    fclose(file);


    for (int i = 0; i < item_count; i++) {
        printf("%8.2f %s\n", menu[i].price, menu[i].name);
    }

    return 0;
}