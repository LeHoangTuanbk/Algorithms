#include <iostream>

using namespace std;

int C(int k, int n)
{
    if (k == 0 || k == n) return 1;
    if (k == 1 ) return n;
    return C(k-1,n-1) + C(k,n-1);
}

int k,n;
int C_me[100][100];

int C_memoization(int k, int n)
{
    if (k == 0 || k == n) return 1;
    if (k == 1 ) return n;
    if( C_me[k][n] > 0) return C_me[k][n];
    else 
    {
        C_me[k][n] = C_memoization(k-1,n-1) + C_memoization(k,n-1);
        return C_me[k][n];
    }
}
int main()
{
    cout << C(30,40);
    k = 30; n = 40;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            C_me[i][j] = 0;
        }
    }
    // cout << C_memoization(k,n);
    system("pause");

    return 0;
}

    //      1  k = 0, n = 0
    //     1 1 , k = 0,1, n = 1
    //    1 2 1, k = 0,1,2, n = 2
    //   1 3 3 1
