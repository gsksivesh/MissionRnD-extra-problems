#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct testcases
{
	int arr[30];
	int size;
	int ans[30];
}test[] = {
	{ { 1, 2, 15, 10, 7, 20 }, 6, { 1, 2, 7, 10, 15, 20 } },
	{ { 1, 2, 10, 7, 15, 20 }, 6, { 1, 2, 7, 10, 15, 20 } },
	{ { 20, 2, 7, 10, 15, 1 }, 6, { 1, 2, 7, 10, 15, 20 } },
	{ { 2, 1, 7, 10, 15, 20 }, 6, { 1, 2, 7, 10, 15, 20 } },
	{ { 7, 2, 1, 10, 15, 20 }, 6, { 1, 2, 7, 10, 15, 20 } }
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
struct node * correct(struct node *head)
{
	struct node *temp;
	struct node *prev1 = NULL, *prev2 = NULL;
	temp = head;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			break;
		prev1 = temp;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return head;
	if (prev1 == NULL)
	{
		prev1 = (struct node*)malloc(sizeof(struct node));
		prev1->next = head;
		prev2 = temp;
		temp = temp->next;
	}
	while (temp->next != NULL)
	{
		if (prev1->next->data < temp->next->data)
			break;
		prev2 = temp;
		temp = temp->next;
	}
	if (prev1->next == head)
	{
		if (prev1->next == prev2)
		{
			prev1->next = prev2->next;
			temp = prev2->next->next;
			prev2->next->next = prev2;
			prev2->next = temp;
			temp = prev1->next;
			free(prev1);
			return temp;
		}
		temp = prev2->next->next;
		prev2->next->next = prev1->next->next;
		prev1->next->next = temp;
		temp = prev2->next;
		prev2->next = prev1->next;
		free(prev1);
		return temp;
	}
	temp = prev2->next;
	prev2->next = prev1->next;
	prev1->next = temp;
	temp = prev1->next->next;
	prev1->next->next = prev2->next->next;
	prev2->next->next = temp;
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
	for (j = 0; j < 5; j++)
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
		head = correct(head);
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