#include<stdio.h>
#include<conio.h>
struct testcases
{
	int arr[30];
	int size;
	int ans[30];
}test[] = {
	{ { 1, 2, 3, 4, 5, -2, -3, -4, 11, 5 }, 10, { 11, 5 } },
	{ { -1, -2, -3, -4, 0 }, 5, { 0 } },
	{ { 1, 2, 3, 4, 5, 6 }, 6, { 1, 2, 3, 4, 5, 6 } },
	{ { 1 }, 1, { 1 } },
	{ { -1 }, 1, { -1 } },
	{ { 25, 26, 13, -4, 102 }, 5, { 102 } },
	{ { 67, 62, 45, -6, -34, -45, 74, 56, 78, -3, -2, -4, 67, 89, 75 }, 15, { 67, 89, 75 } },
	{ { 25, 26, 13, -5, 102, 0 }, 6, { 102 } }
};
int * max(int arr[], int size)
{
	int max = arr[0];
	int i, index=0;
	for (i = 1; i < size; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
			index = i;
		}
	}
	return arr + index;
}
int * maxsubarray(int *arr, int *size)
{
	int i = 0, start1, stop1, start2;
	int sum1 = 0; int sum2 = 0;
	while (i < *size && arr[i] <= 0)
	{
		i++;
	}
	if (i == *size)
	{
		*size = 1;
		return max(arr, i);
	}
	start1 = i;
	while (i < *size && arr[i] >= 0)
	{
		sum1 += arr[i];
		i++;
	}
	stop1 = i;
	if (i == *size)
	{
		*size = (*size) - start1;
		return arr + start1;
	}
	i++;
	while (i < *size)
	{
		while (i < *size && arr[i] <= 0)
		{
			i++;
		}
		start2 = i;
		sum2 = 0;
		while (i < *size && arr[i] >= 0)
		{
			sum2 += arr[i];
			i++;
		}
		if (sum2 >= sum1)
		{
			if (sum1 == sum2 && (stop1 - start1)<(i - start2))
			{
				continue;
			}
			start1 = start2;
			stop1 = i;
			sum1 = sum2;
		}
	}
	while (arr[stop1 - 1] == 0)
	{
		stop1--;
	}
	*size = stop1 - start1;
	return arr + start1;
}
int check(int arr[], int ans[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] != ans[i])
			return 0;
	}
	return 1;
}
int main()
{
	int *ans;
	int j;
	for (j = 0; j < 8; j++)
	{
		ans = maxsubarray(test[j].arr, &test[j].size);
		if (check(ans, test[j].ans, test[j].size))
		{
			printf("Passed\n");
		}
	}
	getchar();
}