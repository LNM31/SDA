#include<stdio.h>
#include<string.h>
#define N 10
typedef struct{
  char nume[35];
  int varsta,premii;
}student;
student v[]={
  {"A",40,1},
  {"stu2",60,0},
  {"C",50,1},
  {"D",80,1},
  {"stu5",70,0},
  {"stu6",30,0},
  {"stu7",100,0},
  {"E",10,1},
  {"B",20,1},
  {"stu10",90,0},
};
void display(const student *v,int size)
{
  for(int i=0;i<size;i++)
    printf("%s %d %d\n",v[i].nume,v[i].varsta,v[i].premii);
  printf("\n");
}
void f1(student *v,int size)
{
  int c1=0,c2=size-1;
  student aux;
  while(c1<c2)
    {
      while(v[c1].premii==1)
	c1++;
      while(v[c2].premii==0)
	c2--;
      if(c1<c2)
	{
	  aux=v[c1];
	  v[c1]=v[c2];
	  v[c2]=aux;
	}
      c1++;
      c2--;
    }
}
void swap(student* el1, student* el2)
{
	student tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}
void quicksort(student a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	swap(&a[prim], &a[(prim + ultim) / 2]);
	student pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
	  while (stanga<=ultim && strcmp(pivot.nume,a[stanga].nume)<0)
			stanga++;
		while (dreapta>=prim && strcmp(pivot.nume,a[dreapta].nume)>0)
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
  display(v,N);
  f1(v,N);
  display(v,N);
  int c=0;
  while(v[c].premii==1)
    c++;
  quicksort(v,0,c-1);
  display(v,N);
  return 0;
}
