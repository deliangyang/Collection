
#include <stdio.h>
#include <stdlib.h>

typedef int TYPE;

struct queue_node {
	TYPE data;
	struct queue_node *next;
};

struct queue_s {
	struct queue_node *front;
	struct queue_node *rear;
};

struct queue_s *queue_init(void)
{
	struct queue_s *head;
	head = (struct queue_s *)malloc(sizeof(struct queue_s));
	if (head == NULL)
		exit(1);

	//head->front = head->rear;
	head->rear = (struct queue_node *)malloc(sizeof(struct queue_node));
	if (head->rear == NULL)
		exit(1);

	head->rear->next = NULL;
	head->front = head->rear;
	return head;
}

int queue_empty(struct queue_s *head)
{
	return head->front->next == NULL;
}

void queue_insert(struct queue_s *head, TYPE data)
{
	head->rear->next = (struct queue_node *)malloc(sizeof(struct queue_node));

	if (head->rear->next == NULL)
		exit(1);
	head->rear->data = data;
	head->rear = head->rear->next;
	head->rear->next = NULL;
	/*struct queue_node *node;
	node = (struct queue_node *)malloc(sizeof(struct queue_node));
	if (node == NULL) 
		return;
	node->data = data;
	node->next = NULL;
	
	head->rear->next = node;
	head->rear = node;*/
	//printf("front->data: %d\n", head->rear->data);
}

int queue_del(struct queue_s *head)
{
	struct queue_node *temp;
	TYPE data;
	if (!queue_empty(head)) {
		temp = head->front;
		data = temp->data;
		head->front = temp->next;
		free(temp);
		return data;
	}

	return -1;
}

void queue_free(struct queue_s *head)
{
	while (!queue_empty(head))
		queue_del(head);
	
	if (head != NULL)
		free(head);
}

int main(int argc, char *argv[])
{
	struct queue_s *head;
	head = queue_init();

	queue_insert(head, 200);
	queue_insert(head, 300);
	queue_insert(head, 4000);

	//printf("%d\n", queue_empty(head));

	while (!queue_empty(head))
		printf("-%d\n", queue_del(head));

	queue_insert(head, 300);
	queue_insert(head, 4000);
	while (!queue_empty(head))
		printf("-%d\n", queue_del(head));

	queue_free(head);



	system("pause");
	return 0;
}
