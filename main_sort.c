
#include <stdio.h>
#include "sort.h"

void bubble_sort(int *arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

void quick_sort(int *arr, int start, int end)
{
	int i, j, pivot;
	if (start < end) {
		i = start;
		j = end;
		pivot = arr[i];

		while (i < j) {
			while (i < j && arr[j] > pivot) j--;
			if (i < j) arr[i++] = arr[j];
			while (i < j && arr[i] < pivot) i++;
			if (i < j) arr[j--] = arr[i];
		}
		arr[i] = pivot;
		quick_sort(arr, start, i - 1);
		quick_sort(arr, i + 1, end);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_array(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

