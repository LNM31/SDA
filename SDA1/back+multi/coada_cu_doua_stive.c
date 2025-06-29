#include<stdio.h>
#include<stdlib.h>
typedef struct gg
{
  int info;
  struct gg *next;
}nod;
typedef struct {
  nod *l;
}stiva;
typedef struct {
  stiva s1;
  stiva s2;
}fifo;

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
void adauga(nod *p,stiva *s)
{
  if(s->l==NULL)
    {
      p->next=NULL;
      s->l=p;
      return;
    }
  p->next=s->l;
  s->l=p;
}
nod *scoate(stiva *s)
{
  nod *p=s->l;
  s->l=s->l->next;
  return p;
}



//coada
void init(fifo *c)
{
  c->s1.l=NULL;
  c->s2.l=NULL;
}
void push(nod *p,fifo *c)
{
  adauga(p,&c->s1);
}
nod * pop(fifo *c)
{
  if(c->s2.l==NULL)
  while(c->s1.l!=NULL)
    {
      adauga(scoate(&c->s1),&c->s2);
    }
  nod *p=scoate(&c->s2);
  return p;
}
int coada_goala(fifo *c)
{
  return c->s1.l==NULL && c->s2.l==NULL;
}
int main()
{
  nod *p1=make(1,NULL);
  nod *p2=make(2,NULL);
  nod *p3=make(3,NULL);
  nod *p4=make(4,NULL);
  nod *p5=make(5,NULL);
  nod *p6=make(6,NULL);
  nod *p7=make(7,NULL);
  nod *p8=make(8,NULL);

  nod *p=NULL;
  fifo c;
  init(&c);
  push(p1,&c);
  push(p2,&c);
  push(p3,&c);
  push(p4,&c);
  pop(&c);
  push(p5,&c);
  push(p6,&c);
  push(p7,&c);
  push(p8,&c);

  while(coada_goala(&c)==0)
    {
      p=pop(&c);
      printf("%d ",p->info);
    }
  return 0;
}
