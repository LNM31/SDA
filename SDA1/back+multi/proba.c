#include<stdio.h>
#include<string.h>
#define N 6
typedef struct{
  char proba[201];
  int valoare;
  int actualizare;
}scor;

void swap(scor *e1,scor *e2)
{
  scor tmp=*e1;
  *e1=*e2;
  *e2=tmp;
}
scor v[N]={
  {"P1",1,0},
  {"P2",2,1},
  {"P3",3,0},
  {"P4",4,1},
  {"P5",5,1},
  {"P6",6,0},
};
void f1(scor *v,int size)
{
  for(int i=1;i<size;i++)
    {
      if(i%2==1)
	{
	  if(v[i-1].valoare<v[i].valoare)
	    swap(&v[i-1],&v[i]);
	}
      else
	{
	  if(v[i-1].valoare>v[i].valoare)
	    swap(&v[i-1],&v[i]);
	}
    }
}
void f2(scor *v,int size)
{
  int st=0,dr=size-1;
  while(st<dr)
    {
      while(v[st].actualizare==1)
	st++;
      while(v[dr].actualizare==0)
	dr--;
      if(st<dr)
	swap(&v[st],&v[dr]);
      st++;
      dr--;
    }
}
void afisare(scor *v,int size)
{
  for(int i=0;i<size;i++)
    {
      printf("%s %d %d\n",v[i].proba,v[i].valoare,v[i].actualizare);
    }
  printf("\n");
}
/*
-prima functie functioneaza printr o parcurgere,cand doua elemente nu verifica conditia
de comparare in functie de indecele par sau impar,atunci le interschimba,rezulta O(n)
-a doua functie consta in declararea a doua capete,standa si dreapta,cu stanga creste
pana cand gaseste un elem cu act falsa,dreapta scade pana cand intalneste un elem cu
actualizarea true,dupa care le interschimba,rezulta O(n)
*/
int main()
{
  afisare(v,N);
  f1(v,N);
  afisare(v,N);
  f2(v,N);
  afisare(v,N);
  return 0;
}
