#include "sort.h"

/**
* swap_ints - A function that swaps two integers in an array.
* @a: The first integer to be swapped.
* @b: The second integer to be swapped.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* shell_sort - A function that sorts an array of integers
* in ascending order using the shell sort algorithm.
* @array: This is an array of integers.
* @size: This is the size of the array.
*
* Description: Uses the Knuth interval sequence.
*/
void shell_sort(int *array, size_t size)
{
size_t gap, h, p;

if (array == NULL || size < 2)
return;

for (gap = 1; gap < (size / 3);)
gap = gap * 3 + 1;

for (; gap >= 1; gap /= 3)
{
for (h = gap; h < size; h++)
{
p = h;
while (p >= gap && array[p - gap] > array[p])
{
swap_ints(array + p, array + (p - gap));
p -= gap;
}
}
print_array(array, size);
}
}
