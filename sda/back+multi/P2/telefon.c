
#include<stdio.h>
int sol;
int valid(int k,int *v)
{
  if(v[k-1]%2==0 && v[k]%2==0 && v[k+1]%2==0)
    return 0;
  return 1;
}
int solutie(int k)
{
  sol++;
  return k==8;
}
void afisare(int *v)
{
  for(int i=0;i<10;i++)
    {
      printf("%d",v[i]);
    }
  printf("\n");
}
void back(int k,int *v)
{
  for(int i=0;i<10;i++)
    {
      v[k]=i;
      if(valid(k,v))
	{
	  if(solutie(k))
	    afisare(v);
	  else
	    back(k+1,v);
	}
    }
}
int main()
{
  int v[10]={0,7,9,9};
  v[9]=0;
  back(4,v);
  printf("sol:%d\n",sol);
  return 0;
}
