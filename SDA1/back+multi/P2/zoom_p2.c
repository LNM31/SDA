#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
typedef struct gg{
  char nume[36],email[36];
  struct gg *next;
}student;
typedef struct {
  int id,data;
  char gazda[36];
  student *s;
}conferinta;

typedef struct {
  conferinta v[N];
  int size;
}List;



//lista sec
student *make(char *nume,char *email,student *elem)
{
  student *e=(student *)malloc(sizeof(student));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  strcpy(e->nume,nume);
  strcpy(e->email,email);
  e->next=elem;
  return e;
}
student *adauga(char *nume,char *email,student *lista)
{
  if(lista==NULL)
    return make(nume,email,NULL);
  student *st=NULL,*p=lista;
  for(;p!=NULL;p=p->next)
    {
      if(strcmp(nume,p->nume)<0)
	{
	  if(st==NULL)
	    return make(nume,email,lista);
	  else
	    {
	      student *nou=make(nume,email,p);
	      st->next=nou;
	      return lista;
	    }
	}
      if(p->next==NULL)
	{
	  p->next=make(nume,email,NULL);
	  return lista;
	}
      st=p;
    }
  return lista;
}
void display(student *lista)
{
  student *p=lista;
  while(p!=NULL)
    {
      printf("%s %s\n",p->nume,p->email);
      p=p->next;
    }
  printf("\n");
}
void free_list(student *lista)
{
  student *p=lista,*aux=NULL;
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
void adauga_conf(int id,int data,char *gazda,student *s,List *lista)
{
  lista->v[lista->size].id=id;
  lista->v[lista->size].data=data;
  lista->v[lista->size].s=s;
  strcpy(lista->v[lista->size++].gazda,gazda);
}
void afisare(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      printf("ID:%d %d %s STU:\n",lista->v[i].id,lista->v[i].data,lista->v[i].gazda);
      display(lista->v[i].s);
    }
  printf("\n");
}
void FREE(List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      free_list(lista->v[i].s);
    }
}
void modificare_email(int id,char *nume,char *email_nou,List *lista)
{
  for(int i=0;i<lista->size;i++)
    {
      if(id==lista->v[i].id)
	{
	  student *p=lista->v[i].s;
	  while(p!=NULL)
	    {
	      if(strcmp(p->nume,nume)==0)
		{
		  strcpy(p->email,email_nou);
		  return;
		}
	      p=p->next;
	    }
	}
    }
}
int main()
{

  student *s1=NULL;
  s1=adauga("N3","E3",s1);
  s1=adauga("N2","E2",s1);
  s1=adauga("N4","E4",s1);
  s1=adauga("N1","E1",s1);
  s1=adauga("N5","E5",s1);

  student *s2=NULL;
  s2=adauga("N3","E3",s2);
  s2=adauga("N2","E2",s2);
  s2=adauga("N4","E4",s2);
  s2=adauga("N1","E1",s2);
  s2=adauga("N5","E5",s2);

  student *s3=NULL;
  s3=adauga("N3","E3",s3);
  s3=adauga("N2","E2",s3);
  s3=adauga("N4","E4",s3);
  s3=adauga("N1","E1",s3);
  s3=adauga("N5","E5",s3);

  List lista;
  initializare(&lista);
  adauga_conf(1,2025,"G1",s1,&lista);
  adauga_conf(2,2026,"G2",s2,&lista);
  adauga_conf(3,2027,"G3",s3,&lista);
  afisare(&lista);

  modificare_email(2,"N4","ENOU",&lista);
  afisare(&lista);
  FREE(&lista);
  return 0;
}
