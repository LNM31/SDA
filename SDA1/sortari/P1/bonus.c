#include<stdio.h>
#define N 10
typedef struct {
	char nume[35];
	int salar, bonus;
}angajat;
angajat v[] = {
	{"ang1",40,1},
	{"ang2",60,0},
	{"ang3",50,1},
	{"ang4",80,1},
	{"ang5",70,0},
	{"ang6",30,0},
	{"ang7",100,0},
	{"ang8",10,1},
	{"ang9",20,1},
	{"ang10",90,0},
};
void display(const angajat* v, int size)
{
	for (int i = 0; i < size; i++)
		printf("%s %d %d\n", v[i].nume, v[i].salar, v[i].bonus);
	printf("\n");
}
void f1(angajat* v, int size)
{
	int c1 = 0, c2 = size - 1;
	angajat aux;
	while (c1 < c2)
	{
		while (v[c1].bonus == 1)
			c1++;
		while (v[c2].bonus == 0)
			c2--;
		if (c1 < c2)
		{
			aux = v[c1];
			v[c1] = v[c2];
			v[c2] = aux;
		}
		c1++;
		c2--;
	}

}
void swap(angajat* el1, angajat* el2)
{
	angajat tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}
void quicksort(angajat a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	swap(&a[prim], &a[(prim + ultim) / 2]);
	angajat pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga<=ultim && a[stanga].salar > pivot.salar)
			stanga++;
		while (dreapta>=prim && pivot.salar > a[dreapta].salar)
			dreapta--;
		if (stanga < dreapta)
			swap(&a[stanga++], &a[dreapta--]);
		else
			stanga++;
	}
	swap(&a[dreapta], &a[prim]);
	if (prim < dreapta - 1)
		quicksort(a, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(a, dreapta + 1, ultim);
}
/*
-algoritmul ales este quicksort,este unul dintre cei mai buni algoritmi de sortare pe
cazuri generale,avand eficienta O(nlog n)pentru caz general
-structurile de date alese sunt angajatii,asa cum sunt cerinta
-se pot vedea rezultatele dand run
*/
int main()
{
	display(v, N);
	f1(v, N);
	display(v, N);
	int c=0;
	while(v[c].bonus==1 && c<N)
	  {
	    c++;
	  }
	quicksort(v,c,N-1);
	display(v,N);
	return 0;
}
