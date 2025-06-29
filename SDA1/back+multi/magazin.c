#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 500
typedef struct gg{
  char cod[9];
  struct gg *next;
}produs;
typedef struct {
  char nume[32];
  produs *l;
}magazin;


typedef struct{
  magazin v[N];
  int size;
}List;

void initializare(List *lista)
{
  for(int i=0;i<N;i++)
    {
      lista->v[i].l=NULL;
      strcpy(lista->v[i].nume,"");
    }
  lista->size=0;
}
//lista sec->
produs *make(char *cod,produs *elem)
{
  produs *nou=(produs *)malloc(sizeof(produs));
  if(nou==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  strcpy(nou->cod,cod);
  nou->next=elem;
  return nou;
}
produs *adauga(char *cod,produs *lista)
{
  if(lista==NULL)
    return make(cod,NULL);
  if(strtol(cod,NULL,10)<strtol(lista->cod,NULL,10))
    return make(cod,lista);
  produs *st=NULL,*p=lista;
  for(;p!=NULL;p=p->next)
    {
      if(strtol(cod,NULL,10)<strtol(p->cod,NULL,10))
	{
	  st->next=make(cod,p);
	  return lista;
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
void display(produs *lista)
{
  produs *p=lista;
  while(p!=NULL)
    {
      printf("%ld ",strtol(p->cod,NULL,10));
      p=p->next;
    }
  printf("\n");
}
produs *stergere(char *cod,produs *lista)
{
  produs *st=NULL,*p=NULL,*dr=NULL;
  for(p=lista;p!=NULL;p=p->next)
    {
      dr=p->next;
      if(strcmp(cod,p->cod)==0)
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
void adaugare_lista_mare(char *nume,produs *l,List *lista)
{
  strcpy(lista->v[lista->size].nume,nume);
  lista->v[lista->size].l=l;
  lista->size++;
}
void afisare(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      printf("NUME:%s\n",lista->v[i].nume);
      display(lista->v[i].l);
    }
  printf("\n");
}
void stergere_totala(char *cod,List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      lista->v[i].l=stergere(cod,lista->v[i].l);
    }
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
int main()
{
  List lista;
  initializare(&lista);
  produs *l1=NULL;
  l1=adauga("3",l1);
  l1=adauga("1",l1);
  l1=adauga("6",l1);
  l1=adauga("4",l1);
  l1=adauga("5",l1);
  l1=adauga("0",l1);

  produs *l2=NULL;
  l2=adauga("3",l2);
  l2=adauga("1",l2);
  l2=adauga("6",l2);
  l2=adauga("4",l2);
  l2=adauga("5",l2);
  l2=adauga("0",l2);

  produs *l3=NULL;
  l3=adauga("3",l3);
  l3=adauga("1",l3);
  l3=adauga("6",l3);
  l3=adauga("4",l3);
  l3=adauga("5",l3);
  l3=adauga("0",l3);
  
  adaugare_lista_mare("magazin1",l1,&lista);
  adaugare_lista_mare("magazin2",l2,&lista);
  adaugare_lista_mare("magazin3",l3,&lista);
  afisare(&lista);
  stergere_totala("3",&lista);
  afisare(&lista);

  for(int i=0;i<lista.size;i++)
    free_list(lista.v[i].l);
  return 0;
}
