#include<stdio.h>
#define N 6
int dx[]={-1,1,0,0};//stanga dreapta sus jos
int dy[]={0,0,-1,1};
int matrice [N][N]={
  {10,12,14,16,18,20},
  {9 ,11,13,15,17,19},
  {8 ,7 ,9 ,11,13,15},
  {10,6 ,5 ,7 ,9 ,11},
  {12,8 ,6 ,4 ,6 ,8},
  {14,10,8 ,6 ,5 ,7},
};
int k=2;
int vizitat[N][N];
void afisare()
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
	  printf("%d ",vizitat[i][j]);
      printf("\n");
    }
  printf("\n");
}
int aux;
int ok(int x,int y,int xnew,int ynew)
{
  if(xnew>=0 && ynew>=0 && xnew<=N-1 && ynew<=N-1 && matrice[xnew][ynew]<matrice[x][y])
    return 1;
  return 0;
}
int solutie(int x,int y)
{
  if(x==0 || y==0 || x==N-1 || y==N-1)
    return 1;
  return 0;
}
void back(int x,int y)
{
  int xnew,ynew;
  if(solutie(x,y))
    afisare();
  aux=matrice[x][y];
  for(int i=0;i<4;i++)
    {
      xnew=x+dx[i];
      ynew=y+dy[i];
      if(ok(x,y,xnew,ynew))
	{
	  vizitat[xnew][ynew]=k++;
	  back(xnew,ynew);
	  vizitat[xnew][ynew]=0;//valoarea anterioara
	  k--;
	}
    }
}
int main()
{
  vizitat[0][5]=1;
  back(0,5);
  //afisare();
  return 0;
}
