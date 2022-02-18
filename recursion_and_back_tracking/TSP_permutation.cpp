/*
1.Min
2.Path
3.Branch and Bounding

*/
// #include <iostream>
#include <bits/stdc++.h>
// #include <limits.h>

using namespace std;

#define N 6

int min_cost = INT_MAX;

int c = 0;
bool visited[N];
int cost_matrix[N][N] = {
        {0,10,15,20,20,30},
        {10,0,35,25,30,60},
        {15,35,0,30,50,50},
        {20,25,30,0,40,10},
        {20,30,50,40,0,20},
        {30,60,50,10,20,0}
    };

int path_min[N];
int path[N];

void Update_min(int current_city)
{
    int total_cost = c + cost_matrix[current_city][0];
    if(total_cost < min_cost)
    {
        min_cost = total_cost;
        for(int i=0;i<N;i++)
        {
            path_min[i] = path[i];
        }
    }
}

int t=0;
int c_min;
void Try(int current_city, int k) //city thanh pho hien tai dang o, k thanh pho thu ?
{
    if(k == N) {
        // cout << current_city << " ";
        Update_min(current_city);
        return ;
    }
    else
    {
        for(int next_city=0;next_city<N;next_city++)
        {
            if(!visited[next_city] && (current_city != next_city && ( min_cost > c + c_min*(N-k-1)))) // min_cost < g = c + c_min*(n-k-1) thi k di tiep. 
            // if(!visited[next_city] && (current_city != next_city)) // min_cost < g = c + c_min*(n-k-1) thi k di tiep. 
            
            {
                // cout << next_city<< " " ;
                cout << (++t) << " ";
                visited[next_city] = 1;
                c += cost_matrix[current_city][next_city];
                path[current_city] = next_city;
                Try(next_city,k+1);
                c -= cost_matrix[current_city][next_city];
                visited[next_city] = 0;
                path[current_city] = 0;
            }
        }
    }
    // return 0;
}


int main()
{
    for(int i=0;i<N;i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    c_min = cost_matrix[0][0];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(cost_matrix[i][j] < c_min && (i != j))
            {
                c_min = cost_matrix[i][j];
            }
        }
    }
    cout << "The min cost is: ";
    Try(0,1);
    cout << min_cost<< endl ;
    int a = path_min[0];
    cout << "The path is: 0 ";
    for(int i=0;i<N;i++)
    {
        cout << a << " ";
        a = path_min[a];
    }

    system("pause");
    return 0;
}