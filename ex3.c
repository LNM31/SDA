#include<stdio.h>
#define N 5
int dx[] = {0,0,-1,1};//sus,jos,stanga,dreapta
int dy[] = {-1,1,0,0};
int matrice[N][N] = {
	{ 1, 1, 0, 0, 0 },
	{ 0, 1, 1, 0, 0 },
	{ 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 1 },
	{ 0, 1, 0, 1, 1 }
};
int vizitat[N][N];
int zone[N*N],count;
int ok(int xnew, int ynew)
{
	if (xnew >= 0 && ynew >= 0 && xnew <= N - 1 && ynew <= N - 1 && matrice[xnew][ynew] == 1 && vizitat[xnew][ynew] == 0)
		return 1;
	return 0;
}
void gasit(int size)
{
	zone[count++] = size;
}
void back(int x, int y,int *size)
{
	for (int i = 0; i < 4; i++)
	{
		int xnew = x + dx[i];
		int ynew = y + dy[i];
		if (ok(xnew, ynew))
		{
			vizitat[xnew][ynew] = 1;
			(*size)++;
			back(xnew, ynew,size);
		}
	}
}
int main()
{
	int size=1;
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			if (matrice[i][j] == 1 && vizitat[i][j] == 0)
			{
				vizitat[i][j] = 1;
				size = 1;
				back(i, j, &size);
				gasit(size);
			}
		}
	for (int i = 0; i < count; i++)
		printf("C%d are %d celule de 1 interconectate\n",i,zone[i]);
	int maxim = 0;
	for (int i = 0; i < count; i++)
	{
		if (zone[i] > maxim)
			maxim = zone[i];
	}
	printf("Cea mai mare celula are %d 1-uri interconectate\n", maxim);
	return 0;
}
