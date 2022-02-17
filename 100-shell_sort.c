#include "sort.h"

/**
 * shell_sort - sorts an array using the shell algorithm
 * @array: Array to sort
 * @size: Array's size
 */

void shell_sort(int *array, size_t size)
{
    size_t nextgap = 1, i;
    int gap = 0, j, aux;

    while (nextgap < size)
    {
        gap = nextgap;
        nextgap = (3 * gap) + 1;
    }
    while (gap > 0)
    {
        i = 0;
        while (i < (size - 1))
        {
            if (i + gap <= (size - 1) && array[i] > array[i + gap])
            {
                aux = array[i];
                array[i] = array[i + gap];
                array[i + gap] = aux;
                for (j = i; (j - gap) >= 0; j -= gap)
                {
                    if (array[j] < array[j - gap])
                    {
                        aux = array[j];
                        array[j] = array[j - gap];
                        array[j - gap] = aux;
                    }
                }
            }
            else if (i != (size - 1) && array[i] < array[size - 1])
            {
                aux = array[i];
                array[i] = array[size - 1];
                array[size - 1] = aux;
                for (j = i; (j - gap) >= 0; j -= gap)
                {
                    if (array[j] < array[j - gap])
                    {
                        aux = array[j];
                        array[j] = array[j - gap];
                        array[j - gap] = aux;
                    }
                }
            }
            i++;
        }
        gap = (gap - 1) / 3;
        print_array(array, size);
    }
}
