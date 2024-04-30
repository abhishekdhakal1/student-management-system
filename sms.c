#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char name[20];
    int roll;
    char course[20];
    float GPA;
} std[100];

int n = 0;

FILE *fptr, *fptr1;

void options();
void addstudent();
void find_roll();
void find_name();
void del_student();
void find_course();
void count_std();
void exit_p();

int main()
{
    int choice;
    while (1)
    {
        printf("\t\t\t-----------Welcome to Student Management System-----------\n");
        options();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addstudent();
            break;
        case 2:
            find_roll();
            break;
        case 3:
            find_name();
            break;
        case 4:
            del_student();
            break;
        case 5:
            find_course();
            break;
        case 6:
            count_std();
            break;
        case 7:
            exit_p();
            break;
        default:
            printf("Invalid Option\n");
            break;
        }
    }
}

void options()
{
    printf("\nChoose your Options \n");
    printf("1. Add the student details.\n");
    printf("2. Find the student by roll no.\n");
    printf("3. To find the student by name.\n");
    printf("4. To delete the student record.\n");
    printf("5. Find the students registered in a course.\n");
    printf("6. Count the total number of students.\n");
    printf("7. Exit program.\n");
}

void addstudent()
{
    fptr = fopen("student.txt", "ab+");
    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    printf("\t\t------Add Student Details------\n");
    fflush(stdin);
    printf("Enter the name of the student: ");
    gets(std[n].name);

    printf("Enter the roll no: ");
    scanf("%d", &std[n].roll);

    printf("Enter the faculty of the student: ");
    scanf("%s", std[n].course);

    printf("Enter the GPA of student: ");
    scanf("%f", &std[n].GPA);

    fwrite(&std[n], sizeof(struct student), 1, fptr);
    fclose(fptr);
    n++;
}

void del_student()
{
    char name[20];
    int dat = 0;
    printf("\t\t------Delete Student Details------\n");
    printf("Enter the name you want to delete: ");
    fflush(stdin);
    gets(name);

    fptr = fopen("student.txt", "rb");
    fptr1 = fopen("temp.txt", "wb");

    if (fptr == NULL || fptr1 == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int found = 0;
    for (int j = 0; j < n; j++)
    {
        if (strcmp(std[j].name, name) == 0)
        {
            found = 1;
            continue;
        }
        fwrite(&std[j], sizeof(struct student), 1, fptr1);
    }
    n--;
    fclose(fptr);
    fclose(fptr1);

    if (found)
    {
        remove("student.txt");
        rename("temp.txt", "student.txt");
        printf("Data deleted successfully.\n");
    }
    else
    {
        printf("Data not found.\n");
    }
}

void find_roll()
{
    int roll, dat = 0;
    printf("\t\t------Find Students by Roll no.------\n");
    printf("Enter the roll no: ");
    scanf("%d", &roll);

    fptr = fopen("student.txt", "rb");

    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (std[j].roll == roll)
        {
            printf("\nThe name of student is %s\n", std[j].name);
            printf("The roll no of the student is %d\n", std[j].roll);
            printf("The faculty of student is %s\n", std[j].course);
            printf("The student GPA is %f\n", std[j].GPA);
            dat++;
        }
    }

    fclose(fptr);

    if (dat == 0)
    {
        printf("\nData not found.\n");
    }
}

void find_name()
{
    char name[20];
    int dat = 0;
    printf("\t\t------Find Students by Name.------\n");
    printf("Enter the name: ");
    fflush(stdin);
    gets(name);

    fptr = fopen("student.txt", "rb");

    if (fptr == NULL)
    {
        printf("\nError opening file\n");
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (strcmp(std[j].name, name) == 0)
        {
            printf("\nThe name of student is %s\n", std[j].name);
            printf("The roll no of the student is %d\n", std[j].roll);
            printf("The faculty of student is %s\n", std[j].course);
            printf("The student GPA is %f\n", std[j].GPA);
            dat++;
        }
    }

    fclose(fptr);

    if (dat == 0)
    {
        printf("\nData not found.\n");
    }
}

void find_course()
{
    char course[20];
    int dat = 0;
    printf("\n\t\t------Find Students Enrolled in a course.------\n");
    printf("Enter the course: ");
    fflush(stdin);
    gets(course);

    fptr = fopen("student.txt", "rb");

    if (fptr == NULL)
    {
        printf("\nError opening file\n");
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (strcmp(std[j].course, course) == 0)
        {
            printf("\nThe name of student is %s\n", std[j].name);
            printf("The roll no of the student is %d\n", std[j].roll);
            printf("The faculty of student is %s\n", std[j].course);
            printf("The student GPA is %f\n", std[j].GPA);
            dat++;
        }
    }

    fclose(fptr);

    if (dat == 0)
    {
        printf("\nData not found.\n");
    }
}
void count_std()
{
    printf("\t\t\n------Total no of students.------\n");
    printf("The total number of student are %d\n", n);
}

void exit_p()
{
    system("cls");
    printf("\t\t--------------Exiting Program----------------\n");
    printf("\t\t ABHISHEK DHAKAL\tTHA080BEIOO1\n");
    printf("\t\t BIBEK PANDEY   \tTHA080BEIO14\n");
    printf("\t\t KESHAR SINGH SUNAR\tTHA080BEIO22\n");
    printf("\t\t PRABESH PARAJULEE\tTHA080BEIO29\n");
    exit(0);
}
