#include<stdio.h>
#include<conio.h>
struct testcases
{
	int num1;
	int num2;
	int r;
	int ans;
}test[] = {
	{3,5,30,65},
	{3,5,5,10},
	{5,3,1782138,3818868},
	{5,9,3,10}
};
int LCMCount(int num1, int num2, int *count)
{
	int i;
	for (i = (num1 > num2) ? num1 : num2; ; i++)
	{
		if (i%num1 == 0 || i%num2 == 0)
		{
			(*count)++;
		}
		if (i%num1 == 0 && i%num2 == 0)
			break;
	}
	return i;
}
int indexvalue(int num1, int num2, int count, int lcm, int r)
{
	int index = r%count;
	int flag = 1, lcm2;
	lcm *= (r / count) + 1;
	lcm2 = lcm;
	while (index != count)
	{
		if (lcm - num1 > lcm2 - num2)
		{
			lcm -= num1;
			flag = 1;
		}
		else
		{
			lcm2 -= num2;
			flag = 0;
		}
		count--;
	}
	if (flag)
		return lcm;
	return lcm2;
}
int rthvalue(int num1, int num2, int r)
{
	int lcm, count = 1;
	if (r < 1)
		return 0;
	lcm = LCMCount(num1, num2, &count);
	if (r%count == 0)
	{
		return lcm*(r / count);
	}
	else
		return indexvalue(num1, num2, count, lcm, r);
}
int main()
{
	int j;
	for (j = 0; j < 4; j++)
	{
		if (test[j].ans == rthvalue(test[j].num1, test[j].num2, test[j].r))
		{
			printf("Passed\n\n");
		}
		else
		{
			printf("Failed\n\n");
		}
	}
	getchar();
}