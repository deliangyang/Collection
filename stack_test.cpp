
#include <iostream>

struct stack_node
{
	int data;
	struct stack_node *next;
};

struct stack_node * stack_init(void)
{
	struct stack_node * node;

	node = (struct stack_node *)malloc(sizeof(struct stack_node));

	if (node == NULL)
		return NULL;
	node->next = NULL;
	return node; 
}

void stack_push(struct stack_node *head, int data)
{
	struct stack_node * node;

	node = (stack_node *)malloc(sizeof(struct stack_node));

	if (node == NULL) 
		return;

	node->data = data;
	node->next = head->next;
	head->next = node;
}

int stack_empty(struct stack_node *head)
{
	return head->next == NULL;
}

void stack_pop(stack_node *head)
{
	struct stack_node *node;
	if (!stack_empty(head)) {
		node = head->next;
		head->next = node->next;
		free(node);
	}
}

int stack_peek(struct stack_node *head)
{
	if (!stack_empty(head)) {
		return head->next->data;
	}
	return -1;
}

void stack_free(struct stack_node *head)
{
	while (!stack_empty(head))
		stack_pop(head);
}

int main(int argc, char *argv[])
{
	struct stack_node *head;
	head = stack_init();

	stack_push(head, 20);
	stack_push(head, 30);
	stack_push(head, 40);

	while (!stack_empty(head)) {
		printf("%d\n", stack_peek(head));
		stack_pop(head);
	}
	//printf("%d\n", stack_peek(head));
	stack_free(head);

	return 0;
}
