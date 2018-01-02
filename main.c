#include <stdio.h>
#include <stdlib.h>
#include "lib/sleio.h"

int main()
{
    char PATH[] = "data/SLE_N5.txt";

    if (isExistsFile(PATH))
    {
        printf("Даний файл існує.\n");
    }
    else
    {
        printf("Помилка! Даний файл не існує.\n");
    }

    return 0;
}