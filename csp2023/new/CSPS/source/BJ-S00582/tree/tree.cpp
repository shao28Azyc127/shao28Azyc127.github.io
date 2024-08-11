#include <iostream>
#include <vector>
using namespace std;
#define int long long
int n;
int a[100010],b[100010],c[100010],i;
int tans;
int solve(int now,int l,int r)
{
    int a1=a[now],b1=b[now],c1=c[now];
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    int tm=(b1+b1+mid*c1-c1)*mid/2;
    if(tm>=a1)
        return solve(now,l,mid);
    else
        return solve(now,mid+1,r);
}
int so2(int now,int l,int r)
{
    int a1=a[now],b1=b[now],c1=c[now];
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    int t1=(b[i]-1)/c[i];
    int tm=(b1+b1-t1)*t1/2ll;
    if(tm>=a1)
        return solve(now,l,mid);
    else
        return solve(now,mid+1,r);
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        b[i]+=c[i]*i;
        b[i]=max(b[i],1ll);
        if(b[i]>=a[i])
        {
            tans=max(tans,1ll);
            continue;
        }
        if(c[i]>0)
            tans=max(tans,solve(i,1ll,a[i]*3/b[i])+i-1);
        else if(c[i]==0)
            tans=max(tans,(a[i]+b[i]-1)/b[i]+i-1);
        else
        {
            c[i]*=-1;
            int t1=(b[i]-1)/c[i];
            int su=(b[i]+b[i]-t1*c[i])*t1/2ll;
            if(su<=a[i])
                tans=max(tans,a[i]-su+t1);
            else
                tans=max(tans,so2(i,1,t1));
        }
    }
    cout<<tans<<endl;
    return 0;
}