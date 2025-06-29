#include<stdio.h>
#include<string.h>
#define N 10
typedef struct {
  char nume[25];
  char telefon[10];
  int an,venit;
}agenda;
agenda v[]={                                                                    
  {"N4","07-4",1988,1201},// 37 ani                                             
  {"N3","07-3",1989,1202},// 36 ani                                             
  {"N2","07-2",1986,800},// 39 ani                                              
  {"N5","07-5",1997,1203},// 28 ani                                             
  {"N6","07-6",1994,1204},// 31 ani                                             
  {"N7","07-7",1991,400},// 34 ani                                              
  {"N8","07-8",2004,1205},// 21 ani                                             
  {"N1","07-1",1994,1209},// 31 ani                                             
  {"N10","07-10",1983,1206},// 42 ani                                           
  {"N9","07-9",2001,1207},// 24 ani                                             
};
agenda temp[N];
int l;
void swap(agenda* el1, agenda* el2)
{
	agenda tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}
void f1(agenda v[],int size)
{
  int n=2;
  for(int i=0;i<size;i++)
    {
      if(v[i].venit<1000)
	{
	  if(n==2)
	    {
	      swap(&v[i],&v[size-1]);
	      n--;
	    }
	  else if(n==1)
	    {
	      swap(&v[i],&v[size-2]);
	      return;
	    }
	}
    }
}
void afisare(const agenda *v,int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%s %s %d %d %d\n",v[i].nume,v[i].telefon,v[i].an,v[i].venit,2025-v[i].an);
    }
  printf("\n");
}
void quicksort(agenda a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	swap(&a[prim], &a[(prim + ultim) / 2]);
	agenda pivot = a[prim];
	while (stanga <= dreapta)
	{
	  while (stanga<=ultim && strcmp(a[stanga].nume,pivot.nume)<0)
			stanga++;
	  while (dreapta>=prim && strcmp(a[dreapta].nume,pivot.nume)>0)
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
void func(agenda a[],agenda temp[],int size)
{
  for(int i=0;i<size;i++)
    {
      if(2025-a[i].an>=30 && 2025-a[i].an<=40)
	temp[l++]=a[i];
    }
  quicksort(temp,0,l-1);
  l=0;
  for(int i=0;i<size;i++)
    {
      if(2025-a[i].an>=30 && 2025-a[i].an<=40)
	a[i]=temp[l++];
    }
}
/*
  pentru prima functie cand am intalnit primele doua venituri mai mici ca 1000,am inter
  -schimbat cu valorile de la final,rezulta O(n)
  -f swap O(1)
  -functia afisare o(n)
  -pentru a doua functie am salvat valorile necesare intr un alt tablou aux dupa care
  am aplicat quicksort pe el si la final le am reintrodus in tabloule initial,
  rezulta O(n)+O(nlog n)+ o(n)=O(nlog n)

  rezulta complexitatea algoritmului O(nlog n)
  
*/
void selection_sort(agenda a[], int n)
{
	int i, j, min; // min retine INDEXUL elementului cu valoare minima
	for (i = 0; i < n - 1; i++)
	{
	  if(2025-a[i].an>=30 && 2025-a[i].an<=40)
	    {
	        min = i;
		//printf("a");
		for (j = i + 1; j < n; j++)
		{
		  if (2025-a[j].an>=30 && 2025-a[j].an<=40 && strcmp(a[j].nume,a[min].nume)<0)
				min = j;
		}
		swap(&a[min], &a[i]);
	    }
	}
}
int main()
{
  afisare(v,N);
  f1(v,N);
  afisare(v,N);
  //func(v,temp,N);
  selection_sort(v,N);
  afisare(v,N);
  return 0;
}
