#include<stdio.h>
int aux[3];
int ok(int k,int *v)
{
  if(aux[0]>3 || aux[1]>4 || aux[2]>3)
    return 0;
  return 1;
}
int solutie(int k)
{
  if(k==9)
    return 1;
  return 0;
}
void afisare(int k,int *v,char *info)
{
  for(int i=0;i<=k;i++)
    printf("%c ",info[v[i]]);
  printf("\n");
}
void back(int k,int *v,char *info)
{
  for(int i=0;i<3;i++)
    {
      v[k]=i;
      aux[i]++;
      if(ok(k,v))
	{
	  if(solutie(k))
	    afisare(k,v,info);
	  else 
	    back(k+1,v,info);
	}
      aux[i]--;
    }
}
/*
-s a facut cu backtracking,maximul de pasi pentru functia back sunt combinari de 10 luate
cate 4 *combinari de 6 luate cate 3,functiile ok,solutie si afisare sunt fiecare O(1),
un total de 4200 de pasi,din care doar cateva sunt solutii
*/
int main()
{
  char M[]={'a','b','c'};
  int v[10];
  back(0,v,M);
  return 0;
}
