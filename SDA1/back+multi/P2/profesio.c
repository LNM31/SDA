#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
typedef struct {
  char text[101];
  int id;
}recom;


typedef struct{
  int id;
  char nume[36],ocupatie[36];
  recom v[N];
  int size;
}persoana;

typedef struct gg{
  persoana *p;
  struct gg *next;
}nod;



//lista sec
persoana *creare_pers(int id,char *nume,char *ocupatie)
{
  persoana *e=(persoana *)malloc(sizeof(persoana));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  e->id=id;
  strcpy(e->nume,nume);
  strcpy(e->ocupatie,ocupatie);
  e->size=0;
  return e;
}
void adaugare_rec(persoana *p,char *text,persoana *adauga)
{
  strcpy(p->v[p->size].text,text);
  p->v[p->size++].id=adauga->id;
}
void display(persoana *per)
{
  printf("%d %s %s REC: ",per->id,per->nume,per->ocupatie);
  for(int i=0;i<per->size;i++)
    {
      printf("id:%d %s ",per->v[i].id,per->v[i].text);
    }
  printf("\n");
}


//lista princi
nod *make(persoana *p,nod *elem)
{
  nod *e=(nod *)malloc(sizeof(nod));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  e->p=p;
  e->next=elem;
  return e;
}
nod *add_back(persoana *per,nod *lista)
{
  if(lista==NULL)
    return make(per,NULL);
  nod *p=lista;
  for(;p->next!=NULL;p=p->next);
  p->next=make(per,NULL);
  return lista;
}
void afisare(nod *lista)
{
  nod *q=lista;
  while(q!=NULL)
    {
      display(q->p);
      q=q->next;
    }
  printf("\n");
}
void FREE(nod *lista)
{
  nod *q=lista,*aux=NULL;
  while(q!=NULL)
    {
      aux=q;
      q=q->next;
      free(aux->p);
      free(aux);
    }
}
void cautare(persoana **tab,nod *lista)
{
  nod *q=lista;
  int i=0;
  while(q!=NULL)
    {
      if(q->p->size>10)
	{
	  if(i<3)
	    {
	      tab[i++]=q->p;
	    }
	  else break;
	}
      q=q->next;
    }
}
int main()
{
  persoana *p1=creare_pers(1,"N1","O1");
  persoana *p2=creare_pers(2,"N2","O2");
  persoana *p3=creare_pers(3,"N3","O3");
  persoana *p4=creare_pers(4,"N4","O4");
  persoana *p5=creare_pers(5,"N5","O5");

  adaugare_rec(p1,"T1",p2);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p2,"T3",p4);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p5,"T5",p1);
  adaugare_rec(p3,"T6",p1);
  adaugare_rec(p3,"T7",p5);
  
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);
  adaugare_rec(p3,"T7",p5);

  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);
  adaugare_rec(p1,"T2",p3);

  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);
  adaugare_rec(p2,"T4",p5);

  nod *lista=NULL;
  lista=add_back(p1,lista);
  lista=add_back(p2,lista);
  lista=add_back(p3,lista);
  lista=add_back(p4,lista);
  lista=add_back(p5,lista);

  afisare(lista);

  persoana *tab[3];
  cautare(tab,lista);
  display(tab[0]);
  display(tab[1]);
  display(tab[2]);
  FREE(lista);
  return 0;
}
