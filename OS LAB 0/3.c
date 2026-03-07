#include <stdio.h>

int main() {
    int rows, cols;
    int matrix[50][50];
    int i, j;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of the %dx%d matrix:\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        int row_sum = 0;
        for (j = 0; j < cols; j++) {
            row_sum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, row_sum);
    }

    for (j = 0; j < cols; j++) {
        int col_sum = 0;
        for (i = 0; i < rows; i++) {
            col_sum += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, col_sum);
    }

    return 0;
}
