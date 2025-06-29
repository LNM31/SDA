#include<stdio.h>
#define N 8
typedef struct {
  char nume[25];
  int puncte,buget;
  char oras[25];
}echipa;
echipa v[N]={
  {"N1",40,400000,"O1"},
  {"N2",50,500000,"O2"},
  {"N3",19,500000,"O3"},
  {"N4",60,100   ,"O4"},
  {"N5",90,400   ,"O5"},
  {"N6",70,200000,"O6"},
  {"N7",10,300000,"O7"},
  {"N8",80,900   ,"O8"},
};
echipa tmp[N];
int l;
void swap(echipa *e1,echipa *e2)
{
  echipa tmp;
  tmp=*e1;
  *e1=*e2;
  *e2=tmp;
}
void f1(echipa *v,int size)
{
  int st=0,dr=size-1;
  while(st<dr)
    {
      while(v[st].puncte>45)
	st++;
      while(v[dr].puncte<=45)
	dr--;
      if(st<dr)
	swap(&v[st],&v[dr]);
      st++;
      dr--;
    }
  st=0,dr=size-1;
  while(st<dr)
    {
      while(v[st].puncte>=20)
	st++;
      while(v[dr].puncte<20)
	dr--;
      if(st<dr)
	swap(&v[st],&v[dr]);
      st++;
      dr--;
    }
  
}
void afisare(const echipa *v,int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%s %d %6d %s\n",v[i].nume,v[i].puncte,v[i].buget,v[i].oras);
    }
  printf("\n");
}
void quicksort(echipa a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	swap(&a[prim], &a[(prim + ultim) / 2]);
	echipa pivot = a[prim];
	while (stanga <= dreapta) 
	{
		while (stanga<=ultim && a[stanga].puncte > pivot.puncte)
			stanga++;
		while (dreapta>=prim && pivot.puncte > a[dreapta].puncte)
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
void f2(echipa *v,echipa *tmp,int size)
{
  for(int i=0;i<size;i++)
    {
      if(v[i].buget>100000)
	tmp[l++]=v[i];
    }
  quicksort(tmp,0,l-1);
  l=0;
  for(int i=0;i<size;i++)
    {
      if(v[i].buget>100000)
	v[i]=tmp[l++];
    }
}
int main()
{
  afisare(v,N);
  f1(v,N);
  afisare(v,N);
  f2(v,tmp,N);
  afisare(v,N);
  return 0;
}
