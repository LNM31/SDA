#include<stdio.h>
#include<stdlib.h>
typedef struct gg{  //lista secundara
  int id,prio;
  long moment;
  struct gg *next;
}even;
typedef struct {
  even *v[8];
  int size;
}List;

even *coada=NULL;

void initializare(List *lista)
{
  for(int i=0;i<8;i++)
    lista->v[i]=NULL;
  lista->size=8;
}
even *make(int id,int prio,long moment,even *elem)
{
  even *nou=(even *)malloc(sizeof(even));
  if(nou==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  nou->id=id;
  nou->prio=prio;
  nou->moment=moment;
  nou->next=elem;
  return nou;
}
even *add_back(even *elem,even *lista)
{
  if(lista==NULL)
    return elem;
  even *p=NULL;
  for(p=lista;p->next!=NULL;p=p->next);
  p->next=elem;
  return lista;
}
even *adauga(int id,int prio,long moment,even *lista)
{
  if(lista==NULL)
    return make(id,prio,moment,NULL);
  even *p=NULL,*st=NULL,*nou=make(id,prio,moment,NULL);
  if(moment<lista->moment)
    {
      nou->next=lista;
      return nou;
    }
  for(p=lista;p!=NULL;p=p->next)
    {
      if(moment<p->moment)
	{
	  st->next=nou;
	  nou->next=p;
	  return lista;
	}
      if(p->next==NULL)
	{
	  p->next=nou;
	  return lista;
	}
      st=p;
    }
  return lista;
}
void display(even *lista)
{
  even *p=lista;
  while(p!=NULL)
    {
      printf("(e%d MOM:%ld) ",p->id,p->moment);
      p=p->next;
    }
  printf("\n");
}



void adauga_lista_principala(int id,int prio,long moment,List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      if(prio==i+1)
	{
	  lista->v[i]=adauga(id,prio,moment,lista->v[i]);
	  break;
	}
    }
}
void afisare(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      printf("P%d - ",i+1);
      display(lista->v[i]);
    }
  printf("\n");
}
void deservire(List *lista)
{
  even *rez=NULL;
  for(int i=lista->size-1;i>=0;i--)
    {
      if(lista->v[i]!=NULL)
	{
	  rez=lista->v[i];
	  lista->v[i]=lista->v[i]->next;
	  rez->next=NULL;
	  coada=add_back(rez,coada);
	  break;
	}
    }
}
/*
-algoritmul consta in doua liste,una principala care este formata dintr un tablou cu
8 elemente reprezentand prioritatiile,adaugarea se face in O(1)in lista propriu zisa,
cea dea doua lista secundara este formata dintr o lista simplu inlantuita ordonata
adaugarea in aceasta este O(n)....(etc)
*/
int main()
{
  //prioritatiile in vector sunt  7 6 5 4 3 2 1 0
  List lista;
  initializare(&lista);
  adauga_lista_principala(1,1,10,&lista);
  adauga_lista_principala(2,1,20,&lista);
  adauga_lista_principala(3,2,15,&lista);
  adauga_lista_principala(11,7,20,&lista);
  adauga_lista_principala(12,7,40,&lista);
  afisare(&lista);

  deservire(&lista);
  printf("DUPA:\n");
  afisare(&lista);
  printf("COADA:");
  display(coada);
  
  return 0;
}
