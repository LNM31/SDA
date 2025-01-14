#include<stdio.h>
#include<string.h>
#define N 10
typedef struct {
  char nume[25],telefon[10];
  int an,venit;
}agenda;
agenda v[]={
  {"N4","07-4",1988,1201},// 37 ani
  {"N3","07-3",1989,1202},// 36 ani
  {"N2","07-2",1986,800},// 39 ani
  {"N5","07-5",1997,1203},// 28 ani
  {"N1","07-1",1999,1204},// 26 ani
  {"N7","07-7",1991,400},// 34 ani
  {"N8","07-8",2004,1205},// 21 ani
  {"N6","07-6",1994,1209},// 31 ani
  {"N10","07-10",1983,1206},// 42 ani
  {"N9","07-9",2001,1207},// 24 ani
};

int d[N],l=0;

void display(agenda *v,int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%s %s %d %d %d ani\n",v[i].nume,v[i].telefon,v[i].an,v[i].venit,2025-v[i].an);
    }
  printf("\n");
}
void f1(agenda *v,int size)
{
  int c1=0,c2=0;
  int nr=0;
  agenda aux;
  for(int i=0;i<size;i++)
    {
      if(v[i].venit<1000)
	{
	  if(nr==1)
	    {
	      nr=2;
	      c2=i;
	      break;
	    }
	  nr=1;
	  c1=i;
	}
    }
  if(nr==2)
    {
      aux=v[c1];
      v[c1]=v[size-2];
      v[size-2]=aux;

      aux=v[c2];
      v[c2]=v[size-1];
      v[size-1]=aux;
    }
  else if(nr==1)
    {
      aux=v[c1];
      v[c1]=v[size-1];
      v[size-1]=aux;
    }
}
void function(agenda *v,int size)
{
  for(int i=0;i<size;i++)
    if(2025-v[i].an>=30 &&2025-v[i].an<=40)
      {
	d[l++]=i;
      }
}
void swap(agenda* el1, agenda* el2)
{
	agenda tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}
void quicksort(int d[],agenda a[], int prim, int ultim)
{
	int stanga = d[prim + 1];
	int dreapta = d[ultim];
	int i=prim+1,j=ultim;
	//alegere pivot
	swap(&a[d[prim]], &a[d[(prim + ultim) / 2]]);
	//mutare pivot pe prima pozitie
	agenda pivot = a[d[prim]];
	while (stanga <= dreapta) //partitionare
	{
	  while (stanga<=d[ultim] && strcmp(a[stanga].nume,pivot.nume)<0)
			stanga=d[i++];
	  while (dreapta>=d[prim] && strcmp(a[dreapta].nume,pivot.nume)>0)
			dreapta=d[j--];
		if (stanga < dreapta)
		  {
		    swap(&a[stanga], &a[dreapta]);
		    stanga=d[i++];
		    dreapta=d[j--];
		  }
		else
			stanga=d[i++];
	}
	//mutare pivot la locul sau final
	swap(&a[dreapta], &a[d[prim]]);
	//apelurile recursive
	if (d[prim] < dreapta - 1)
	  quicksort(d,a, d[prim], dreapta - 1);
	if (dreapta + 1 < d[ultim])
	  quicksort(d,a, dreapta + 1,d[ultim]);
}
int main()
{
  display(v,N);
  f1(v,N);
  display(v,N);
  function(v,N);
  quicksort(d,v,0,l-1);
  display(v,N);
  for(int i=0;i<l;i++)
    printf("%d ",d[i]);
  printf("\n%d\n",l);
  return 0;
}
