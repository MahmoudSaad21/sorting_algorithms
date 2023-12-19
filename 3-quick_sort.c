#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
int pivot, temp;
size_t i, j;
pivot = array[high];
i = low;
for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
i++;
}
}
if (i != high)
{
temp = array[i];
array[i] = array[high];
array[high] = temp;
print_array(array, size);
}
return i;
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
size_t pivot;
if (low < high)
{
pivot = lomuto_partition(array, low, high, size);
if (pivot != 0 && pivot != low)
quick_sort_recursive(array, low, pivot - 1, size);
quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
quick_sort_recursive(array, 0, size - 1, size);
}

