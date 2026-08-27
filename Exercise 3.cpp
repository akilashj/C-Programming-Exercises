//
// Created by Akila Shashiduni on 2026.08.27.
//
#include <stdio.h>

int main(void)
{
    int count;
    int student;
    int grade;
    int i;

    printf("How many students: ");
    scanf("%d", &count);

    int grades[count];

    /* Initialize all grades to -1 */
    for(i = 0; i < count; i++)
    {
        grades[i] = -1;
    }

    do
    {
        printf("Enter student number (1 - %d) or 0 to stop: ", count);

        if(scanf("%d", &student) != 1)
        {
            while(getchar() != '\n');
            printf("Invalid input!\n");
            continue;
        }

        if(student != 0)
        {
            if(student >= 1 && student <= count)
            {
                do
                {
                    printf("Enter grade (0 - 5) for student %d or -1 to cancel: ",
                           student);

                    if(scanf("%d", &grade) != 1)
                    {
                        while(getchar() != '\n');
                        printf("Invalid grade!\n");
                        grade = -2;
                    }
                    else if(grade < -1 || grade > 5)
                    {
                        printf("Invalid grade!\n");
                    }

                } while(grade < -1 || grade > 5);

                if(grade != -1)
                {
                    grades[student - 1] = grade;
                }
            }
            else
            {
                printf("Invalid student number!\n");
            }
        }

    } while(student != 0);

    printf("\nStudent Grade\n");

    for(i = 0; i < count; i++)
    {
        if(grades[i] == -1)
        {
            printf("%d N/A\n", i + 1);
        }
        else
        {
            printf("%d %d\n", i + 1, grades[i]);
        }
    }

    return 0;
}