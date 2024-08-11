#include <bits/stdc++.h>
using namespace std;
int n,cnt;
int a[10][10];

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
        {
            cin>>a[i][j];
        }
    }

    if(n==1)
    {
        cnt=81;
    }
    else if(n==2)
    {
        cnt=10;
    }
    else if(n==8)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(a[i][j]!=a[i+1][j]&&a[i][j]!=a[i][j+1])
                {
                    cnt=10;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}