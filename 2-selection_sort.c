#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Integers array to sort
 * @size: Array's size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smaller, smaller_index, aux;

	if (!array || size <= 0)
		return;
	for (i = 0; i <= (size - 1); i++)
	{
		smaller = array[i];
		for (j = i + 1; j <= (size - 1); j++)
		{
			if (array[j] < smaller)
			{
				smaller = array[j];
				smaller_index = j;
			}
		}
		aux = array[i];
		array[i] = smaller;
		array[smaller_index] = aux;
		print_array(array, size);
	}
}
