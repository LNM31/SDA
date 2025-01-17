#include<stdio.h>
#define N 4
typedef struct{
  char id;
  int durata,termen;
}cerere;
cerere v[N]={
  {'A',4,2},
  {'B',3,10},
  {'C',2,8},
  {'D',4,15},
};
cerere t[N]={
  {'A',5,11},
  {'B',1,3},
  {'C',3,9},
  {'D',2,8},
};

int compare(cerere a,cerere b)
{
  if(a.durata<b.durata)
    return 1;
  else if(a.durata>b.durata)
    return 0;
  return a.termen<b.termen;
}
void swap(cerere* el1, cerere* el2)
{
	cerere tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}
void deplasare(cerere a[], int stanga, int dreapta)
{
	int fiu = 2 * stanga + 1;
	while (fiu <= dreapta)
	{
		if (fiu < dreapta && compare(a[fiu],a[fiu+1]))
			fiu++;						 
		if (compare(a[stanga],a[fiu]))  
		{								        
			swap(&a[stanga], &a[fiu]);			
			stanga = fiu;
			fiu = 2 * stanga + 1;
		}
		else
			fiu = dreapta + 1;
	}
}
void heapsort(cerere a[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--) 
		deplasare(a, i, n - 1);
	for (i = n - 1; i >= 1; i--)
	{
		swap(&a[0], &a[i]);		
		deplasare(a, 0, i - 1);		
	}
}
void afisare(const cerere v[],int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%c %d %d\n",v[i].id,v[i].durata,v[i].termen);
    }
  printf("\n");
}
int main()
{
  afisare(v,N);
  heapsort(v,N);
  afisare(v,N);

  
  int s=0,d=0;
  for(int i=0;i<N;i++)
    {
      d=d+v[i].durata;
      s=s+v[i].termen-d;
    }
  printf("Scor maxim:%d\n",s);

  printf("\nExemplul 2:\n");
  afisare(t,N);
  heapsort(t,N);
  afisare(t,N);

  
  s=0,d=0;
  for(int i=0;i<N;i++)
    {
      d=d+t[i].durata;
      s=s+t[i].termen-d;
    }
  printf("Scor maxim:%d\n",s); 
  return 0;
}
