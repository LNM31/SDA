#include<stdio.h>
#include<stdlib.h>
#define N 8
typedef struct gg{
  int id,prio;
  struct gg*next;
}proces;//lista secundara;
typedef struct{
  proces*v[N];
}List;//lista principala;



//pt lista secundara
proces *make(int id,int prio,proces *elem)
{
  proces *e=(proces *)malloc(sizeof(proces));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  e->id=id;
  e->prio=prio;
  e->next=elem;
  return e;
}
proces *push(proces *pro,proces *lista)
{
  if(lista==NULL)
    {
      pro->next=NULL;
      return pro;
    }
  proces *p=lista;
  for(;p->next!=NULL;p=p->next);
  p->next=pro;
  pro->next=NULL;
  return lista;
}
proces *pop(proces **lista)
{
  if(*lista==NULL)
    return NULL;
  proces *rez=*lista;
  *lista=(*lista)->next;
  return rez;;
}
void display(proces *lista)
{
  proces *p=lista;
  while(p!=NULL)
    {
      printf("(proc %d) ",p->id);
      p=p->next;
    }
  printf("\n");
}









//pt lista principala
void initializare(List *lista)
{
  for(int i=0;i<N;i++)
    lista->v[i]=NULL;
}
void adauga(proces *p,List *lista)
{
  for(int i=0;i<N;i++)
    {
      if(i==p->prio-1)
	{
	  lista->v[i]=push(p,lista->v[i]);
	  return;
	}
    }
}
proces *extrage(List *lista)
{
  for(int i=N-1;i>=0;i--)
    {
      if(lista->v[i]!=NULL)
	return pop(&lista->v[i]);
    }
  return NULL;
}
void afisare(List *lista)
{
  for(int i=0;i<N;i++)
    {
      printf("P%d - ",i+1);
      display(lista->v[i]);
    }
  printf("\n");
}




//stiva
proces *stiva=NULL;
proces *add_stiva(int id,int prio,proces *stiva)
{
  return make(id,prio,stiva);
}

void terminare_proces(List *lista,proces **stiva)
{
  proces *p=NULL;
  while((p=pop(stiva))!=NULL)
    {
      adauga(p,lista);
    }
}
/*
-pt lista sec s-a folosit o lista simplu inlantuita(dinamica),adaugarea O(1),scoaterea O(1)
s a ales pentru a fi eficient
-pt lista principala s-a folosit un tablou,adaugarea O(1),scoaterea O(1)
s-a ales pt a fi eficient
*/
int main()
{
  List lista;
  initializare(&lista);
  
  proces *p1=make(11,7,NULL);
  proces *p2=make(12,7,NULL);
  proces *p3=make(3,2,NULL);
  proces *p4=make(1,1,NULL);
  proces *p5=make(2,1,NULL);

  adauga(p1,&lista);
  adauga(p2,&lista);
  adauga(p3,&lista);
  adauga(p4,&lista);
  adauga(p5,&lista);

  afisare(&lista);

  stiva=add_stiva(4,2,stiva);
  stiva=add_stiva(3,1,stiva);
  printf("Stiva:");
  display(stiva);

  terminare_proces(&lista,&stiva);
  afisare(&lista);
  printf("Stiva:");
  display(stiva);

  proces *p8=extrage(&lista);
  printf("elem scos:(proc %d Prio:%d)\n",p8->id,p8->prio);
  afisare(&lista);
  return 0;
}
