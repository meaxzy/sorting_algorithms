#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - function that sways the positions of 2 integers
 * @first_int: pointer to the first integer
 * @second_int: pointer to the 2nd integer
 */
void swap(int *first_int, int *second_int)
{
	int temp = *first_int;
	*first_int = *second_int;
	*second_int = temp;
}

/**
 * bubble_sort - sorts an array of intergers in
 * ascending order using Bubble Sort
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
        int temp;
        int flag;
	
	if (array == NULL || size <= 1)
	{
		return;
	}
	
	for (i = 0; i < size - 1; i++)
	{
		flag = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap(&array[j], &array[j + 1]);
				print_array(array, size);

				/* Set the flag to indicate a swap was made */
				flag = 1;
			}
		}
		/* if no swaps were made, the array is already sorted */
		if (flag == 0)
		{
			break;
		}
	}
}
