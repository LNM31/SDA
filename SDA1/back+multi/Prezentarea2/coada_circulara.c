#include<stdio.h>
#define N 7
typedef struct{
  int v[N+1];
  int size;
  int prim;
  int ultim;
}coada;
void init(coada *c)
{
  c->size=N+1;
  c->prim=1;
  c->ultim=0;
}
void adauga(int x,coada *c)
{
  if(((c->ultim+2)%c->size)==c->prim)
    {
      printf("Coada este plina!\n");
    }
  else
    {
      c->ultim=(c->ultim+1)%c->size;
      c->v[c->ultim]=x;
    }
}
int scoate(coada *c)
{
  int rez=-1;
  if((c->ultim+1)%c->size==c->prim)
    {
      printf("Coada este plina!\n");
    }
  else
    {
      rez=c->v[c->prim];
      c->prim=(c->prim+1)%c->size;
    }
  return rez;
}
void afisare(const coada *c)
{
  int i=c->prim-1;
  if(c->ultim+1!=c->prim)
  do{
    i=(i+1)%c->size;
    printf("%d ",c->v[i]);
  }while(i!=c->ultim);
  printf("\n");
}
int main()
{
  coada c;
  init(&c);
  adauga(1,&c);
  adauga(2,&c);
  adauga(3,&c);
  adauga(4,&c);
  adauga(5,&c);
  adauga(6,&c);
  adauga(7,&c);
  
  afisare(&c);
  adauga(8,&c);
  scoate(&c);
  scoate(&c);
  scoate(&c);
  adauga(8,&c);
  adauga(9,&c);
  adauga(10,&c);
  afisare(&c);
  scoate(&c);
  scoate(&c);
  scoate(&c);
  adauga(14,&c);
  adauga(15,&c);
  adauga(16,&c);
  afisare(&c);
  adauga(100,&c);
  return 0;
}
