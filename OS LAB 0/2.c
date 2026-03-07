#include <stdio.h>

int main() {
    int n, i, j;
    int matrix[50][50];
    int sum = 0;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of left diagonal = %d\n", sum);

    return 0;
}
