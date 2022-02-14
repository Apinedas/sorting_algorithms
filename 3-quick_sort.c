#include "sort.h"
/**
 * swap - swaps two positions in Array
 *
 * @first: first position
 * @second: Second position
 * @size: size of array
 * @array: input array
 */
void swap(int *first, int *second, size_t size, int *array)
{
	int temp = *first;
	*first = *second;
	*second = temp;
	print_array(array, size);
}
/**
 * partition - partition array while sorts it
 * @array: Input array
 * @low: lowest position posible in array
 * @high: high position posible in array
 * @size: size of array
 * Return: int
 */
int partition(int *array, int low, int high, size_t size)
{
	int j;
	int pivot = array[high];
	int i = (low - 1);

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
				swap(&array[i], &array[j], size, array);
		}
	}
	if ((i + 1) != high)
		swap(&array[i + 1], &array[high], size, array);

	return (i + 1);
}
/**
 * sorting - sorts an array
 *
 * @array: Input array
 * @low: lowest position posible in array
 * @high: high position posible in array
 * @size: size of array
 */
void sorting(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high, size);

		sorting(array, low, partition_index - 1, size);
		sorting(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Integers array to sort
 * @size: Array's size
 */

void quick_sort(int *array, size_t size)
{
	int low = 0, high = size - 1;

	if (array && size >= 2)
		sorting(array, low, high, size);
}
