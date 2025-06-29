#include<stdio.h>
#define N 3
#define M 3
int dx[]={-1,1,-1,1};//dreapta jos stanga sus
int dy[]={-1,-1,1,1};
int matrice[N][M];
int v[N*M];
int ok(int k)
{
  int a=k/N,b=k%M,xnew,ynew;
  for(int i=0;i<4;i++)
    {
      xnew=a+dx[i];
      ynew=b+dy[i];
      if(xnew>=0 && xnew<=N-1 && ynew>=0 && ynew<=M-1 && matrice[a][b]==matrice[xnew][ynew])
	return 0;
    }
  return 1;
}
int solutie(int k)
{
  if(k==N*M-1)
    return 1;
  return 0;
}
void afisare()
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
	printf("%d",matrice[i][j]);
      printf("\n");
    }
  printf("\n");
}
void back(int k)
{
  for(int i=1;i<=4;i++)
    {
      matrice[k/N][k%M]=i;
      if(ok(k))
	{
	  if(solutie(k))
	    afisare();
	  else if(k<=N*M)
	    {
	      back(k+1);
	    }
	}
    }
}
int main()
{
  back(0);
  //afisare();
  return 0;
}
