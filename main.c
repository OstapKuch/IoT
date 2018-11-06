//Vasya
#include <stdio.h>
#include <math.h>
//int mas[5][5] = {{3,   5,   9,   24, 2},
//            {-23, 0,   37,  29, 10},
//            {0,   1,   4,   -2, -5},
//            {-5,  -83, -74, 82, -1},
//            {11,  88,  -5,  81, -39}};
int x, i, scan, elem, z = 1, mas[5][5];
int sort(), f(), print(), F();


int main() { //scaning array
    for (x = 0; x <= 4; x++) {
        for (int i = 0; i <= 4; i++) {
            scanf("%i", &mas[x][i]);
        }
    }
    sort();
}

int sort() { //sorting array
    for (x = 0; x <= 4; x++) {
        for (int i = 1; i <= 4; i++) {
            int g = mas[x][i];
            for(int y = i-1; y >= 0; y--) {
                if(mas[x][y] < g){
                    mas[x][y+1] = mas[x][y];
                    if(y == 0) {
                        mas[x][y] = g;
                    }
                }

                else {
                    mas[x][y+1] = g;
                    break;
                }

            }
        }
    }
    print();
    f();

}
int print(){ //printing array
    for(x=0; x<=4; x++) {
        printf("\n");
        for(i=0; i<=4; i++) {
            printf("    %i\t", mas[x][i]);
      }
    }
}
int f() { // calculating element sum of each column under main diagonal
    int sumgeom=1, sumel=0;
    for(x=0; x<=4; x++) {
        int sum = 1;
        for(i=0; i<=4; i++) {
            if(x<i) {
                for(int t = x+1; t<=4; t++){
                    sum = sum + mas[t][x];
                }
                i = 4;
                sumgeom *= fabs(sum);
                sumel+=1;
                printf("\n sum f(a) = %d ", sum);
            }
        }
    }
    F(sumgeom, sumel);
}

int F(x1, y1) { // calculating avarage geometric sum
    double result = pow(x1, 1.0/y1);
    printf("\nresult %f", result);
}

