#include "sort.h"

/**
 * merge - Merges two subarrays of array[].
 * First subarray is array[l..m].
 * Second subarray is array[m+1..r].
 * @array: Array to be sorted
 * @l: Left index of the subarray
 * @m: Middle index of the subarray
 * @r: Right index of the subarray
 */

void merge(int *array, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int *L = malloc(n1 * sizeof(int));
	int *R = malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1 + j];

	i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			array[k++] = L[i++];
		else
			array[k++] = R[j++];
	}
	while (i < n1)
		array[k++] = L[i++];
	while (j < n2)
		array[k++] = R[j++];

	free(L);
	free(R);
}

/**
 * merge_sort - Sorts an array of integers using Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */

void merge_sort(int *array, size_t size)
{
	int mid;

	if (size <= 1)
		return;
	mid = size / 2;
	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, 0, mid - 1, size - 1);
}
