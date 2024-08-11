#include<bits/stdc++.h>
using namespace std;
long long n,d,mmin=0x3f3f3f3f,f,u,w;
int a[100010],v[100010];
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        u=v[i];
        if(f>u)
        {
            f-=u;
            u=0;
        }
        else
        {
            u-=f;
            f=0;
        }
        if(a[i]<mmin)
        {
            mmin=a[i];
        }
        w=u/d+((u%d)?1:0);
        ans+=mmin*w;
        f+=d*w-u;
    }
    cout<<ans<<endl;
    return 0;
}
