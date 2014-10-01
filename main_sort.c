
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

void select_sort(int *arr, int n)
{
	int i, j, temp, min;
	for (i = 0; i < n-1; i++) {
		min = i;
		for (j = i+1; j < n; j++)
			if (arr[min] > arr[j])
				min = j;
		if (i != min) {
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

void shell_sort(int *arr, int n)
{
	int i, step;
	for (step = n/2; step > 0; step /= 2)
		for (i = step; i < n; i += step) {
			int key = arr[i];
			int j = 0;
			for (j = i-step; j >= 0 && arr[j] > key; j -= step)
				arr[j+step] = arr[j];
			arr[j+step] = key;
		}
}

void insert_sort(int *arr, int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		j = i;
		while (j > 0 && temp < arr[j-1]) {
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = temp;
	}
}

void merge_array(int *arr, int start, int mid, int end, int *temp)
{
	int i, j, k;

	i = start;
	j = mid + 1;
	k = 0;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	for (i = 0; i < k; i++) 
		arr[start+i] = temp[i];

}

void merge_sort_do(int *arr, int start, int end, int *temp)
{
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort_do(arr, start, mid, temp);					// left
		merge_sort_do(arr, mid + 1, end, temp);					// right
		merge_array(arr, start, mid, end, temp);				// merge
	}
}

void merge_sort(int *arr, int n)
{
	int *temp;
	temp = (int *)malloc(sizeof(int) * n);

	if (temp == NULL)
		exit(1);

	merge_sort_do(arr, 0, n, temp);

	free(temp);
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

