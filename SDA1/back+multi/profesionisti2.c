#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
typedef struct gg{
  int id;
  char nume[36],ocupatie[36];
  char v[N][36];
  int size;
  struct gg*next;
}persoana;

persoana *make(int id,char *nume,char *ocupatie,persoana *elem)
{
  persoana *p=(persoana *)malloc(sizeof(persoana));
  if(p==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  p->id=id;
  strcpy(p->nume,nume);
  strcpy(p->ocupatie,ocupatie);
  p->size=0;
  p->next=elem;
  return p;
}
void adauga_conexiune(persoana *p,persoana *adaug)
{
  strcpy(p->v[p->size++],adaug->nume);
}
void display(persoana *lista)
{
  persoana *p=lista;
  while(p!=NULL)
    {
      printf("(%d %s %s leg:",p->id,p->nume,p->ocupatie);
      for(int i=0;i<p->size;i++)
	{
	  printf("%s ",p->v[i]);
	}
      printf(")\n");
      p=p->next;
    }
}
persoana *add_back(int id,char *nume,char *ocupatie,persoana *lista)
{
  if(lista==NULL)
    return make(id,nume,ocupatie,NULL);
  persoana *q=lista;
  for(;q->next!=NULL;q=q->next);
  q->next=make(id,nume,ocupatie,NULL);
  return lista;
}

int main()
{
  persoana *p1=make(1,"N1","O1");
  persoana *p2=make(2,"N2","O2");
  persoana *p3=make(3,"N3","O3");
  persoana *p4=make(4,"N4","O4");
  persoana *p5=make(5,"N5","O5");

  adauga_conexiune(p1,p2);
  adauga_conexiune(p1,p3);
  adauga_conexiune(p2,p4);
  adauga_conexiune(p2,p5);
  adauga_conexiune(p5,p1);
  adauga_conexiune(p3,p1);
  adauga_conexiune(p3,p5);

  nod *lista=NULL;
  lista=add_back(p1,lista);
  lista=add_back(p2,lista);
  lista=add_back(p3,lista);
  lista=add_back(p4,lista);
  lista=add_back(p5,lista);
  afisare(lista);
  return 0;
}
