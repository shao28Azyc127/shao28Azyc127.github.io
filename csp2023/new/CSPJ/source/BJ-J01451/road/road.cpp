#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],v[N],s[N];
long long b[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n-1;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++)
        b[i]=b[i-1]+v[i-1];
    int minn=a[1],len=1;
    s[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]<minn)
        {
            minn=a[i];
            len++;
            s[len]=i;
        }
    }
    long long ans=0;
    double t=0.0;
    for(int i=1;i<=len;i++)
    {
        double x=double(b[s[i]])-double(b[s[i-1]]);
        if(t>=x)
        {
            t=t-x;
            continue;
        }
        x=x-t,t=0.0;
        if(x<=double(d))
        {
            t=double(d)-x;
            ans=ans+a[s[i-1]];
            continue;
        }
        double q=x/double(d);
        if(q-int(q)==0)
            ans=ans+(int(q))*a[s[i-1]];
        else
        {
            ans=ans+(int(q)+1)*a[s[i-1]];
            t=double((int(q)+1)*d)-x;
        }
    }
    if(len==n) printf("%lld\n",ans);
    else
    {
        double x=double(b[n])-double(b[s[len-1]]);
        if(t>=x)
        {
            printf("%lld\n",ans);
            return 0;
        }
        x=x-t,t=0.0;
        if(x<=double(d))
        {
            t=double(d)-x;
            ans=ans+a[s[len]];
            printf("%lld\n",ans);
            return 0;
        }
        double q=x/double(d);
        if(q-int(q)==0)
            ans=ans+(int(q))*a[s[len]];
        else
        {
            ans=ans+(int(q)+1)*a[s[len]];
            t=double((int(q)+1)*d)-x;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
