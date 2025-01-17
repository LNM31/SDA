#include<stdio.h>
#define N 7
int baterie=3,g=2;
int dx[]={-1,1,0,0};//stanga dreapta sus jos
int dy[]={0,0,-1,1};
int matrice[N][N]={
  {-1,-1,-1,-1,-1,-1,-1},
  {-1, 0, 5, 0, 0, 4,-1},
  {-1, 0, 0,-1, 0,-1,-1},
  {-1, 3, 0,-1, 5, 0,-1},
  {-1, 0, 0,-1, 0, 0,-1},
  {-1, 0, 0,-1, 0, 0, 0},
  {-1,-1,-1,-1,-1, 0,-1},
};
int vizitat[N][N];
int valid(int x,int y)
{
  if(x<0 || y<0 || x>=N || y>=N || baterie<=0 || matrice[x][y]==-1 || vizitat[x][y]>=1)
    return 0;
  return 1;
}
int solutie(int x,int y)
{
  return x==0 || y==0 || x==N-1 || y==N-1;
}
void afisare()
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
	printf("%2d ",vizitat[i][j]);
      printf("\n");
    }
  printf("\n");
}
void back(int x,int y)
{
  if(solutie(x,y))
    {
      afisare();
      return;
    }
  for(int i=0;i<4;i++)
    {
      int xnew=x+dx[i];
      int ynew=y+dy[i];
      if(valid(xnew,ynew))
	{
	  
	  int baterie_ant=baterie;
	  baterie--;
	  vizitat[xnew][ynew]=g++;
	  if(matrice[xnew][ynew]>0)
	    baterie+=matrice[xnew][ynew];
	  

	  back(xnew,ynew);

	   g--;
	  baterie=baterie_ant;
	  vizitat[xnew][ynew]=0;
	  
	 
	}
    }
}
int main()
{
  vizitat[5][2]=1;
  back(5,2);
  //afisare();
  return 0;
}
