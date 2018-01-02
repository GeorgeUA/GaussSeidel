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

#endif