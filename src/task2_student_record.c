#include <stdio.h>
#include <string.h>

/*
    Name:Mehmet Kaan ULU
    Student ID:231ADB102
    Group: 2
    */


#define NAME_LEN 64

typedef struct {
    char  name[NAME_LEN];
    int   age;
    double grade;   // örn: 7.5 gibi
} Student;

static void chomp(char *s) {
    size_t len = strlen(s);
    if (len && s[len-1] == '\n') s[len-1] = '\0';
}

int main(void) {
    Student s;

    printf("Enter name: ");
    if (!fgets(s.name, sizeof s.name, stdin)) return 1;
    chomp(s.name);

    printf("Enter age: ");
    if (scanf("%d", &s.age) != 1) return 1;

    printf("Enter grade: ");
    if (scanf("%lf", &s.grade) != 1) return 1;

    printf("Student: %s, Age: %d, Grade: %.1f\n", s.name, s.age, s.grade);
    return 0;
}
