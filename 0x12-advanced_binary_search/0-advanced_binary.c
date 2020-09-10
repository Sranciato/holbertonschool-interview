#include "search_algos.h"

/**
 * print_array - prints array
 * @array: pointer to the first element of the array to search in
 * @size: size of array
 */
void print_array(int *array, size_t size)
{
	int first = 1;
	size_t i = 0;

	printf("Searching in array: ");

	for (i = 0; i < size; i++)
	{
		if (first == 0)
			printf(", ");
		printf("%d", array[i]);
		first = 0;
	}
	printf("\n");
}
/**
 * advanced_binary -  searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: size of the array
 * @value: value to search for
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	int middle = (size - 1) / 2, temp = 0;

	if (size == 0 || array == NULL)
		return (-1);
	print_array(array, size);
	if (size == 1 && array[0] != value)
		return (-1);

	if (array[middle] == value)
	{
		if (array[middle - 1] == value)
			return (advanced_binary(array, size / 2, value));
		else
			return (middle);
	}

	if (array[middle] > value)
	{
		return (advanced_binary(array, middle, value));
	}
	else
	{
		temp = advanced_binary(array + size / 2 + size % 2, size / 2, value);
		if (temp == -1)
			return (-1);
		else
			return (temp + size / 2 + size % 2);
	}

	return (-1);
}
