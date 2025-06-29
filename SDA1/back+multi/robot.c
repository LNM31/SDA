#include<stdio.h>
#define N 10
int dx[]={1,-1,0,0};//dreapta stanga sus jos
int dy[]={0,0,-1,1};
int baterie=5;//default
char matrice[N][N] = {
    {'*', '.', '.', '*', '.', '+', '.', '.', '.', '.'},
    {'.', '.', '*', '.', '.', '*', '.', '.', '.', '.'},
    {'*', '.', '.', '.', '.', '*', '.', '.', '.', '.'},
    {'.', '.', '*', '*', '*', '.', '.', '+', '.', '.'},
    {'.', '.', '.', '.', '.', '*', '*', '.', '*', '*'},
    {'S', '.', '.', '+', '.', '*', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '*', '*', '*', '.', '.'},
    {'*', '*', '*', '*', '*', '*', '.', '.', '.', '.'},
    {'.', '.', 'E', '.', '*', '.', '.', '+', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '*', '*', '.', '.'}
};
int g=2,gmin=100;;
int vizitat[N][N];
int final[N][N];
int ok(int x,int y)
{
  if(x<0 || y<0 || x>=N || y>=N || baterie<=0 || matrice[x][y]=='*' ||  vizitat[x][y]>=1 )
    return 0;
  return 1;
}
int solutie(int x,int y)
{
  return matrice[x][y]=='E';
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
  if (solutie(x, y)) {
    afisare();
    if(g<gmin)
    {
      gmin=g;
      for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	  final[i][j]=vizitat[i][j];
    }
    return;
  }
  int xnew,ynew;
  for(int i=0;i<4;i++)
    {
      xnew=x+dx[i];
      ynew=y+dy[i];
      if(ok(xnew,ynew))
	{
	  int bat_ant=baterie;
	  baterie--;
	  vizitat[xnew][ynew]=g++;
	  if(matrice[xnew][ynew]=='+')
	    baterie+=10;
	 
	  back(xnew,ynew);

	  vizitat[xnew][ynew]=0;
	  g--;
	  baterie=bat_ant;
	}
    }
}
int main()
{
  vizitat[5][0]=1;
  back(5,0);

  printf("Solutia cea mai buna:\n");
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
	printf("%2d ",final[i][j]);
      printf("\n");
    }
  printf("\n");
  return 0;
}
