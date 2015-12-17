#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int test[] = { 3, 2, 6, -2 };
void lastLines(int k)
{
	int count = 0;
	FILE *file = fopen("abc.txt", "r");
	char line[128];
	if (file != NULL)
	{
		while (fgets(line, sizeof line, file) != NULL)
		{
			count++;
		}
		fclose(file);
	}
	file = fopen("abc.txt", "r");
	if (file != NULL)
	{
		while (fgets(line, sizeof line, file) != NULL)
		{
			if (count <= k)
			{
				printf("%s", line);
			}
			count--;
		}
		fclose(file);
	}
}
int main()
{
	int j;
	for (j = 0; j < 4; j++)
	{
		lastLines(test[j]);
		printf("\n\n");
	}
	getchar();
}