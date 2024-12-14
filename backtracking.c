//#include _CRT_NO_WARNINGS
#include<stdio.h>
#define N 4
typedef struct {
	int linie, coloana;
}coordonate;
coordonate pos[4];
coordonate a[N * N];

int matrice[N][N] = { {1,1,1,1},{1,0,1,1},{1,0,0,0},{1,0,1,0} };
void initializare() //int pos[] variabila globala
{
	pos[0].coloana = 0; // Nord
	pos[0].linie = -1;// y scade spre Nord
	pos[1].coloana = 1; // Est – x creste spre Est
	pos[1].linie = 0;
	pos[2].coloana = 0; // Sud
	pos[2].linie = 1; // y creste spre Sud
	pos[3].coloana = -1;// Vest – x scade spre Vest
	pos[3].linie = 0;
}
int ok(coordonate c)
{
	if (matrice[c.linie][c.coloana] == 0 && c.linie >= 0 && c.coloana >= 0 && c.linie <= N - 1 && c.coloana <= N - 1)
		return 1;
	return 0;
}
int solutie(coordonate c)
{
	if (c.linie == 0 || c.coloana == 0 || c.linie == N - 1 || c.coloana == N - 1)
		return 1;
	return 0;
}
void afisare()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", matrice[i][j]);
		printf("\n");
	}
	printf("\n");
}
void back(int k)
{
	if (solutie(a[k - 1]))
		afisare();
	for (int i = 0; i < 4; i++)
	{
		a[k].linie = a[k - 1].linie + pos[i].linie;
		a[k].coloana = a[k - 1].coloana + pos[i].coloana;
		if (ok(a[k]))
		{
				matrice[a[k].linie][a[k].coloana] = 2;
				back(k + 1);
				matrice[a[k].linie][a[k].coloana] = 0;
		}
		
	}
}

int main()
{
	initializare();
	a[0].linie = 1;
	a[0].coloana = 1;
	matrice[1][1] = 2;
	back(1);
	return 0;
}
