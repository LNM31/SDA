//taskkill /F /IM ApplicationName.exe
#include<stdio.h>
#define N 8
int dx[] = { 0,0,-1,1 };// sus, jos, stnga, dreapta
int dy[] = { -1,1,0,0 };
char matrice[N][N] = {
    {'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n'},
    {'n', 'a', 'a', 'a', 'n', 'a', 'a', 'n'},
    {'n', 'a', 'a', 'a', 'n', 'a', 'a', 'n'},
    {'n', 'n', 'a', 'a', 'n', 'n', 'n', 'n'},
    {'n', 'n', 'n', 'n', 'n', 'a', 'a', 'n'},
    {'n', 'n', 'n', 'n', 'n', 'a', 'a', 'n'},
    {'n', 'a', 'a', 'n', 'n', 'n', 'n', 'n'},
    {'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n'}
};
int vizitat[N][N];
int zone[N];
int count;//numarul de zone
int size;
int ok(int xnew, int ynew)
{
    if (xnew >= 0 && ynew >= 0 && xnew <= N - 1 && ynew <= N - 1 && matrice[xnew][ynew] == 'a' && vizitat[xnew][ynew] == 0)
        return 1;
    return 0;
}
void gasit(int size)
{
    zone[count++] = size;
}
void back(int x, int y, int* size)
{
    for (int i = 0; i < 4; i++)
    {
        int xnew = x + dx[i];
        int ynew = y + dy[i];
        if (ok(xnew, ynew))
        {
            vizitat[xnew][ynew] = 1;
            (*size)++;
            back(xnew, ynew, size);
        }
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrice[i][j] == 'a' && vizitat[i][j] == 0)
            {
                size = 1;
                vizitat[i][j] = 1;
                back(i, j, &size);
                gasit(size);
            }
        }
    }
    for (int i = 0; i < count; i++)
        printf("C%d = %d celule albe\n",i,zone[i]);
    return 0;
}
