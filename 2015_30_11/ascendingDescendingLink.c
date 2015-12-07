#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct testcases
{
	int arr[30];
	int size;
	int ans[30];
}test[] = {
	{ { 1, 2, 7, 20, 15, 10 }, 6, { 1, 2, 7, 10, 15, 20 } },
	{ { 1, 2, 3, 4, 5, 19, 15, 12, 10, 6 }, 10, { 1, 2, 3, 4, 5, 6, 10, 12, 15, 19 } },
	{ { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 9, { 1, 2, 3, 4, 5, 6, 7, 8, 9 } },
	{ { 9, 8, 7, 6, 5, 4, 3, 2, 1 }, 9, { 1, 2, 3, 4, 5, 6, 7, 8, 9 } }
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
struct node * sortAD(struct node *head)
{
	struct node *temp1, *temp2, *temp, *prev = NULL;
	temp = head;
	while (temp != NULL)
	{
		if (temp->next!=NULL && temp->data > temp->next->data)
		{
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return head;
	temp1 = temp->next;
	temp->next = NULL;
	temp2 = temp;
	temp = temp1;
	while (temp != NULL)
	{
		temp1 = temp->next;
		temp->next = temp2;
		temp2 = temp;
		temp = temp1;
	}
	if (prev == NULL)
		return temp2;
	prev->next = temp2;
	return head;
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
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < test[j].size; i++)
		{
			add(&head, test[j].arr[i]);
		}
		if (head == NULL)
		{
			printf("Empty LinkedList\n\n");
			continue;
		}
		head = sortAD(head);
		if (check(test[j].ans, test[j].size, head))
		{
			printf("Passed\n\n");
		}
		else
		{
			printf("Failed\n\n");
		}
		free(head);
		head = NULL;
	}
	getchar();
}