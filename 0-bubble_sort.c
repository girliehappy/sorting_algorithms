#include "sort.h"

/**
 * swap_ints - A function that swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - A function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * Description: Print the array after each time you swap two elements.
 */
void bubble_sort(int *array, size_t size)
{
	size_t h, len = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (h = 0; h < len - 1; h++)
		{
			if (array[h] > array[h + 1])
			{
				swap_ints(array + h, array + h + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		len--;
	}
}
