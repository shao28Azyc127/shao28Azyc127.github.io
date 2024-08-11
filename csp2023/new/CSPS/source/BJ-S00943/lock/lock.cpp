#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int b1[10];
int b2[10];
int ans=0;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    if(n==1) cout<<81;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            if(a[i][j]!=a[i+1][j])b1[j]=1;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(a[i][j]-a[i][j+1]!=a[i+1][j]-a[i+1][j+1])b2[j]=1;
        }
    }
    if(b1[1]+b1[2]+b1[3]+b1[4]+b1[5]==1)
    {
        cout<<10;
    }
    if(0.0+b2[1]+b2[2]+b2[3]+b2[4]==1)
    {
        cout<<10;
    }
return 0;
}
