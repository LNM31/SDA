#include<stdio.h>
#include<stdlib.h>
#define N 8
typedef struct gg{
  int id,prio;
  long mom;
  struct gg *next;
}even;

typedef struct {
  even *v[8];
}List;

typedef struct {
  even *prim;
  even *ultim;
}fifo;


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
even *adauga(even *add,even *lista)
{
  if(lista==NULL)
    {
      add->next=NULL;
      return add;
    }
  even *st=NULL,*p=lista;
  for(;p!=NULL;p=p->next)
    {
      if(add->mom<p->mom)
	{
	  if(st==NULL)
	    {
	      add->next=p;
	      return add;
	    }
	  else
	    {
	      st->next=add;
	      add->next=p;
	      return lista;
	    }
	}
      else if(p->next==NULL)
	{
	  p->next=add;
	  add->next=NULL;
	  return lista;
	}
      st=p;
    }
  return lista;
}
even *scoate(even **lista)
{
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


//lista princi
void init(List *lista)
{
  for(int i=0;i<8;i++)
    lista->v[i]=NULL;
}
void adauga_lista(even *p,List *lista)
{
  lista->v[p->prio-1]=adauga(p,lista->v[p->prio-1]);
}
even *scoate_lista(List *lista)
{
  for(int i=7;i>=0;i--)
    {
      if(lista->v[i]!=NULL)
	{
	  return scoate(&lista->v[i]);
	}
    }
  return NULL;
}
void afisare(const List *lista)
{
  for(int i=0;i<8;i++)
    {
      printf("P%d - ",i+1);
      display(lista->v[i]);
    }
  printf("\n");
}

void init_coada(fifo *c)
{
  c->prim=NULL;
  c->ultim=NULL;
}
void push(even *p,fifo *c)
{
  if(c->prim==NULL)
    {
      p->next=NULL;
      c->prim=p;
      c->ultim=p;
    }
  else
    {
      c->ultim->next=p;
      p->next=NULL;
      c->ultim=p;
    }
}

/*
-avem 3 structuri de date:
   -lista secundara formata dintr o lista simplu inlantuita
   -lista principala formata dintr un vector static de size 8,avem 8 prioritati
   -coada fifo
-aduagare lista sec,O(n), dc se face ordonata,stergere O(1),dc se sterge capul listei
-adaugare lista princi,avem O(1)*O(n)=O(n),stergere O(1)
-adaugare coada fifo,O(1),dc retinem ultimul elem,stergere O(1),dc stergem primul elem
   
*/
int main()
{

  even *e1=make(1,1,10,NULL);
  even *e2=make(2,1,20,NULL);
  even *e3=make(3,2,15,NULL);
  even *e4=make(11,7,20,NULL);
  even *e5=make(12,7,40,NULL);

  List lista;
  init(&lista);
  adauga_lista(e5,&lista);
  adauga_lista(e2,&lista);
  adauga_lista(e3,&lista);
  adauga_lista(e1,&lista);
  adauga_lista(e4,&lista);
  afisare(&lista);

  fifo c;
  init_coada(&c);
  even *aux=NULL;
  while((aux=scoate_lista(&lista))!=NULL)
    {
      push(aux,&c);
    }
  afisare(&lista);
  display(c.prim);
  return 0;
}
