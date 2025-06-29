#include<stdio.h>
#include<stdlib.h>
#define N 8
typedef struct gg{
  int id,prio;
  struct gg *next;
}proces;

typedef struct {
  proces *prim;
  proces *ultim;
}fifo;

typedef struct{
  fifo v[N];
}List;

typedef struct {
  proces *l;
}stiva;


//coada
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
void adauga_coada(proces *p,fifo *c)
{
  if(c->prim==NULL)
    {
      p->next=NULL;
      c->prim=p;
      c->ultim=p;
    }
  else
    {
      p->next=NULL;
      c->ultim->next=p;
      c->ultim=p;
    }
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

//lista princi
void init(List *lista)
{
  for(int i=0;i<N;i++)
    {
      lista->v[i].prim=NULL;
      lista->v[i].ultim=NULL;
    }
}
void adauga_lista(proces *p,List *lista)
{
  adauga_coada(p,&lista->v[p->prio-1]);
}
void afisare(const List *lista)
{
  for(int i=0;i<N;i++)
    {
      printf("P%d - ",i+1);
      display(lista->v[i].prim);
    }
  printf("\n");
}

//stiva
void init_stiva(stiva *s)
{
  s->l=NULL;
}
void adauga_stiva(proces *p,stiva *s)
{
  p->next=s->l;
  s->l=p;
}
proces *scoate_stiva(stiva *s)
{
  proces *p=s->l;
  s->l=s->l->next;
  p->next=NULL;
  return p;
}
void terminare_proces(stiva *s,List *lista)
{
  while(s->l!=NULL)
    {
      adauga_lista(scoate_stiva(s),lista);
    }
}
/*
am folosit 4 structuri de date:
    -proces ,care reprezinta un nod alocat dinamic avand datele procesului
    -fifo,fiind o coada,care retine primul si ultimul element,rezulta adaugarea si
    stergere o(1)
    -List,care reprezinta structura multilista,avand 8 cozi de tip fifo,dc sunt 8 priori
    adaugarea si stergerea se fac in O(1)
    -stiva,cu adaugarea si stergerea o(1)
-rezulta ca algoritmul are o complezitate liniara O(n),deoarece presupunem ca evem n
procese in stiva
*/
int main()
{
  proces *p1=make(1,1,NULL); 
  proces *p2=make(2,1,NULL);
  proces *p3=make(3,2,NULL);
  proces *p4=make(11,7,NULL);
  proces *p5=make(12,7,NULL);
  proces *p6=make(3,1,NULL);
  proces *p7=make(4,2,NULL);

  List lista;
  init(&lista);
  adauga_lista(p1,&lista);
  adauga_lista(p2,&lista);
  adauga_lista(p3,&lista);
  adauga_lista(p4,&lista);
  adauga_lista(p5,&lista);
  afisare(&lista);

  stiva s;
  init_stiva(&s);
  adauga_stiva(p7,&s);
  adauga_stiva(p6,&s);
  printf("Stiva: ");
  display(s.l);
  printf("\n");

  terminare_proces(&s,&lista);
  afisare(&lista);
  printf("Stiva: ");
  display(s.l);
  return 0;
}
