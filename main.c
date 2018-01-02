#include <stdio.h>
#include <stdlib.h>
#include "lib/sleio.h"

int main()
{
    char PATH[] = "data/SLE_N3.txt";
    double EPS, **A, *B, *X;
    int N;

    if (isExistsFile(PATH))
    {
        readOrderMatrixAndAccuracyFromFile(PATH, &N, &EPS);
        printf("N = %d, EPS = %lg\n", N, EPS);

        A = (double **)malloc(N * sizeof(double *));
        B = (double *)malloc(N * sizeof(double));
        X = (double *)malloc(N * sizeof(double));

        for (int i = 0; i < N; ++i)
        {
            A[i] = (double *)malloc(N * sizeof(double));
            for (int j = 0; j < N; ++j)
            {
                A[i][j] = 0;
            }
            B[i] = 0;
            X[i] = 0;
        }

        readSleFromFile(PATH, N, A, B);

        for (int i = 0; i < N; ++i)
        {
            free(A[i]);
        }

        free(A);
        free(B);
        free(X);
    }
    else
    {
        printf("Помилка! Даний файл не існує.\n");
    }

    return 0;
}