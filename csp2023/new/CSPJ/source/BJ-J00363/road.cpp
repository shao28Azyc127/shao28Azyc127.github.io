#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[1000005];
int a[1000005];
int b[1000005];
int minx=10000000;
int minf;
int be=1;
long long dis;
int ans=1000000000;
long long dis2;
int main()
{
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        dis+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=i;
        if(a[i]<minx)
        {
            minx=a[i];
            minf=i;
        }
    }
    for(int i=1;i<minf;i++)
    {
        dis2+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==minf)
            {
                if(j*d>=dis-dis2)
                ans+=j*minx;
                cout<<ans;
                return 0;
            }
            else
            {
                if(j*d>=dis2)
                ans=min(ans,j*a[i]);
            }
        }
    }
    cout<<ans;

}