#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
typedef struct ff{
  int id;
  char nume[36],ocupatie[36];
  char v[N][36];
  int size;
}persoana;

typedef struct gg{
  persoana *per;
  struct gg *next;
}nod;



//lista sec
persoana *creare_persoana(int id,char *nume,char *ocupatie)
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
  return p;
}
void adauga_conexiune(persoana *p,persoana *adaug)
{
  strcpy(p->v[p->size++],adaug->nume);
}
void display(persoana *per)
{
  printf("(%d %s %s leg:",per->id,per->nume,per->ocupatie);
  for(int i=0;i<per->size;i++)
    {
      printf("%s ",per->v[i]);
    }
  printf(")\n");
}






//lista princip
nod *make(persoana *p,nod *elem)
{
  nod *e=(nod *)malloc(sizeof(nod));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  e->per=p;
  e->next=elem;
  return e;
}
nod *add_back(persoana *p,nod *lista)
{
  if(lista==NULL)
    return make(p,NULL);
  nod *q=lista;
  for(;q->next!=NULL;q=q->next);
  q->next=make(p,NULL);
  return lista;
}
void afisare(nod *lista)
{
  nod *q=lista;
  while(q!=NULL)
    {
      display(q->per);
      q=q->next;
    }
  printf("\n");
}


/*
doua lista:una lista formata din tablou,alta lista simplu inlantuita
-la lista secundara toate functiile sunt O(1) dc se adauga la spate
-la a doua adaugarea se face la fel in O(1),afisarea este O(n)
 */
int main()
{
  persoana *p1=creare_persoana(1,"N1","O1");
  persoana *p2=creare_persoana(2,"N2","O2");
  persoana *p3=creare_persoana(3,"N3","O3");
  persoana *p4=creare_persoana(4,"N4","O4");
  persoana *p5=creare_persoana(5,"N5","O5");

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
