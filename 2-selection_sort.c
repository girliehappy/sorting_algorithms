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
* selection_sort - A function that sorts an array of integers
* in ascending order using the selection sort algorithm.
* @array: This is an array of integers.
* @size: This is the size of the array.
*
* Description: Prints the array after each element is been swapped.
*/
void selection_sort(int *array, size_t size)
{
int *min;
size_t h, p;

if (array == NULL || size < 2)
return;

for (h = 0; h < size - 1; h++)
{
min = array + h;
for (p = h + 1; p < size; p++)
min = (array[p] < *min) ? (array + p) : min;

if ((array + h) != min)
{
swap_ints(array + h, min);
print_array(array, size);
}
}
}
