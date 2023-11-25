#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - A function that orders a subset of an array of integers
 * according to the lomuto partition scheme (last element as pivot).
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 * @left: This is the starting index of the subset to order.
 * @right: This is the ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
        int *pivot, above, below;

        pivot = array + right;
        for (above = below = left; below < right; below++)
        {
                if (array[below] < *pivot)
                {
                        if (above < below)
                        {
                                swap_ints(array + below, array + above);
                                print_array(array, size);
                        }
                        above++;
                }
        }

        if (array[above] > *pivot)
        {
                swap_ints(array + above, pivot);
                print_array(array, size);
        }

        return (above);
}

/**
 * lomuto_sort - A function that implements the quicksort algorithm
 * through recursion.
 * @array: This is an array of integers to sort.
 * @size: This is the size of the array.
 * @left: This is the starting index of the array partition to order.
 * @right: This is the ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
        int prt;

        if (right - left > 0)
        {
                prt = lomuto_partition(array, size, left, right);
                lomuto_sort(array, size, left, prt - 1);
                lomuto_sort(array, size, prt + 1, right);
        }
}

/**
 * quick_sort - A function that sorts an array of integers in ascending order
 * using the quicksort algorithm.
 * @array: This is an array of integers.
 * @size: This is the size of the array.
 *
 * Description: Uses the Lomuto partition scheme.
 * Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        lomuto_sort(array, size, 0, size - 1);
}
