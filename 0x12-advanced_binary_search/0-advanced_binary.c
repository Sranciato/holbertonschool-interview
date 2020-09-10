#include "search_algos.h"

/**
 * print_array - prints array
 * @array: pointer to the first element of the array to search in
 * @size: size of array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t middle;
	int ret;

	if (array == NULL)
		return (-1);

	print_array(array, size);

	if (size % 2)
		middle = size / 2;
	else
		middle = size / 2 - 1;
	while (array[middle] == value)
	{
		if (middle > 0 && array[middle - 1] == value)
			return (advanced_binary(array, middle + 1, value));
		else
			return (middle);
	}
	if (size == 1)
		return (-1);
	if (array[middle] > value)
	{
		while (middle < size - 1 && array[middle + 1] == array[middle])
			middle++;
		return (advanced_binary(array, middle, value));
	}
	else
	{
		middle++;
		while (middle > 0 && array[middle - 1] == array[middle])
			middle--;
		ret = advanced_binary(array + middle, size - middle, value);
		if (ret != -1)
			return (middle + ret);
	}
	return (-1);
}
