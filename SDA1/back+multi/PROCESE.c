#include<stdio.h>
#include<stdlib.h>
#define N 8
typedef struct gg{
  int id,prio;
  struct gg *next;
}proces;

typedef struct {
  proces *v[N];
}List;

typedef struct{
  proces *l;
}stiva;

//lista sec
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
proces *add_back(proces *pro,proces *lista)
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
proces *add_front(proces *p,proces *lista)
{
  p->next=lista;
  return p;
}
proces *stergere(proces **lista)
{
  if(*lista==NULL)
    return NULL;
  proces *rez=*lista;
  *lista=(*lista)->next;
  rez->next=NULL;
  return rez;
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
void free_list(proces *lista)
{
  proces *p=lista,*aux=NULL;
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
    {
      lista->v[i]=NULL;
    }
}
void adaugare_proces(proces *p,List *lista)
{
  lista->v[p->prio-1]=add_back(p,lista->v[p->prio-1]);
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



//stiva
void init_stiva(stiva *s)
{
  s->l=NULL;
}
void adauga_in_stiva(proces *p,stiva *s)
{
  s->l=add_front(p,s->l);
}

void eliminare_proces(stiva *s,List *lista)
{
  proces *p=NULL;
  while(s->l!=NULL)
    {
      p=stergere(&s->l);
      adaugare_proces(p,lista);
    }
}

/*
avem 3 structuri de date implementate:
  -proces:reprezinta un nod dintr o lista simplu inlantuita,reprezentand coada FIFO aferenta fiecarei
  prioritati
  -List-reprezinta lista propriu-zisa de prioritati,in numar de 8
  -stiva-reprezinta stiva care este implentata cu o lista simplu inlantuita de procese

  Complexitati:
  -pentru lista simplu inlantuita:adaugarea spate-O(n),adaugarea_fata-O(1),stergerea O(1)
  -pentru lista de prioritati,adaugarea este O(n)
  -pentru stiva:adaugare si stergera sunt O(1)
  -functia eliminare_proces are O(n)

  In final,Complezitatea totala a algoritmului este O(n)
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
  initializare(&lista);
  adaugare_proces(p1,&lista);
  adaugare_proces(p2,&lista);
  adaugare_proces(p3,&lista);
  adaugare_proces(p4,&lista);
  adaugare_proces(p5,&lista);
  afisare(&lista);

  stiva s;
  init_stiva(&s);
  adauga_in_stiva(p7,&s);
  adauga_in_stiva(p6,&s);
  printf("Stiva:");
  display(s.l);

  printf("\n");
  eliminare_proces(&s,&lista);
  afisare(&lista);
  printf("Stiva:");
  display(s.l);

  FREE(&lista);
  free_list(s.l);
  return 0;
}
