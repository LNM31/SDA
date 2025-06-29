#include<stdio.h>
#include<stdlib.h>
#define N 4
#define M 5
#define xsol 3
#define ysol 4
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int matrice[N][M]={
  {3,0,0,0,1},
  {0,5,0,2,0},
  {0,0,0,0,0},
  {2,0,0,1,0},
};
int vizitat[N][M];
int sol[N][M];
int baterie=0,baterie_maxima=0;
int k=2;
void afisare()
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
	printf("%2d ",vizitat[i][j]);
      printf("\n");
    }
  printf("\n");
}
int ok(int x,int y)
{
  if(x<0 || y<0 || x>N-1 || y>M-1 || baterie<=0 || vizitat[x][y]>0)
    return 0;
  return 1;
}
int solutie(int x,int y)
{
  return x==xsol && y==ysol;
}
void back(int x,int y)
{
  if(solutie(x,y))
    {
      afisare();
      if(baterie>baterie_maxima)
	{
	  for(int i=0;i<N;i++)
	    for(int j=0;j<M;j++)
	      sol[i][j]=vizitat[i][j];
	  baterie_maxima=baterie;
	}
      return;
    }
  for(int i=0;i<4;i++)
    {
      int xnew=x+dx[i];
      int ynew=y+dy[i];
      if(ok(xnew,ynew))
	{
	  vizitat[xnew][ynew]=k++;
	  int baterie_ant=baterie;
	  if(matrice[xnew][ynew]>0)
	    baterie+=matrice[xnew][ynew];
	  baterie--;

	  back(xnew,ynew);

	  vizitat[xnew][ynew]=0;
	  k--;
	  baterie=baterie_ant;
	}
    }
}
int main()
{
  vizitat[0][0]=1;
  baterie+=matrice[0][0];
  back(0,0);

  printf("Solutia cu bateria maxima:%d\n",baterie_maxima);
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
	printf("%2d ",sol[i][j]);
      printf("\n");
    }
  return 0;
}
