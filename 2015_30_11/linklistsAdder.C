#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct testcases
{
	int num1;
	int num2;
}test[] = {
	{1234,1234},
	{999,1},
	{9999,9999}
};
struct node
{
	int data;
	struct node *next;
};
struct node * createList(int num)
{
	struct node *head;
	struct node *temp;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = num % 10;
	head->next = NULL;
	num /= 10;
	while (num)
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num % 10;
		temp->next = head;
		head = temp;
		num /= 10;
	}
	return head;
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
		rhead = reverse(head->next, rhead);
		head->next->next = head;
	}
	return rhead;
}
struct node *start(struct node *head)
{
	struct node *rhead = NULL;
	if (head->next == NULL)
		return head;
	rhead = reverse(head, rhead);
	head->next = NULL;
	return rhead;
}
struct node *addRemaining(struct node *temp, struct node *ans, struct node *prev, int *carry)
{
	while (temp != NULL && *carry)
	{
		ans = (struct node*)malloc(sizeof(struct node));
		ans->data = (temp->data + *carry) % 10;
		if ((temp->data + *carry) / 10)
			*carry = 1;
		else
			*carry = 0;
		prev->next = ans;
		prev = ans;
		temp = temp->next;
	}
	while (temp != NULL)
	{
		ans = (struct node*)malloc(sizeof(struct node));
		ans->data = temp->data;
		prev->next = ans;
		prev = ans;
		temp = temp->next;
	}
	if (*carry)
	{
		ans = (struct node*)malloc(sizeof(struct node));
		ans->data = 1;
		prev->next = ans;
		*carry = 0;
	}
	return ans;
}
struct node * add(struct node *head1, struct node *head2)
{
	int carry = 0;
	struct node *temp1, *temp2, *temp=NULL, *head = NULL;
	struct node *ans = NULL;
	temp1 = head1;
	temp2 = head2;
	temp1 = start(temp1);
	temp2 = start(temp2);
	while (temp1 != NULL && temp2 != NULL)
	{
		ans = (struct node*)malloc(sizeof(struct node));
		ans->data = (temp1->data + temp2->data + carry) % 10;
		if ((temp1->data + temp2->data + carry) / 10)
			carry = 1;
		else
			carry = 0;
		if (temp == NULL)
		{
			head = ans;
			temp = ans;
		}
		else
		{
			temp->next = ans;
			temp = ans;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if (temp1 != NULL)
		ans = addRemaining(temp1, ans, temp, &carry);
	if (temp2 != NULL)
		ans = addRemaining(temp2, ans, temp, &carry);
	if (carry)
	{
		temp = ans;
		ans = (struct node*)malloc(sizeof(struct node));
		ans->data = 1;
		temp->next = ans;
		carry = 0;
	}
	ans->next = NULL;
	head = start(head);
	return head;
}
int check(struct node *ans, struct node *head)
{
	
	while (ans != NULL)
	{
		if (ans->data != head->data)
		{
			return  0;
		}
		ans = ans->next;
		head = head->next;
	}
	return 1;
}
int main()
{
	struct node *head = NULL;
	int i, j;
	for (j = 0; j < 3; j++)
	{
		head = add(createList(test[j].num1), createList(test[j].num2));

		if (head == NULL)
		{
			printf("Empty LinkedList\n\n");
			continue;
		}
		if (check(createList(test[j].num1+test[j].num2),head))
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