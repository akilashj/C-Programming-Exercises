//
// Created by Akila Shashiduni on 2026.10.12.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 50
#define NAME_SIZE 64

#define COLOR_RESET  "\033[0m"
#define COLOR_RED    "\033[1;31m"
#define COLOR_GREEN  "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_CYAN   "\033[1;36m"
#define COLOR_BOLD   "\033[1m"

typedef struct {
    char name[NAME_SIZE];
    int score;
    int grade;
} Subject;

// Function prototypes
int calculate_grade(int score);
const char* get_performance_status(double avg);
int read_int(const char *prompt, int min, int max);

int main(void) {
    char student_name[NAME_SIZE];
    Subject subjects[MAX_SUBJECTS];

    printf("%sWelcome to the Student Grade Calculator!%s\n", COLOR_CYAN, COLOR_RESET);
    printf("Please enter your name: ");
    if (fgets(student_name, sizeof(student_name), stdin) != NULL) {
        student_name[strcspn(student_name, "\n")] = '\0';
    }

    int subject_count = read_int("How many subjects do you want to calculate grades for? ", 1, MAX_SUBJECTS);

    double total_grade_points = 0;
    for (int i = 0; i < subject_count; i++) {
        printf("\nEnter subject %d name: ", i + 1);
        fgets(subjects[i].name, sizeof(subjects[i].name), stdin);
        subjects[i].name[strcspn(subjects[i].name, "\n")] = '\0';

        subjects[i].score = read_int("Enter score (0-100): ", 0, 100);
        subjects[i].grade = calculate_grade(subjects[i].score);
        total_grade_points += subjects[i].grade;
    }

    double average_grade = total_grade_points / subject_count;

    return 0;
}

int calculate_grade(int score) {
    if (score >= 90) return 5;
    if (score >= 80) return 4;
    if (score >= 70) return 3;
    if (score >= 60) return 2;
    if (score >= 50) return 1;
    return 0;
}

const char* get_performance_status(double avg) {
    if (avg >= 4.5) return "EXCELLENT (Honors List)";
    if (avg >= 3.5) return "VERY GOOD";
    if (avg >= 2.5) return "GOOD";
    if (avg >= 1.0) return "PASS";
    return "NEEDS IMPROVEMENT";
}

int read_int(const char *prompt, int min, int max) {
    int val;
    char buffer[64];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &val) == 1 && val >= min && val <= max) {
                return val;
            }
        }
        printf("%sInvalid input! Please enter a number between %d and %d.%s\n", COLOR_RED, min, max, COLOR_RESET);
    }
}