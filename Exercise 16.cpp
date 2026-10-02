//
// Created by Akila Shashiduni on 2026.10.02.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int number;
    struct node *next;
} node;

int main(void) {
    char input[64];
    node *head = NULL;
    node *tail = NULL;

    while (1) {
        printf("Enter a number or 'end' to stop: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }


        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }


        if (strcmp(input, "end") == 0) {
            break;
        }

        int val;

        if (sscanf(input, "%d", &val) == 1) {

            node *new_node = (node *)malloc(sizeof(node));
            if (new_node == NULL) {
                fprintf(stderr, "Memory allocation failed!\n");
                break;
            }
            new_node->number = val;
            new_node->next = NULL;


            if (head == NULL) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        } else {
            printf("Invalid input! Please enter an integer or 'end'.\n");
        }
    }


    printf("\nEntered numbers:\n");
    node *curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->number);
        curr = curr->next;
    }


    curr = head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}