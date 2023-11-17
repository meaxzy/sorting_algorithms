#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - sorts an array of intergers in
 * ascending order using Bubble Sort
 * @array: The array to be sorted
 * @size: Size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int temp;
	int flag;

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
				/* Print array after each swap */
				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k != size - 1)
					{
						printf(", ");
					}
				}
				printf("\n");

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
