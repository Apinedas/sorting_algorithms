#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Integers array to sort
 * @size: Array's size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, smaller_index;
	int smaller, aux, change;

	if (!array || size < 2)
		return;
	for (i = 0; i <= (size - 1); i++)
	{
		smaller = array[i];
		change = 0;
		for (j = i + 1; j <= (size - 1); j++)
		{
			if (array[j] < smaller)
			{
				smaller = array[j];
				smaller_index = j;
				change += 1;
			}
		}
		if (i != smaller_index && change > 0)
		{
			aux = array[i];
			array[i] = smaller;
			array[smaller_index] = aux;
			print_array(array, size);
		}
	}
}
