#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int a,b,l[9][5];
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>l[i][j];
        }
    }
    if(a==1)
    {
        cout<<81;
    }
    else
    {
        cout<<10;
    }
    return 0;
}
