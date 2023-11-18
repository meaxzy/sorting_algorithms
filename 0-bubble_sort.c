
#include "sort.h"

/**
 * bubble_sort - sorts an array of intergers in
 * ascending order using Bubble Sort
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
        int temp;
        int flagged;
	
	if (array == NULL || size <= 1)
	{
		return;
	}
	
	for (i = 0; i < size - 1; i++)
	{
		flagged = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);

				/* Set the flag to indicate a swap was made */
				flagged = 1;
			}
		}
		/* if no swaps were made, the array is already sorted */
		if (flagged == 0)
		{
			break;
		}
	}
}
