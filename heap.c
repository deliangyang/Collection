
#include <stdio.h>

int size = 0;

void heap_add(int *arr, int data)
{
	int i;

	for (i = ++size; arr[i / 2] > data; i /= 2)
		arr[i] = arr[i / 2];
	arr[i] = data;
}

int heap_del(int *arr)
{
	int i, child;
	int min, last;
	min = arr[1];
	last = arr[size--];

	for (i = 1; i*2 <= size; i = child) {
		child = i * 2;
		if (child != size && arr[child + 1] < arr[child])
			child++;

		if (last > arr[child])
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = last;
	return min;
}

int main(int argc, char *argv[])
{
	int arr[5];
	int i;

	heap_add(arr, 10);
	heap_add(arr, 5);
	heap_add(arr, 300);
	heap_add(arr, 3000);
	heap_add(arr, 0);

	for (i = 0; i < 5; i++)
		printf("%d ", heap_del(arr));

	return 0;
}
