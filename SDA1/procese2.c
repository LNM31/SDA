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

typedef struct{
  proces *l;
}stiva;


void init_coada(fifo *c)
{
  c->prim=NULL;
  c->ultim=NULL;
}
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
void adauga(proces *p,fifo *c)
{
  if(c->prim==NULL)
    {
      c->prim=p;
      p->next=NULL;
      c->ultim=p;
    }
  else
    {
      c->ultim->next=p;
      p->next=NULL;
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
void adauga_lista_princi(proces *p,List *lista)
{
  adauga(p,&lista->v[p->prio-1]);
}
void afisare(List *lista)
{
  for(int i=0;i<N;i++)
    {
      printf("P%d - ",i+1);
      display(lista->v[i].prim);
    }
}

void adaug_stiva(proces *p,stiva *s)
{
  if(s->l==NULL)
    {
      p->next=NULL;
      s->l=p;
    }
  else
    {
      p->next=s->l;
      s->l=p;
    }
}
proces *stergere(stiva *s)
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
      adauga_lista_princi(stergere(s),lista);
    }
}

/*
  -avem 4 structuri de date alese:
    -proces,este un nod dintr o lista simplu inlantuita
    -fifo,reprezand o coada FIFO care are ca elem un proces
      -adaugarea se face la sfarsit prin O(1),deoarece se retine ultimul nod
    -List,reprezinta cele 8 cozi de prioriate,de tip fifo,adaugarea este O(1)*O(1)=O(1)
    -stiva,este o stiva care reprezinta o lista simplu inlantuita cu adaugarea si
    stergerea la inceput,ambele O(1)

    daca presupunem ca stiva are n elemente,care toate se introduc in lista de prio
    atunci o sa avem o complexitate de O(n)

    In concluzie, complexitatea algoritmului este O(n)
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

  adauga_lista_princi(p1,&lista);
  adauga_lista_princi(p2,&lista);
  adauga_lista_princi(p3,&lista);
  adauga_lista_princi(p4,&lista);
  adauga_lista_princi(p5,&lista);

  afisare(&lista);

  stiva s;
  s.l=NULL;
  adaug_stiva(p7,&s);
  adaug_stiva(p6,&s);

  printf("Stiva:");
  display(s.l);
  printf("\n");
  terminare_proces(&s,&lista);
  
  afisare(&lista);
  printf("\nStiva:");
  display(s.l);
  return 0;
}
