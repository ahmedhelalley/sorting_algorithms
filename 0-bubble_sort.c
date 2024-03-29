#include "sort.h"

/**
 * bubble_sort - algorithm of bubble sorting
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool is_swapped = false;

	if (!array || size < MIN_SIZE)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				is_swapped = true;
				print_array(array, size);
			}
		}
		if (!is_swapped)
			break;
	}
}

/**
 * swap - exchange two elements function
 * @first_element: first element
 * @second_element: second element
 */
void swap(int *first_element, int *second_element)
{
	int temp = *first_element;
	*first_element = *second_element;
	*second_element = temp;
}
