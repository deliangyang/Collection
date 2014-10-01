
#include <stdio.h>
#include "sort.h"

#define SIZE 300

int main(int argc, char *argv[])
{
	int arr[300];
	int i;

	for (i = 0; i < 300; i++)
		arr[i] = rand() % 300;
	//quick_sort(arr, 0, SIZE-1);
	//insert_sort(arr, SIZE);
	//select_sort(arr, SIZE);
	//shell_sort(arr, SIZE);
	merge_sort(arr, SIZE);
	print_array(arr, SIZE);

	return 0;
}

