#include <bits/stdc++.h>
using namespace std;
int n;
const int N=100009;
int a[N];
int v[N];
int ans;
int minn=INT_MAX;
int minid;
int d;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        minn=min(minn,v[i]);
    }
    if(minn==a[1])
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=v[i];
        }
        while(sum>0)
        {
            sum-=d;
            ans+=minn;
        }
        cout<<ans;
        return 0;
    }
    else
    {
        int sum=0;
        int y=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int k=a[i];
                y-=k;
                while(y<0)
                {
                    y+=d;
                    sum+=v[j];
                }
            }
        }
        cout<<sum;
    }
    return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5
*/