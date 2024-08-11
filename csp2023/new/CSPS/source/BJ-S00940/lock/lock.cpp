#include<bits/stdc++.h>
using namespace std;
int a[9][6];
stack<int> sa,sb;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    if(n==1)
    {
        cout<<81;
        return 0;
    }

        for(int j=1;j<=5;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(k==a[1][j]) continue;
                sa.push(1);
            }
        }
    for(int i=1;i<=n;i++)
    {

    }
    return 0;
}
