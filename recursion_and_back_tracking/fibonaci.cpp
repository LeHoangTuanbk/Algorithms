#include <iostream>

using namespace std;

int memoi[100] = {0,1,1};

int F(int n)
{
    if(n == 1 || n == 2) return 1;
    return F(n-1) + F(n-2);
}

int F_memoi(int n)
{
    if(n == 1 || n == 2) return memoi[n];
    if(memoi[n] > 0) return memoi[n];
    else 
    {
        memoi[n] = F_memoi(n-1) + F_memoi(n-2);
        return memoi[n];
    }
}



int main()
{
    // cout << F(43) << endl;
    cout << F_memoi(50) << endl;
    system("pause");
    return 0;
}