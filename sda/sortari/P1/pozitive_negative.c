#include<stdio.h>
#define N 10
int v[N]={2,-1,-4,0,5,4,9,-8,7,-5};
int prim_pozitiv;
void swap(int *e1,int *e2)
{
  int tmp;
  tmp=*e1;
  *e1=*e2;
  *e2=tmp;
}
void f1(int *v,int size)
{
  int st=0,dr=size-1;
  while(st<dr)
    {
      while(v[st]<0)
	st++;
      while(v[dr]>0)
	dr--;
      if(st<dr)
	  swap(&v[st],&v[dr]);
      st++;
      dr--;
    }
}
void afisare(int *v,int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%d ",v[i]);
    }
  printf("\n");
}
void quicksort(int a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	swap(&a[prim], &a[(prim + ultim) / 2]);
	int pivot = a[prim];
	while (stanga <= dreapta)
	{
		while (stanga<=ultim && a[stanga] < pivot)
			stanga++;
		while (dreapta>=prim && pivot < a[dreapta])
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
-prima functie consta in definirea lui st (inceput),dr(sfarsit),st creste pana cand
sa de un numar pozitiv,dr scade pana cand da de un numar neg,dupa care interschimba elem
Astfel,se rezulta la O(n)
-a doua functie este functia de sortare quicksort care ef. O(nlog n)
-rezulta efi algortmului O(n)+O(nlogn)=O(nlog n)
*/
int main()
{
  afisare(v,N);
  f1(v,N);
  afisare(v,N);
  while(v[prim_pozitiv]<0)
    prim_pozitiv++;
  quicksort(v,prim_pozitiv,N-1);
  afisare(v,N);
  return 0;
}
