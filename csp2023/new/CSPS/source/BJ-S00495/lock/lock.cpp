#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n;
int a[100];
int vis[100005];
int main()
{
    freopen("lock.out","w",stdout);
    freopen("lock.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        for(int j=1;j<=5;j++)
        {
            cin>>x;
            a[i]*=10;
            a[i]+=x;
        }
    }
    if(n==1)
    {
        cout<<81;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        for(int j=0;j<=n;j++)
        {
            int add=int(pow(10,j));
            for(int k=1;k<=9;k++)
            {
                if((x/add)%10==9)
                {
                    x-=9*add;
                }
                else
                {x+=add;}
                vis[x]=1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=99999;i++)
    {
        ans+=vis[i];
    }
    cout<<ans;
    return 0;
}
