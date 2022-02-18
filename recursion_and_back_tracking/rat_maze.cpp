#include <iostream>
using namespace std;

#define N 4

int maze[N][N] = {
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 1, 0, 0},
            {1, 1, 1, 1}
            };

int path[N][N];

int x_move[2] = {1,0};
int y_move[2] = {0,1};

bool Try(int x, int y, int k)
{
    if (x == (N-1) && y == (N-1)) return 1;
    for(int i=0;i<2;i++)
    {
        int x_new = x + x_move[i];
        int y_new = y + y_move[i];
        if(maze[y_new][x_new]) 
        {
            path[y_new][x_new] = 1;
            if(Try(x_new, y_new, k+1)) return 1;
            else path[y_new][x_new] = 0;
        }
    }
    return 0;
}

void Print_solution()
{
    for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                cout << path[i][j] << " ";
            cout << endl;
        }
}

int main()
{
    path[0][0] = 1;
    if(Try(0,0,0)) Print_solution();
    else cout << " Rat couldn't reach the destination";
    system("pause");

    return 0;
}
