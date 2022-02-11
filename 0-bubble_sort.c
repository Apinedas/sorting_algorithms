#include "sort.h"

/**
 * bubble_sort - orts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: Array of intigers to sort
 * @size: Array's size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int aux, wrong = 1;

	while (wrong != 0)
	{
		wrong = 0;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
				wrong++;
			}
		}
	}
}
