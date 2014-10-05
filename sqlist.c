
#include <stdio.h>
#include <stdlib.h>

struct sqlist_t {
	int *data;
	int length;
	int sqlist_size;
};

struct sqlist_t *sqlist_init(int size) 
{
	struct sqlist_t *l;

	l = (struct sqlist_t *)malloc(sizeof(struct sqlist_t));
	l->data = (int *)malloc(sizeof(int) * size);
	l->sqlist_size = size;
	l->length = 0;

	return l;
}

void sqlist_add(struct sqlist_t *l, int data)
{
	if (l->length > l->sqlist_size) {
		printf("out of sqlist's size\n");
		return;
	}
	l->data[l->length] = data;
	l->length++;
}

int sqlist_get(struct sqlist_t *l, int index)
{
	if (index >= l->length || index < 0) {
		printf("out of range\n");
		return -1;
	}
	return l->data[index];
}

void sqlist_free(struct sqlist_t *l)
{
	free(l->data);
	free(l);
	//l->length = 0;
}

int *do_init(void)
{
	int *a;
	a = (int *)malloc(sizeof(int));
	*a = 20;

	return a;
}

void do_free(int *a)
{
	free(a);
	printf("a: %d\n", *a);
}

int main(int argc, char *argv[])
{
	struct sqlist_t *l;
	int i;

	l = sqlist_init(20);

	for (i = 0; i < 20; i++)
		sqlist_add(l, i);

	for (i = 0; i < 20; i++)
		printf("%d ", sqlist_get(l, i));

	sqlist_free(l);

	for (i = 0; i < 20; i++)
		printf("%d ", sqlist_get(l, i));

	printf("\n-----------------------------\n");

	for (i = 0; i < 20; i++)
		printf("%d ", l->data[i]);
	
	printf("\n-----------look at l is or not free--------------\n");
	printf("l length: %d\n", l->length);


	// just test it is free or not
	/*int *a;
	a = do_init();
	printf("%d\n", *a);
	do_free(a);
	printf("%d\n", *a);*/

	return 0;
}

/*
	output

	0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 2964136 2959920 1735357008 544
	039282 1701603654 1632263283 1247568246 1817986637 3891817 1835888451 1917873775
	 1634887535 1818838637 1128100709 1917869114 1634887535 1766203501 1551066476 18
	35888451 1176530543
	-----------------------------
	2964136 2959920 1735357008 544039282 1701603654 1632263283 1247568246 1817986637
	 3891817 1835888451 1917873775 1634887535 1818838637 1128100709 1917869114 16348
	87535 1766203501 1551066476 1835888451 1176530543
	-----------look at l is or not free--------------
	l length: 2959824



 */
