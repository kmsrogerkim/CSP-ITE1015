#include <iostream>
#include "shapes.h"
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    if ((n < 3) || (n % 2 == 0)) return 0;

    // initialize matrix with 0s
    int** matrix = new int*[n];
    for (int i=0; i<n; i++)
    {
        matrix[i] = new int[n];
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // call & print
    // also delete
    magic_square(n, matrix);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        delete matrix[i];
        cout << endl;
    }
    delete matrix;
    
    return 0;
}
