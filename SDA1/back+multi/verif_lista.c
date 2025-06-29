#include<stdio.h>
#include<stdlib.h>
typedef struct gg{
  int info;
  struct gg *next;
}nod;

nod *make(int info,nod *elem)
{
  nod *e=(nod *)malloc(sizeof(nod));
  if(e==NULL)
    {
      perror(NULL);
      exit(-1);
    }
  e->info=info;
  e->next=elem;
  return e;
}
nod *add_back(nod *p,nod *lista)
{
  if(lista==NULL)
    {
      p->next=NULL;
      return p;
    }
  nod *q=lista;
  for(;q->next!=NULL;q=q->next);
  p->next=NULL;
  q->next=p;
  return lista;
}
void display(nod *lista)
{
  nod *p=lista,*flag=lista;
  while(p!=NULL)
    {
      printf("%d ",p->info);
      p=p->next;
      if(p==flag)
	{
	  printf("\n");
	  return;
	}
    }
  printf("\n");
}
void f(nod *lista)
{
  nod *p=lista,*flag=lista;
  while(p!=NULL)
    {
      p=p->next;
      if(p==NULL)
	{
	  printf("Lista liniara\n");
	  return;
	}
      else if(p==flag)
	{
	  printf("Lista circulara\n");
	  return;
	}
    }
  printf("Lista nula\n");
}
int main()
{
  nod *p1=make(1,NULL);
  nod *p2=make(2,NULL);
  nod *p3=make(3,NULL);
  nod *p4=make(4,NULL);
  nod *p5=make(5,NULL);

  p1=add_back(p2,p1);
  p1=add_back(p3,p1);
  p1=add_back(p4,p1);
  p1=add_back(p5,p1);

  display(p1);

  nod *p6=make(6,NULL);
  nod *p7=make(7,NULL);
  nod *p8=make(8,NULL);
  nod *p9=make(9,NULL);
  nod *p10=make(10,NULL);

  p6=add_back(p7,p6);
  p6=add_back(p8,p6);
  p6=add_back(p9,p6);
  p6=add_back(p10,p6);
  p10->next=p6;

  display(p6);
  f(p1);
  f(p6);
  return 0;
}
