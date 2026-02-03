#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    char name[50];
    int mark;
} Student;

int compareByMarkDesc(const void *a, const void *b)
{
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return s2->mark - s1->mark;
}

int compareByFirstCharAsc(const void *a, const void *b)
{
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    return s1->name[0] - s2->name[0];
}

int main()
{
    Student students[MAX];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter student's name and mark: ");
        scanf("%s %d", students[i].name, &students[i].mark);
    }

    Student studentsByName[MAX];
    memcpy(studentsByName, students, sizeof(Student) * n);

    qsort(students, n, sizeof(Student), compareByMarkDesc);
    printf("\nPrimary Sort: (Descending)\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", students[i].name, students[i].mark);
    }

    qsort(studentsByName, n, sizeof(Student), compareByFirstCharAsc);
    printf("\nSecondary Sort: (Ascending)\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", studentsByName[i].name, studentsByName[i].mark);
    }

    return 0;
}

