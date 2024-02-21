#include "sort.h"

/**
 * selection_sort - algorithm of selection sorting
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t curr_idx, min_idx;

	if (!array || size < MIN_SIZE)
		return;

	for (curr_idx = 0; curr_idx < size - 1; curr_idx++)
	{
		min_idx = find_minimum_index(array, (int) curr_idx, size);

		if (min_idx != curr_idx)
		{
			swap(&array[curr_idx], &array[min_idx]);
			print_array(array, size);
		}
	}
}

/**
 * find_minimum_index - finding minimum function
 * @array: the array to be sorted
 * @start: the leftmost element in the unsorted list
 * @size: the size of the array
 * Return: the index of the minimum element
 */
size_t find_minimum_index(const int *array, int start, size_t size)
{
	size_t j, min_idx = start;

	for (j = start + 1; j < size; j++)
		if (array[min_idx] > array[j])
			min_idx = j;

	return (min_idx);
}

/**
 * swap - exchanging 2 elements
 * @first_element: first element
 * @second_element: second element
 */
void swap(int *first_element, int *second_element)
{
	int temp = *first_element;
	*first_element = *second_element;
	*second_element = temp;
}
