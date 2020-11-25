#include "sort.h"

/**
 * recursive_radix - recursively sorts array
 * @array: array of integers
 * @size: size of array
 * @level: level of recursion
 */
void recursive_radix(int *array, size_t size, int level)
{
	int *new, i, x, index = 0, w = 0, num = 0;

	(void)w;
	new = malloc(size * sizeof(int));
	for (x = 0; x < 10; x++)
	{
		for (i = 0; i < (int)size; i++)
		{
			if (array[i] / level > 0)
				num = 1;
			if ((array[i] / level) % 10 == x)
			{
				new[index] = array[i];
				index++;
			}
		}
	}
	for (i = 0; i < (int)size; i++)
		if (array[i] != new[i])
			array[i] = new[i], w = 1;
	free(new);
	if (num != 0)
	{
		print_array(array, size);
		recursive_radix(array, size, level * 10);
	}
}

/**
 * radix_sort - sorts an integer array using the Radix sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	recursive_radix(array, size, 1);
}
