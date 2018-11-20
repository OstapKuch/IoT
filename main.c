//Vasya
#include <stdio.h>
#include <math.h>

int Matrix[5][5];
int ScanningMatrix(), InsertionSort(), SumUnderMainDiagonal(), PrintMatrix(), AverageGeometricSum();


int main() { //scaning array
    ScanningMatrix();
    InsertionSort();
    PrintMatrix();
    SumUnderMainDiagonal();
}

int ScanningMatrix() { 
    
    for (row = 0; row <= 4; row++) {
        for (int column = 0; column <= 4; column++) {
            scanf("%i", &Matrix[row][column]);
        }
    }
}
int InsertionSort() { 
    for (int row = 0; row <= 4; row++) {
        
        for (int column = 1; column <= 4; column++) {
            
            int teporaryElement = Matrix[row][column];            
            for(int temporaryColumnIndex = column - 1; column >= 0; column--) {
              
                if(Matrix[row][temporaryColumnIndex] < teporaryElement){
                    
                    Matrix[row][temporaryColumnIndex+1] = Matrix[row][temporaryColumnIndex];      
                    if(temporaryColumnIndex == 0) {
                        
                        Matrix[row][temporaryColumnIndex] = teporaryElement;
                    }
                }
                else {
                    
                    Matrix[row][temporaryColumnIndex+1] = teporaryElement;
                    break;
                }

            }
        }
    }
}

int PrintMatrix(){ 
    for(int row=0; row<=4; row++) {
        printf("\n");
        for(int column=0; i<=4; column++) {
            printf("    %i\t", Matrix[row][column]);
      }
    }
}

// calculating element sum of each column under main diagonal
int SumUnderMainDiagonal() { 
    int SumGeometric=1, ElementsQuantity=0;
    for(int row=0; row<=4; row++) {
        int SumOfElements = 1;
        for(int column=0; column<=4; column++) {
            if(row<column) {
                for(int temporaryIndex = row+1; temporaryIndex<=4; temporaryIndex++){
                    SumOfElements = SumOfElements + Matrix[temporaryIndex][row];
                }
                column = 4;
                SumGeometric *= fabs(SumOfElements);
                ElementsQuantity += 1;
                printf("\n sum f(a) = %d ", SumOfElements);
            }
        }
    }
    AverageGeometricSum(SumGeometric, SumOfElements);
}
// calculating avarage geometric sum
int AverageGeometricSum(SumGeometric, SumOfElements) { 
    double result = pow(SumGeometric, 1.0/SumOfElements);
    printf("\nresult %f", result);
}

