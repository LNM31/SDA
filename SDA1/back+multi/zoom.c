#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
typedef struct gg{
  char nume[36];
  struct gg *next;
}student;
typedef struct{
  int id,parola;
  student *s;
}conferinta;

typedef struct{
  conferinta v[50];
  int size;
}List;//sesiune



student  *make(char *nume,student *elem)
{
  student *e=(student *)malloc(sizeof(student));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  strcpy(e->nume,nume);
  e->next=elem;
  return e;
}
student *adauga(char *nume,student *lista)
{
  if(lista==NULL)
    return make(nume,NULL);
  student *st=NULL,*p=lista;
  for(;p!=NULL;p=p->next)
    {
      if(strcmp(nume,p->nume)<0)
	{
	  if(st==NULL)
	    return make(nume,p);
	  else
	    {
	      student *nou=make(nume,NULL);
	      st->next=nou;
	      nou->next=p;
	      return lista;
	    }
	  
	}
      if(p->next==NULL)
	    {
	      p->next=make(nume,NULL);
	      return lista;
	    }
      st=p;
    }
  return lista; 
}
student *stergere(char c,student *lista,int *ok)
{
  *ok=0;
  student *st=NULL,*p=lista,*dr=NULL;
  for(;p!=NULL;p=p->next)
    {
      dr=p->next;
      if(p->nume[0]==c)
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
  *ok=1;
  return lista;
}
int comp(student *s1,student *s2)
{
  student *p=s1,*q=s2;
  int c1=0,c2=0;
  for(;p!=NULL;p=p->next)
    c1++;
  for(;q!=NULL;q=q->next)
    c2++;
  return c1==c2;
}
student *stergere_totala(char c,student *lista)
{
  int ok=0;
  while(ok==0)
    {
      lista=stergere(c,lista,&ok);
    }
  return lista;
}
void display(student *lista)
{
  student *p=lista;
  while(p!=NULL)
    {
      printf("%s ",p->nume);
      p=p->next;
    }
  printf("\n");
}
void free_list(student *s)
{
  student *p=s,*aux=NULL;
  while(p!=NULL)
    {
      aux=p;
      p=p->next;
      free(aux);
    }
}





/*
-am facut doua liste,una sec si alta princi,cea sec este lista simplu inlantuita,iar cea
princi este un tablou,
-pentru lista sec,adaugarea este O(n) ,stergerea O(n)
-pentru princi ,adaugarea este O(1),stergerea depinde de fiecare lista a fiecarui elem
in general O(n)
le am ales pentru simplitate si eficienta pentru unele functii
*/
void adauga_conferinta(int id,int parola,student *s,List *lista)
{
  lista->v[lista->size].id=id;
  lista->v[lista->size].parola=parola;
  lista->v[lista->size++].s=s;
}
void afisare(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      printf("ID:%d Parola:%d ",lista->v[i].id,lista->v[i].parola);
      display(lista->v[i].s);
    }
  printf("\n");
}
void initializare(List *lista)
{
  lista->size=0;
}
void acceptare(char c,List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      lista->v[i].s=stergere_totala(c,lista->v[i].s);
    }
}
void FREE(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      free_list(lista->v[i].s);
    }
}
int main()
{
  student *s1=NULL;
  s1=adauga("Cosmin",s1);
  s1=adauga("Ana",s1);
  s1=adauga("Bob",s1);
  s1=adauga("Dan",s1);
  s1=adauga("Bembi",s1);
  s1=adauga("Abel",s1);

  student *s2=NULL;
  s2=adauga("Catalin",s2);
  s2=adauga("Alex",s2);
  s2=adauga("Bogdan",s2);
  s2=adauga("Darius",s2);
  s2=adauga("Belea",s2);
  s2=adauga("Aris",s2);

  student *s3=NULL;
  s3=adauga("Cornel",s3);
  s3=adauga("Andrei",s3);
  s3=adauga("Bianca",s3);
  s3=adauga("Denis",s3);
  s3=adauga("Bel",s3);
  s3=adauga("Anton",s3);

  
  List lista;
  initializare(&lista);
  adauga_conferinta(1,10,s1,&lista);
  adauga_conferinta(2,20,s2,&lista);
  adauga_conferinta(3,30,s3,&lista);
  afisare(&lista);
  acceptare('B',&lista);
  afisare(&lista);
  FREE(&lista);
  return 0;
}
