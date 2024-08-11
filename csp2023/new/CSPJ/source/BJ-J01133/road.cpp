#include<bits/stdc++.h>
using namespace std;
struct kx
{
    int shu;
    int xu;
};
long long ans=0;
long long n,d;
long long v[1000005];
kx a[1000005];
long long minn=1000000000;
long long t=0;
kx m[1000005];
int l=0;
int op=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++) cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].shu;
        a[i].xu=i;
    }
    for(int i=1;i<=n-1;i++)
    {
        if(a[i].shu<minn)
        {
            minn=a[i].shu;
            t=i;
        }
    }
    for(int i=t-1;i>=1;i--)
    {
        for(int j=i;j>=1;j--)
        {
            if(a[j].shu>a[i].shu)
            {
                l++;
                m[l].shu=a[j+1].shu;
                m[l].xu=a[j+1].xu;
            }
        }
        i=m[l].xu-1;
    }
    int yy=0;
    for(int i=l;i>=1;i--)
    {
        int st=0;
        for(int j=m[i].xu;j<=m[i-1].xu;j++)
        {
            st+=v[j];
        }
        if((st-yy)%d==0) ans+=(st-yy)/d*m[i].shu;
        else
        {
            ans+=((st-yy)/d+1)*m[i].shu;
            yy+=(st/d+1)*d-st;
        }
    }
    int fk=0;
    for(int i=t;i<=n-1;i++) fk+=v[i];
    if((fk-yy)%d==0) ans+=(fk-yy)/d*minn;
    else
    {
        ans+=((fk-yy)/d+1)*minn;
        yy+=(fk/d+1)*d-fk;
    }
    cout<<ans;
}
