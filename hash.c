
#include <stdio.h>
#include <stdlib.h>

typedef int hash_data;

struct hash_node_list {
	hash_data data;
	struct hash_node_list *next;
};

struct hash_table {
	int size;
	int (*hash_func)(hash_data);
	struct hash_node_list **list;
};

//struct hash_node_list *

struct hash_table *hash_init(int table_size, int(*hash_func)(hash_data)) 
{
	struct hash_table *table;

	table = (struct hash_table *)malloc(sizeof(struct hash_table));
	if (table) {
		printf("%s\n", "create error");
		exit(1);
	}
	table->size = table_size;
	table->hash_func = hash_func;

	table->list = (struct hash_node_list *)malloc(sizeof(struct hash_node_list) * table_size);
	if (table) {
		printf("%s\n", "create error");
		exit(1);
	}

	return table;
}

struct hash_node_list *hash_node_exist(struct hash_node_list *node, hash_data data)
{
	struct hash_node_list *temp = node;
	while (temp->next != NULL && temp->data != data)
		temp = temp->next;
	return temp;
}

struct hash_node_list *hash_find(struct hash_table *table, hash_data data)
{
	int index = table->hash_func(data);
	struct hash_node_list *node = hash_node_exist(table->list[index], data);

	if (node == NULL)
		return NULL;
	return node;
}

void hash_set(struct hash_table *table, hash_data data)
{
	struct hash_node_list *node = hash_find(table, data);

	if (node != NULL)
		return;

	node->next = (struct hash_node_list *)malloc(sizeof(struct hash_node_list));
	if (node->next == NULL) {
		printf("hash_set memory error\n");
		exit(1);
	}
	node->next->data = data;
	node->Next->next = NULL;
}

struct hash_data hash_get(struct hash_table *table, hash_data data)
{
	struct hash_node_list *node = hash_find(table, data);

	if (node != NULL)
		return node->data;
	
	return -1;
}


int main(int argc, char *argv[])
{


	return 0;
}
