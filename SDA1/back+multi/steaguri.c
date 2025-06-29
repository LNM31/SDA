#include<stdio.h>
int ok(int k,int *v)
{
  if(k==1 && v[k]!=1 && v[k]!=3)
    return 0;
  for(int i=0;i<k;i++)
    if(v[i]==v[k])
      return 0;
  return 1;
}
int solutie(int k)
{
  return k==2;
}
void afisare(int *v,char **info)
{
  for(int i=0;i<3;i++)
    printf("%s ",info[v[i]]);
  printf("\n");
}
void back(int k,int *v,char **info)
{
  for(int i=0;i<6;i++)
    {
      v[k]=i;
      if(ok(k,v))
	{
	  if(solutie(k))
	    afisare(v,info);
	  else
	    back(k+1,v,info);
	}
    }
}
int main()
{
  char *info[]={"alb","galben","rosu","verde","albastru","negru"};
  int v[3];
  back(0,v,info);
  return 0;
}
