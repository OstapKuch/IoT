//Vasya
#include <stdio.h>
#include <math.h>

#define MATRIX_SIZE 5

int matrix[MATRIX_SIZE][MATRIX_SIZE];

int scanMatrix(), matrixInsertionSort(), sumUnderMainDiagonal(), printMatrixIntoConsole(), averageGeometricSum();

int main() { //scaning array
    scanMatrix();
    matrixInsertionSort();
    printMatrixIntoConsole();
    sumUnderMainDiagonal();
}

int scanMatrix() {

    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int column = 0; column < MATRIX_SIZE; column++) {
            scanf("%i", &matrix[row][column]);
        }
    }
}


int matrixInsertionSort() {
    for (int row = 0; row < MATRIX_SIZE; row++) {
        for (int column = 1; column < MATRIX_SIZE; column++) {
            int temporaryElement = matrix[row][column];
            for (int temporaryColumnIndex = column - 1; temporaryColumnIndex >= 0; temporaryColumnIndex--) {
                if (matrix[row][temporaryColumnIndex] < temporaryElement) {
                    matrix[row][temporaryColumnIndex + 1] = matrix[row][temporaryColumnIndex];
                    if (temporaryColumnIndex == 0) {
                        matrix[row][temporaryColumnIndex] = temporaryElement;
                    }
                } else {
                    matrix[row][temporaryColumnIndex + 1] = temporaryElement;
                    break;
                }

            }
        }
    }
}

int printMatrixIntoConsole() {
    for (int row = 0; row < MATRIX_SIZE; row++) {
        printf("\n");
        for (int column = 0; column < MATRIX_SIZE; column++) {
            printf("    %i\t", matrix[row][column]);
        }
    }
}

// calculating elements sum of each column under the main diagonal
int sumUnderMainDiagonal() {
    int sumGeometric = 1, elementsQuantity = 0;
    for (int row = 0; row < MATRIX_SIZE; row++) {
        int sumOfElements = 1;
        for (int column = 0; column < MATRIX_SIZE; column++) {
            if (row < column) {
                for (int temporaryIndex = row + 1; temporaryIndex < MATRIX_SIZE; temporaryIndex++) {
                    sumOfElements = sumOfElements + matrix[temporaryIndex][row];
                }
                column = MATRIX_SIZE - 1;
                sumGeometric *= fabs(sumOfElements);
                elementsQuantity += 1;
                printf("\n sum f(a) = %d ", sumOfElements);
            }
        }
    }
    averageGeometricSum(sumGeometric, elementsQuantity);
}

// calculating average geometric sum
int averageGeometricSum(sumGeometric, elementsQuantity) {
    double averageGeometricSum = pow(sumGeometric, 1.0 / elementsQuantity);
    printf("\nresult %f", averageGeometricSum);
}

