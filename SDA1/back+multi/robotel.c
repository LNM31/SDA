#include<stdio.h>
#define N 4
#define M 5
#define xsol 3
#define ysol 4
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int matrice[N][M]={
  {3,0,0,0,-1},
  {4,5,9,2,-1},
  {0,0,-1,1,-1},
  {1,0,-1,1,0},
};
int vizitat[N][M];
int sol[N][M];
int k=2;
int resurse=0;
int k_min=N*M;
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
  if(x<0 || y<0 || x>N-1 || y>M-1 || vizitat[x][y]>0 || matrice[x][y]==-1)
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
      printf("resurse:%d\n",resurse);
      afisare();
      if(k<k_min)
	{
	  for(int i=0;i<N;i++)
	    for(int j=0;j<M;j++)
	      sol[i][j]=vizitat[i][j];
	  k_min=k;
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
	  int resurse_ant=resurse;
	  resurse+=matrice[xnew][ynew];

	  back(xnew,ynew);

	  vizitat[xnew][ynew]=0;
	  k--;
	  resurse=resurse_ant;
	}
    }
}
/*
am facut deplasarea cu doi vectori,unul pentru axa X si altul pentru axa y
de fiecare data cand am gasit o coordonata buna ,o marcam ca vizitata si continuam pana
gasim o solutie
*/
int main()
{
  vizitat[0][0]=1;
  resurse+=matrice[0][0];
  back(0,0);

  printf("Solutia optima \n");
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
	printf("%2d ",sol[i][j]);
      printf("\n");
    }
  printf("\n");
  return 0;
}
