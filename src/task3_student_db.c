#include <stdio.h>
#include <stdlib.h>
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
    double grade;
} Student;

static void chomp(char *s) {
    size_t len = strlen(s);
    if (len && s[len-1] == '\n') s[len-1] = '\0';
}

int main(void) {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number\n");
        return 1;
    }
    // input buffer temizle
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    Student *db = (Student *)calloc((size_t)n, sizeof(Student));
    if (!db) {
        fprintf(stderr, "Allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter Student #%d name: ", i + 1);
        if (!fgets(db[i].name, NAME_LEN, stdin)) { free(db); return 1; }
        chomp(db[i].name);

        printf("Enter Student #%d age: ", i + 1);
        if (scanf("%d", &db[i].age) != 1) { free(db); return 1; }

        printf("Enter Student #%d grade: ", i + 1);
        if (scanf("%lf", &db[i].grade) != 1) { free(db); return 1; }

        while ((c = getchar()) != '\n' && c != EOF) {} // sonraki satıra temiz geç
    }

    // Biçimli tablo yazdır
    printf("\n%-4s %-30s %-5s %-6s\n", "No.", "Name", "Age", "Grade");
    printf("---- ------------------------------ ----- ------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d %-30s %-5d %-6.1f\n", i + 1, db[i].name, db[i].age, db[i].grade);
    }

    free(db);
    return 0;
}
