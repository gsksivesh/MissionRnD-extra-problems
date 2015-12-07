//Find median of a given linked list (Sorted Linked List) 
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct testcases
{
	int arr[20];
	int size;
	float ans;
}test[7] = { 
	{ { 1, 2, 3, 4, 5 }, 5, 3.0 },
	{ { 5, 4, 3, 2, 1 }, 5, 3.0 },
	{ { 1, 2, 3, 4 }, 4, 2.5 },
	{ { 4, 3, 2, 1 }, 4, 2.5 },
	{ NULL, 0, 0 },
	{ {1}, 1, 1 },
	{ {23,45}, 2, 34.0 }
};
struct node
{
	int data;
	struct node *next;
};
struct node * createNode(int n1) 
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = n1;
	newNode->next = NULL;
	return newNode;
}

void add(struct node **head, int p)
{
	struct node *temp = *head;
	if (*head == NULL)
	{
		(*head) = createNode(p);
		(*head)->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = createNode(p);
		temp->next->next = NULL;
	}
}
float median(struct node *head)
{
	struct node *temp1, *temp2;
	temp1 = head;
	temp2 = head;
	if (temp1 == NULL)
		return 0;
	if (temp1->next == NULL)
		return temp1->data;
	while (temp1->next->next != NULL)
	{
		temp2 = temp2->next;
		temp1 = temp1->next->next;
		if (temp1->next == NULL)
			return temp2->data;
	}
	return (temp2->data + temp2->next->data) / 2.0;
}
float medianByCount(struct node *head)
{
	struct node *temp;
	int count = 0, i=0;
	temp = head;
	if (temp == NULL)
		return 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	temp = head;
	if (count == 1)
		return temp->data;
	while (i < (count / 2) - 1)
	{
		temp = temp->next;
		i++;
	}
	if (count % 2)
		return temp->next->data;
	return (temp->data + temp->next->data) / 2.0;
}
int main()
{
	struct node *head = NULL;
	int i, j;
	for (j = 0; j < 7; j++)
	{
		for (i = 0; i < test[j].size; i++)
		{
			add(&head, test[j].arr[i]);
		}
		printf("Test case %d:-\n", j+1);
		if (head == NULL)
		{
			printf("Empty Linked List\n\n");
			continue;
		}
		if (test[j].ans == median(head))
		{
			printf("Method 1 passed\n");
		}
		else
		{
			printf("Method 1 Failed\n");
		}
		if (test[j].ans == medianByCount(head))
		{
			printf("Method 2 passed\n\n");
		}
		else
		{
			printf("Method 2 Failed\n\n");
		}
		free(head);
		head = NULL;
	}
	getchar();
}