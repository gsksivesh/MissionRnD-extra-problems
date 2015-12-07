//Reverse an Linked list , using recursion
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct testcases
{
	int arr[20];
	int size;
	int ans[20];
}test[7] = {
	{ { 1, 2, 3, 4, 5 }, 5, { 5, 4, 3, 2, 1 } },
	{ { 1 }, 1, {1} },
	{ { NULL }, 0, {NULL} }
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
struct node * reverse(struct node *head, struct node *rhead)
{
	if (head->next->next == NULL)
	{
		rhead = head->next;
		head->next->next = head;
		return rhead;
	}
	else if (head->next->next != NULL)
	{
		rhead=reverse(head->next, rhead);
		head->next->next = head;
	}
	return rhead;
}
struct node *start(struct node *head)
{
	struct node *rhead=NULL;
	if (head->next == NULL)
		return head;
	rhead = reverse(head, rhead);
	head->next = NULL;
	return rhead;
}
int check(int *nums, int len, struct node *head)
{
	int index = 0;
	struct node *temp = head;
	for (index = 0; index < len; index++)
	{
		if (temp->data != nums[index])
		{
			return  0;
		}
		temp = temp->next;
	}
	return 1;
}
int main()
{
	struct node *head = NULL;
	int i, j;
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < test[j].size; i++)
		{
			add(&head, test[j].arr[i]);
		}
		printf("Test case %d:-\n", j + 1);
		if (head == NULL)
		{
			printf("Empty Linked List\n\n");
			continue;
		}
		if (check(test[j].ans, test[j].size, start(head)))
		{
			printf("Method 1 passed\n\n");
		}
		else
		{
			printf("Method 1 Failed\n");
		}
		free(head);
		head = NULL;
	}
	getchar();
}