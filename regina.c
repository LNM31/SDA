#include<stdio.h>
#include<math.h>
#define N 8
int ok(int k, int* v)
{
	for (int i = 0; i < k; i++)
	{
		if (v[i]==v[k] || abs(i - k) == abs(v[i] - v[k]))
			return 0;
	}
	return 1;
}
int solutie(int k, int n)
{
	return (n-1) == k;
}
void afisare(int k, int* v)
{
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j == v[i])
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
}
void back(int k, int* v, int n)
{
	for (int i = 0; i < n; i++)
	{
		v[k] = i;
		if (ok(k, v))
		{
			if (solutie(k, n))
			{
				afisare(k, v);
			}
			else back(k + 1, v, n);
		}
	}
}
int main()
{
	int v[100], n = 8;
	back(0, v, 8);
	return 0;
}
