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


int calculate_grade(int score);
const char* get_performance_status(double avg);
int read_int(const char *prompt, int min, int max);
void print_score_bar(FILE *stream, int score);
void print_report(FILE *stream, const char *student_name, const Subject *subjects, int count, double avg, int use_colors);

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


    print_report(stdout, student_name, subjects, subject_count, average_grade, 1);


    FILE *file = fopen("grade_report.txt", "w");
    if (file != NULL) {
        print_report(file, student_name, subjects, subject_count, average_grade, 0);
        fclose(file);
        printf("\n%sReport successfully saved to 'grade_report.txt'.%s\n", COLOR_GREEN, COLOR_RESET);
    } else {
        fprintf(stderr, "%sError: Could not open file for writing.%s\n", COLOR_RED, COLOR_RESET);
    }

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

void print_score_bar(FILE *stream, int score) {
    int filled = score / 10;
    fprintf(stream, "[");
    for (int i = 0; i < 10; i++) {
        if (i < filled) fprintf(stream, "#");
        else fprintf(stream, ".");
    }
    fprintf(stream, "]");
}

void print_report(FILE *stream, const char *student_name, const Subject *subjects, int count, double avg, int use_colors) {
    const char *header_color = use_colors ? COLOR_CYAN : "";
    const char *bold_color   = use_colors ? COLOR_BOLD : "";
    const char *name_color   = use_colors ? COLOR_YELLOW : "";
    const char *reset_color  = use_colors ? COLOR_RESET : "";

    fprintf(stream, "\n%s==================================================================%s\n", header_color, reset_color);
    fprintf(stream, "%s                   STUDENT GRADE CALCULATOR                       %s\n", header_color, reset_color);
    fprintf(stream, "%s==================================================================%s\n", header_color, reset_color);
    fprintf(stream, " Student Name:   %s%s%s\n", name_color, student_name, reset_color);
    fprintf(stream, " Total Subjects: %d\n", count);
    fprintf(stream, "------------------------------------------------------------------\n");
    fprintf(stream, " %-20s | %-8s | %-7s | %-12s\n", "Subject Name", "Score", "Grade", "Progress");
    fprintf(stream, "------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        const char *grade_color = reset_color;
        if (use_colors) {
            grade_color = (subjects[i].grade >= 3) ? COLOR_GREEN : COLOR_RED;
        }


        fprintf(stream, " %-20s | %3d%%     | ", subjects[i].name, subjects[i].score);


        fprintf(stream, "%s%d%s       | ", grade_color, subjects[i].grade, reset_color);

        
        print_score_bar(stream, subjects[i].score);
        fprintf(stream, "\n");
    }

    fprintf(stream, "==================================================================\n");
    fprintf(stream, " OVERALL AVERAGE GRADE: %s%.2f / 5.00%s\n", name_color, avg, reset_color);
    fprintf(stream, " PERFORMANCE STATUS:   %s%s%s\n", bold_color, get_performance_status(avg), reset_color);
    fprintf(stream, "==================================================================\n");
}