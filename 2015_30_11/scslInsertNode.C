//Add a node to the circular linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct testcases
{
	int arr[20];
	int size;
	int insertELement;
	int ans[20];
	int asize;
}test[7] = {
	{ { 1, 2, 3, 4, 5 }, 5, 4, { 1, 2, 3, 4, 4, 5 }, 6 },
	{ { 2, 3, 4, 5 }, 4, 1, { 1, 2, 3, 4, 5 }, 5 },
	{ { 1, 2, 3, 4, 5 }, 5, 6, { 1, 2, 3, 4, 5, 6 }, 6 },
	{ { NULL }, 0, 0, {NULL} }
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
		(*head)->next = (*head);
	}
	else
	{
		while (temp->next != (*head))
		{
			temp = temp->next;
		}
		temp->next = createNode(p);
		temp->next->next = (*head);
	}
}
struct node * insertNode(struct node *head,int num)
{
	struct node *temp, *temp1 = NULL;
	temp = head;
	if (num < temp->data)
	{
		temp1 = (struct node*)malloc(sizeof(struct node*));
		temp1->data = head->data;
		temp1->next = head->next;
		head->next = temp1;
		head->data = num;
		return head;
	}
	while (temp->next != head)
	{
		if (num >= temp->data)
		{
			if (num <= temp->next->data || temp->next==head)
			{
				temp1 = (struct node*)malloc(sizeof(struct node));
				temp1->data = num;
				temp1->next = temp->next;
				temp->next = temp1;
				return head;
			}
		}
		temp = temp->next;
	}
	if (num > temp->data)
	{
		temp1 = (struct node*)malloc(sizeof(struct node));
		temp1->data = num;
		temp1->next = temp->next;
		temp->next = temp1;
	}
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
	struct node *head = NULL,*temp;
	int i,j;
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < test[j].size; i++)
		{
			add(&head, test[j].arr[i]);
		}
		printf("Test Case %d:-\n", j + 1);
		if (head == NULL)
		{
			printf("Empty Linked List\n\n");
			continue;
		}
		if (check(test[j].ans, test[j].asize, insertNode(head, test[j].insertELement)))
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