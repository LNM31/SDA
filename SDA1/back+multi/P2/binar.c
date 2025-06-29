#include<stdio.h>
int v[6];
int ok(int k)
{
  if(k==1 && v[k-1]==v[k] && v[k]==1)//(k==1 && v[0]==1 && v[1]==1)
    return 0;
  if(k==5 && v[k]==0)
    return 0;
  return 1;
}
int solutie(int k)
{
  if(k!=5)
    return 0;
  int c=0;
  for(int i=0;i<=k;i++)
    if(v[i]==0)
      c++;
  return c==2;
}
void afisare()
{
  for(int i=0;i<6;i++)
    printf("%d ",v[i]);
  printf("\n");
}
void back(int k)
{
  for(int i=0;i<2;i++)
    {
      v[k]=i;
      if(ok(k))
	{
	  if(solutie(k))
	    afisare();
	  else if(k<6)
	    back(k+1);
	}
    }
}
int main()
{
  back(0);
  return 0;
}
