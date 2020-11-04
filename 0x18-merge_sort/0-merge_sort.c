#include "sort.h"

/**
 * merge - merges array
 * @array: pointer to array
 * @size: size of array
 * @left: pointer to left array
 * @right: pointer to right array
 **/
void merge(int *array, int *left, int *right, size_t size)
{
	int i, j, k, leftsize, rightsize;

	leftsize = size / 2;
	rightsize = size - leftsize;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, leftsize);
	printf("[right]: ");
	print_array(right, rightsize);

	i = j = k = 0;

	while (i < leftsize && j < rightsize)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < leftsize)
		array[k++] = left[i++];

	while (j < rightsize)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int pack[2048];
	int *left;
	size_t middle;
	int *right;

	if (!array || size < 2)
		return;

	middle = size / 2;
	left = pack;
	right = &pack[middle];

	for (i = 0; i < middle; i++)
		left[i] = array[i];

	for (i = middle; i < size; i++)
		right[i - middle] = array[i];

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(array, left, right, size);
}
