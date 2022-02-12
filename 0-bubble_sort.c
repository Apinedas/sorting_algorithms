#include "sort.h"

/**
 * bubble_sort - orts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: Array of intigers to sort
 * @size: Array's size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int aux;

	if (array && size > 0)
	{
		for (i = 0; i < (size - 1); i++)
		{
			for (j = 0; j < (size - i - 1); j++)
			{
				if (array[j] > array[j + 1])
				{
					aux = array[j];
					array[j] = array[j + 1];
					array[j + 1] = aux;
					print_array(array, size);
				}
			}
		}
	}
}
