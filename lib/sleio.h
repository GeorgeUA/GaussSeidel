#ifndef SLEIO_H
#define SLEIO_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Функція провірки на існування файлу
 * @param path - путь до файлу
 * @return повертає 1 якщо існує файл, 0 якщо не існує
 */
short isExistsFile(char *path)
{
    short isExist = 1;
    FILE *fptr = fopen(path, "r");

    if (fptr == NULL)
    {
        isExist = 0;
    }

    fclose(fptr);

    return isExist;
}

void readOrderMatrixAndAccuracyFromFile(char *path, int *n, double *eps)
{
    FILE *fptr = fopen(path, "r");
    fscanf(fptr, "%d", n);
    fscanf(fptr, "%lf", eps);
    fclose(fptr);
}

void readSleFromFile(char *path, int N, double **A, double *B)
{
    FILE *fptr = fopen(path, "r");
    double tmp;
    fscanf(fptr, "%lf", &tmp);
    fscanf(fptr, "%lf", &tmp);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fscanf(fptr, "%lf", &A[i][j]);
        }
        fscanf(fptr, "%lf", &B[i]);
    }

    fclose(fptr);
}

#endif