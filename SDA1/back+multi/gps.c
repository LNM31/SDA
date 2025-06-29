#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
typedef struct gg{
  char cod[9];
  struct gg *next;
}gps;
typedef struct{
  char nume[36];
  gps *l;
}firma;

typedef struct{
  firma v[N];
  int size;
}List;


//lista sec
gps *make(char *cod,gps *elem)
{
  gps *e=(gps *)malloc(sizeof(gps));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  strcpy(e->cod,cod);
  e->next=elem;
  return e;
}
gps *adauga(char *cod,gps *lista)
{
  if(lista==NULL)
    return make(cod,NULL);
  gps *st=NULL,*p=lista;
  for(;p!=NULL;p=p->next)
    {
      if(strtol(cod,NULL,10)<strtol(p->cod,NULL,10))
	{
	  if(st==NULL)
	    return make(cod,lista);
	  else
	    {
	      gps *nou=make(cod,p);
	      st->next=nou;
	      return lista;
	    }
	}
      if(p->next==NULL)
	{
	  p->next=make(cod,NULL);
	  return lista;
	}
      st=p;
    }
  return lista;
}
gps *stergere(char *cod,gps *lista)
{
  gps *st=NULL,*p=lista,*dr=NULL;
  for(;p!=NULL;p=p->next)
    {
      dr=p->next;
      if(strcmp(p->cod,cod)==0)
	{
	  if(st==NULL)
	    {
	      lista=lista->next;
	      free(p);
	      return lista;
	    }
	  else
	    {
	      st->next=dr;
	      free(p);
	      return lista;
	    }
	}
      st=p;
    }
  return lista;
}
void display(gps *lista)
{
  gps *p=lista;
  while(p!=NULL)
    {
      printf("%s ",p->cod);
      p=p->next;
    }
  printf("\n");
}
void free_list(gps *lista)
{
  gps *p=lista,*aux=NULL;
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
void adauga_firma(char *nume,gps *g,List *lista)
{
  strcpy(lista->v[lista->size].nume,nume);
  lista->v[lista->size++].l=g;
}
void afisare(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      printf("\n%s\n",lista->v[i].nume);
      display(lista->v[i].l);
    }
  printf("\n");
}
void FREE(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      free_list(lista->v[i].l);
    }
}
void eliminare(char *cod,List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      lista->v[i].l=stergere(cod,lista->v[i].l);
    }
}
int main()
{
  gps *g1=NULL;
  g1=adauga("3",g1);
  g1=adauga("1",g1);
  g1=adauga("5",g1);
  g1=adauga("2",g1);
  g1=adauga("4",g1);
  g1=adauga("6",g1);

  gps *g2=NULL;
  g2=adauga("4",g2);
  g2=adauga("2",g2);
  g2=adauga("6",g2);
  g2=adauga("3",g2);
  g2=adauga("5",g2);
  g2=adauga("7",g2);

  gps *g3=NULL;
  g3=adauga("5",g3);
  g3=adauga("3",g3);
  g3=adauga("7",g3);
  g3=adauga("4",g3);
  g3=adauga("6",g3);
  g3=adauga("8",g3);

  List lista;
  initializare(&lista);
  adauga_firma("N1",g1,&lista);
  adauga_firma("N2",g2,&lista);
  adauga_firma("N3",g3,&lista);
  afisare(&lista);
  eliminare("5",&lista);
  afisare(&lista);
  FREE(&lista);
  return 0;
}
