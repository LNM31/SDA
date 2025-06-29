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
nod *add_back(int info,nod *lista)
{
  if(lista==NULL)
    return make(info,NULL);
  nod *p=lista;
  for(;p->next!=NULL;p=p->next);
  p->next=make(info,NULL);
  return lista;
}
void display(nod *lista)
{
  nod *p=lista;
  while(p!=NULL)
    {
      printf("%d ",p->info);
      p=p->next;
    }
}
void free_list(nod *lista)
{
  nod *p=lista,*aux=NULL;
  while(p!=NULL)
    {
      aux=p;
      p=p->next;
      free(aux);
    }
}
nod *f(nod *lista)
{
  nod *p=lista,*q=lista;
  while(q->next!=NULL)
    {
      p=p->next;
      q=q->next->next;
    }
  return p;
}


/*
-am folosit doi incrementi,unul care merge din 1 in 1 si altul cand merge din doi in doi
Astfel,cand al doilea increment o sa ajunga la sfarsit ,primul o sa fie la mijoc,de unde
il si returnam,eficienta este O(n)
*/
int main()
{
  nod *l1=NULL;
  for(int i=1;i<10;i++)
    l1=add_back(i,l1);
  display(l1);
  nod *rez=f(l1);
  printf("\nnod mijloc:%d\n",rez->info);
  free_list(l1);
  return 0;
}
