#include<stdio.h>
#define N 4
int dx[] = {0,0,-1,1};//sus,jos,stanga,dreapta
int dy[] = {-1,1,0,0};
int matrice[N][N] = {
	{1,1,1,1},
	{1,0,1,1},
	{1,0,0,0},
	{1,0,1,0}
};
int nr_sol;
int ok(int xnew, int ynew)
{
	if (xnew >= 0 && ynew >= 0 && xnew <= N - 1 && ynew <= N - 1 && matrice[xnew][ynew] == 0)
		return 1;
	return 0;
}
int solutie(int x, int y)
{
	if (x == 0 || y == 0 || x == N - 1 || y == N - 1)
		return 1;
	return 0;
}
void afisare()
{
	printf("Sol : %d\n", ++nr_sol);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", matrice[i][j]);
		printf("\n");
	}
	printf("\n");
}
void back(int x, int y)
{
	if (solutie(x, y))
		afisare();
    for (int i = 0; i < 4; i++)
	{
		int xnew = x + dx[i];
		int ynew = y + dy[i];
		if (ok(xnew, ynew))
		{
			matrice[xnew][ynew] = 2;
			back(xnew, ynew);
			matrice[xnew][ynew] = 0;
		}
	}
}
int main()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrice[i][j] == 0)
			{
				printf("Se porneste de la linia %d coloana %d\n", i, j);
				matrice[i][j] = 2;
				back(i, j);
				matrice[i][j] = 0;
			}
		}
	}
}
