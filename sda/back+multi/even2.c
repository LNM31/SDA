#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 8
typedef struct gg{
  int id,prio;
  long mom;
  struct gg *next;
}even;

typedef struct {
  even *v[N];
}List;

typedef struct {
  even *prim;
}coada;


//lista sec
even *make(int id,int prio,long mom,even *elem)
{
  even *e=(even *)malloc(sizeof(even));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  e->id=id;
  e->prio=prio;
  e->mom=mom;
  e->next=elem;
  return e;
}
even *adauga(int id,int prio,long mom,even *lista)
{
  if(lista==NULL)
    return make(id,prio,mom,NULL);
  even *st=NULL,*p=lista;
  for(;p!=NULL;p=p->next)
    {
      if(mom<p->mom)
	{
	  if(st==NULL)
	    {
	      return make(id,prio,mom,lista);
	    }
	  else
	    {
	      even *nou=make(id,prio,mom,p);
	      st->next=nou;
	      return lista;
	    }
	}
      if(p->next==NULL)
	{
	  p->next=make(id,prio,mom,NULL);
	  return lista;
	}
      st=p;
    }
  return lista;
}
even *stergere(even **lista)
{
  if(*lista==NULL)
    return NULL;
  even *rez=*lista;
  *lista=(*lista)->next;
  rez->next=NULL;
  return rez;
}
void display(even *lista)
{
  even *p=lista;
  while(p!=NULL)
    {
      printf("(e%d %ld) ",p->id,p->mom);
      p=p->next;
    }
  printf("\n");
}
void free_list(even *lista)
{
  even *p=lista,*aux=NULL;
  while(p!=NULL)
    {
      aux=p;
      p=p->next;
      free(aux);
    }
}




//lista princi
void initializare(List *lista)
{
  for(int i=0;i<N;i++)
    lista->v[i]=NULL;
}
void adaugare_even(int id,int prio,long mom,List *lista)
{
  lista->v[prio-1]=adauga(id,prio,mom,lista->v[prio-1]);
}
even *deservire_even(List *lista)
{
  even *rez=NULL;
  for(int i=N-1;i>=0;i--)
    {
      if(lista->v[i]!=NULL)
	{
	  rez=stergere(&lista->v[i]);
	  return rez;
	}
    }
  return rez;
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
void FREE(List *lista)
{
  for(int i=0;i<N;i++)
    {
      free_list(lista->v[i]);
    }
}




//coada
even *add_back(even *e,even *lista)
{
  if(lista==NULL)
    return e;
  even *p=lista;
  for(;p->next!=NULL;p=p->next);
  p->next=e;
  e->next=NULL;
  return lista;
}
void adauga_in_coada(even *e,coada *c)
{
  c->prim=add_back(e,c->prim);
}
int main()
{
  List lista;
  initializare(&lista);
  adaugare_even(2,1,20,&lista);
  adaugare_even(12,7,40,&lista);
  adaugare_even(3,2,15,&lista);
  adaugare_even(1,1,10,&lista);
  adaugare_even(11,7,20,&lista);

  afisare(&lista);
  coada c;
  c.prim=NULL;
  adauga_in_coada(deservire_even(&lista),&c);
  afisare(&lista);
  display(c.prim);

  adauga_in_coada(deservire_even(&lista),&c);
  afisare(&lista);
  display(c.prim);

  FREE(&lista);
  free_list(c.prim);

  
  return 0;
}
