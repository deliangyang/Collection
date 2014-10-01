
#ifndef __SORT_H__
#define __SORT_H__

void swap(int *a, int *b);
void bubble_sort(int *arr, int n);
void quick_sort(int *arr, int start, int end);
void shell_sort(int *arr, int n);
void insert_sort(int *arr, int n);
void select_sort(int *arr, int n);
void merge_array(int *arr, int start, int mid, int end, int *temp);
void merge_sort_do(int *arr, int start, int end, int *temp);
void merge_sort(int *arr, int n);
void print_array(int *arr, int n);



#endif

