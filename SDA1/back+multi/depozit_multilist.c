#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50


typedef struct gg{
  char cod[9];
  struct gg *next;
}palete;
typedef struct{
  char nume[32];
  palete *l;
}depozit;


typedef struct {
  depozit v[N];
  int size;
}List;


void initializare(List *lista)
{
  for(int i=0;i<N;i++)
    {
      strcpy(lista->v[i].nume,"");
      lista->v[i].l=NULL;
    }
  lista->size=0;
}

palete *make(char *cod,palete *elem)
{
  palete *nou=(palete *)malloc(sizeof(palete));
  if(nou==NULL)
    {
      perror("error aloc");
      exit(-1);
    }
  strcpy(nou->cod,cod);
  nou->next=elem;
  return nou;
}
palete *add_back(char *cod,palete *lista)
{
  if(lista==NULL)
    return make(cod,NULL);
  palete *p=lista;
  for(;p->next!=NULL;p=p->next);
  p->next=make(cod,NULL);
  return lista;
}
void display(palete *lista)
{
  palete *p=lista;
  while(p!=NULL)
    {
      printf("%s ",p->cod);
      p=p->next;
    }
  printf("\n");
}
palete *adauga(char *cod,palete *lista)
{
  palete *nou=make(cod,NULL);
  if(lista==NULL)
    return nou;
  if(strtol(nou->cod,NULL,10)<strtol(lista->cod,NULL,10))
    {
      nou->next=lista;
      return nou;
    }
  palete *st=NULL;
  for(palete *p=lista;p!=NULL;p=p->next)
    {
      if(strtol(nou->cod,NULL,10)<strtol(p->cod,NULL,10))
	{
	  st->next=nou;
	  nou->next=p;
	  return lista;
	}
      st=p;
    }
  return add_back(cod,lista);
}

void adauga_depozit(char *nume,palete *l,List *lista)
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
palete *stergere(char *cod,palete *lista)
{
  palete *st=NULL,*p=lista,*dr=NULL;
  for(;p!=NULL;p=p->next)
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
void stergere_totala(char *cod,List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      lista->v[i].l=stergere(cod,lista->v[i].l);
    }
}
int main()
{
  List lista;
  initializare(&lista);
  palete *l1=NULL;
  l1=adauga("8",l1);
  l1=adauga("1",l1);
  l1=adauga("1",l1);
  l1=adauga("4",l1);
  l1=adauga("9",l1);
  l1=adauga("6",l1);
  l1=adauga("0",l1);
  //display(l1);

  palete *l2=NULL;
  l2=adauga("4",l2);
  l2=adauga("8",l2);
  l2=adauga("5",l2);
  l2=adauga("1",l2);
  l2=adauga("7",l2);
  l2=adauga("1",l2);
  l2=adauga("9",l2);
  //display(l2);

  palete *l3=NULL;
  l3=adauga("4",l3);
  l3=adauga("1",l3);
  l3=adauga("3",l3);
  l3=adauga("2",l3);
  l3=adauga("2",l3);
  l3=adauga("0",l3);
  l3=adauga("4",l3);
  //display(l3);

  adauga_depozit("DEP1",l1,&lista);
  adauga_depozit("DEP2",l2,&lista);
  adauga_depozit("DEP3",l3,&lista);
  afisare(&lista);
  stergere_totala("4",&lista);
  afisare(&lista);
  return 0;
}
/*
-complexitatea functiei de stergere pentru fiecare depozit este O(n),fiind efiecient
deoarece stergerea se face in O(1) odata gasit nodul,in final fiinf O(n) dc lista
contine n noduri
-am ales ca lista principala(depozite) sa fie de tip tablou adaugarea fiind O(1)
,iar lista sec(palete) sa
fie de tip lista simplu inlantiuita deoarece adaugarea este O(n)
*/
