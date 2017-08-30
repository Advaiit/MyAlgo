#include <iostream>
#include <stdlib.h>

using namespace std;

int*addMatrix(int **a, int** b, int** result, int r, int c, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            result[r][c] = a[i][j] + b[i][j];
            c++;
        }
        r++;
    }
}

int** multiply_matrix(int** matrix1, int** matrix2, int r1, int c1, int r2, int c2, int n)
{
    int **result;
    if(n == 1)
    {
        result = (int**)malloc(sizeof(int*));
        *result = (int*)malloc(sizeof(int));
        result[0][0] = matrix1[r1][c1] * matrix2[r2][c2];
        return result;
    }

    //Create a n x n matrix
    result = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));   
    }

    int **c11_1 = multiply_matrix(matrix1, matrix2, r1, c1, r2, c2, n/2);
    int **c11_2 = multiply_matrix(matrix1, matrix2, r1, c1 + n/2, r2, c2 + n/2, n/2);
    addMatrix(c11_1, c11_2, result, 0, 0, n/2);

    int **c12_1 = multiply_matrix(matrix1, matrix2, r1, c1, r2, c2 + n/2, n/2);
    int **c12_2 = multiply_matrix(matrix1, matrix2, r1, c1 + n/2, r2 + n/2, c2 + n/2, n/2);
    addMatrix(c12_1, c12_2, result, 0, n/2, n/2);

    int **c21_1 = multiply_matrix(matrix1, matrix2, r1 + n/2, c1, r2, c2, n/2);
    int **c21_2 = multiply_matrix(matrix1, matrix2, r1 + n/2, c1 + n/2, r2 + n/2, c2, n/2);
    addMatrix(c21_1, c21_2, result, n/2, 0, n/2);

    int **c22_1 = multiply_matrix(matrix1, matrix2, r1 + n/2, c1, r2, c2, n/2);
    int **c22_2 = multiply_matrix(matrix1, matrix2, r1 + n/2, c1 + n/2, r2 + n/2, c2, n/2);  
    addMatrix(c22_1, c22_2, result, n/2, n/2, n/2);  

    free(c11_1);
    free(c11_2);
    free(c12_1);
    free(c12_2);
    free(c21_1);
    free(c21_2);
    free(c22_1);
    free(c22_2);

    return result;
}

int main()
{
    int **matrix1, **matrix2;
    int **resultMatrix;
    int n = 2;

    matrix1 = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        matrix1[i] = (int *)malloc(n * sizeof(int));   
    }

    matrix2 = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        matrix2[i] = (int *)malloc(n * sizeof(int));   
    }

    // resultMatrix = (int **)malloc(n * sizeof(int*));
    // for(int i = 0; i < n; i++)
    // {
    //     *resultMatrix = (int *)malloc(n * sizeof(int));   
    // }

    cout<<"First Matrix: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>matrix1[i][j];
        }
    }

    
    cout<<"Second Matrix: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>matrix2[i][j];
        }
    }

    resultMatrix = multiply_matrix(matrix1, matrix2, 0, 0, 0, 0, n);

    cout<<"Resulting Matrix: \n";

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout<<resultMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    free(matrix1);
    free(matrix2);
    free(resultMatrix);

    return 0;
}