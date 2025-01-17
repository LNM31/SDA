#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50
typedef struct gg{
  char cod[9];
  int stoc;
  struct gg *next;
}produs;
typedef struct {
  char nume[36];
  produs *l;
}magazin;

typedef struct {
  magazin  v[N];
  int size;
}List;




//lista sec
produs *make(char *cod,int stoc,produs *elem)
{
  produs *e=(produs *)malloc(sizeof(produs));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  strcpy(e->cod,cod);
  e->stoc=stoc;
  e->next=elem;
  return e;
}
produs *adauga(char *cod,int stoc,produs *lista)
{
  if(lista==NULL)
    return make(cod,stoc,NULL);
  produs *st=NULL,*p=lista;
  for(;p!=NULL;p=p->next)
    {
      if(strtol(cod,NULL,10)<strtol(p->cod,NULL,10))
	{
	  if(st==NULL)
	    {
	      return make(cod,stoc,lista);
	    }
	  else
	    {
	      st->next=make(cod,stoc,p);
	      return lista;
	    }
	}
      if(p->next==NULL)
	{
	  p->next=make(cod,stoc,NULL);
	  return lista;
	}
      st=p;
    }
  return lista;
}
void display(produs *lista)
{
  produs *p=lista;
  while(p!=NULL)
    {
      printf("%s %d\n",p->cod,p->stoc);
      p=p->next;
    }
  printf("\n");
}
void free_list(produs *lista)
{
  produs *p=lista,*aux=NULL;
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
  lista->size=0;
}
void adauga_magazin(char *nume,produs *p,List *lista)
{
  strcpy(lista->v[lista->size].nume,nume);
  lista->v[lista->size++].l=p;
}
void afisare(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      printf("Nume:%s\n",lista->v[i].nume);
      display(lista->v[i].l);
    }
  printf("\n");
}

void modificare_stoc(char *nume,char *cod,int stoc_nou,List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      if(strcmp(lista->v[i].nume,nume)==0)
	{
	  produs *p=lista->v[i].l;
	  while(p!=NULL)
	    {
	      if(strcmp(p->cod,cod)==0)
		p->stoc=stoc_nou;
	      p=p->next;
	    }
	  return;
	}
    }
    
}
void FREE(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      free_list(lista->v[i].l);
    }
}
int main()
{
  produs *p1=NULL;
  p1=adauga("3",30,p1);
  p1=adauga("1",10,p1);
  p1=adauga("5",50,p1);
  p1=adauga("2",20,p1);
  p1=adauga("4",40,p1);

  produs *p2=NULL;
  p2=adauga("3",30,p2);
  p2=adauga("1",10,p2);
  p2=adauga("5",50,p2);
  p2=adauga("2",20,p2);
  p2=adauga("4",40,p2);

  produs *p3=NULL;
  p3=adauga("3",30,p3);
  p3=adauga("1",10,p3);
  p3=adauga("5",50,p3);
  p3=adauga("2",20,p3);
  p3=adauga("4",40,p3);

  List lista;
  initializare(&lista);
  adauga_magazin("N1",p1,&lista);
  adauga_magazin("N2",p2,&lista);
  adauga_magazin("N3",p3,&lista);
  afisare(&lista);

  modificare_stoc("N2","4",100,&lista);
  afisare(&lista);
  FREE(&lista);
  return 0;
}
