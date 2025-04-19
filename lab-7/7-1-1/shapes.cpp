#include <iostream>
#include "shapes.h"

using namespace std;

void magic_square(int n, int** matrix)
{
    int num = 1; 
    int i = 0, j = n / 2; 

    while (num <= n * n) {
        matrix[i][j] = num; 
        num++; 

        int newi = (i - 1 + n) % n; 
        int newj = (j + 1) % n; 

        if (matrix[newi][newj] != 0) { 
            i = (i + 1) % n; 
        } else {
            i = newi; 
            j = newj; 
        }
    }
}