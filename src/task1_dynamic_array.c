#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    Name:Mehmet Kaan ULU
    Student ID:231ADB102
    Group: 2
    */


int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid n\n");
        return 1;
    }

    int *a = (int *)malloc((size_t)n * sizeof(int));
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(a);
            return 1;
        }
    }

    int min = INT_MAX, max = INT_MIN;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
        sum += a[i];
    }

    double avg = (double)sum / (double)n;
    printf("max = %d\nmin = %d\naverage = %.2f\n", max, min, avg);

    free(a);
    return 0;
}
