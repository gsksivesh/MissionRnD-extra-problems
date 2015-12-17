//Merge two linked list which are in sorted order
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct testcases
{
	int arr1[20];
	int arr2[20];
	int size1;
	int size2;
	int ans[40];
	int size;
}test[] = {
	{ { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, 5, 5, { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 }, 10 },
	{ { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, 5, 5, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 },
	{ { 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5 }, 5, 5, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 },
	{ NULL, NULL, 0, 0, NULL, 0 },
	{ { NULL }, { 1, 2, 3, 4, 5 }, 0, 5, { 1, 2, 3, 4, 5 }, 5 },
	{ { 1, 2, 3, 4, 5 }, { NULL }, 5, 0, { 1, 2, 3, 4, 5 }, 5 },
	{ { 1, 3, 5, 7, 9 }, { 2, 4, 6 }, 5, 3, { 1, 2, 3, 4, 5, 6, 7, 9 }, 8 },
	{ { 2, 4, 6 }, { 1, 3, 5, 7, 9 }, 3, 5, { 1, 2, 3, 4, 5, 6, 7, 9 }, 8 },
	{ { 1, 3, 5, 7, 9 }, { 2, 4, 6, 8, 10 }, 5, 5, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10 }
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
struct node * merge(struct node *head1, struct node *head2)
{
	struct node *temp1, *temp2, *temp;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	temp1 = head1;
	temp2 = head2;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->next != NULL && temp2->data >= temp1->data && temp2->data <= temp1->next->data)
		{
			temp = temp1->next;
			temp1->next = temp2;
			temp1 = temp;
		}
		else if (temp2->next != NULL && temp1->data >= temp2->data && temp1->data <= temp2->next->data)
		{
			temp = temp2->next;
			temp2->next = temp1;
			temp2 = temp;
		}
		else if (temp2->data >= temp1->data && temp1->next==NULL)
		{
			temp1->next = temp2;
			temp1 = NULL;
		}
		else if (temp1->data >= temp2->data && temp2->next==NULL)
		{
			temp2->next = temp1;
			temp2 = NULL;
		}
		else if (temp2->data > temp1->data)
		{
			temp1 = temp1->next;
		}
		else if (temp1->data > temp2->data)
		{
			temp2 = temp2->next;
		}
	}
	if (head1->data <= head2->data)
		return head1;
	else
		return head2;
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
	struct node *head1 = NULL, *head2 = NULL;
	int i, j;
	for (j = 0; j < 9; j++)
	{
		for (i = 0; i < test[j].size1; i++)
		{
			add(&head1, test[j].arr1[i]);
		}
		for (i = 0; i < test[j].size2; i++)
		{
			add(&head2, test[j].arr2[i]);
		}
		printf("Test case %d:-\n", j + 1);
		if (head1 == NULL && head2 == NULL)
		{
			printf("Empty Linked Lists\n\n");
			continue;
		}
		if (check(test[j].ans,test[j].size,merge(head1,head2)))
		{
			printf("Passed\n\n");
		}
		else
		{
			printf("Failed\n\n");
		}
		free(head1);
		free(head2);
		head1 = NULL;
		head2 = NULL;
	}
	getchar();
}