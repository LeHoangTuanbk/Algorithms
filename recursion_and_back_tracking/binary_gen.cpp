#include <iostream>

using namespace std;

int n;
bool a[100];
void Print_solution()
{
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try_forward(int k)
{
    for(int i=0;i<=1;i++)
    {
        a[k] = i;
        if(k == (n-1)) Print_solution();
        else Try_forward(k+1);
    }
}

int main()
{
    n=3;
    Try_forward(0);
    system("pause");
    return 0;
}
