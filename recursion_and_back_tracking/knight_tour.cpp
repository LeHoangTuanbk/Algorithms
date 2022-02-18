#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int n2;
int m[20][20];

int y_move[8] = {-1,-2,-2,-1,1,2,2,1};
int x_move[8] = {2,1,-1,-2,-2,-1,1,2};

bool Check_moveable(int x_new, int y_new)
{
    if(0<= x_new && x_new < n && y_new >= 0 && y_new < n && m[y_new][x_new] == -1)
        return true;
    return false;
}

void Print_solution()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << setw(2)<< m[i][j] << " ";
        }
        cout << endl;
    }
}

int Try(int x, int y, int t) // 8^64
{
    if (t == n2) 
    {
        // Print_solution();
        return 1;
    }
    for(int k=0;k<8;k++)
    {
        int x_new = x + x_move[k];
        int y_new = y + y_move[k];
        // if (t == n2) Print_solution();
        if (Check_moveable(x_new, y_new)) {
            m[y_new][x_new] = t;
            if(Try(x_new, y_new,t+1) == 1)
                return 1;
            else
                m[y_new][x_new] = -1;    
        }
    }
    return 0;
}
int main()
{

    n = 8;
    n2 = n*n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            // cout << m[i][j] << " " ;
            m[i][j] = -1;
        }
    m[0][0] = 0;
    if(Try(0,0,1))
        Print_solution();
    else cout <<"Solution doesn't exist;";
    system("pause");
    return 0;
}