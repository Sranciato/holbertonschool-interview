#include "sort.h"

/**
 * swap - swaps two given values
 * @array: array of integers
 * @i: value to swap
 * @j: value to swap
 * @size: size of array
 */

void swap(int array[], int i, int j, size_t size)
{
	int temp = array[i];

	if (array[i] == array[j])
		return;
	array[i] = array[j];
	array[j] = temp;

	print_array(array, size);
}

/**
 * heapify - heapify a subtree
 * @array: array of integers
 * @size: size after recursion
 * @i: value of child
 * @_size: size of array
 */

void heapify(int array[], int  size, int i,  size_t _size)
{
	int max = i;
	int l = 2 * i  + 1;
	int r = 2 * i + 2;

	if (l < size  && array[l] > array[max])
		max = l;
	if (r < size && array[r] > array[max])
		max = r;

	if (max != i)
	{
		swap(array, i, max, _size);
		heapify(array, size, max, _size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using Heap sort
 * @array: array of integers
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int i;
	size_t _size = size;

	if (!array || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, _size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(array, 0, i, _size);
		heapify(array, i, 0, _size);
	}
}
