#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,d,v[100005],a[100005],minn=1e9,sum=0,cnt=0,p,ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;++i)
    {
        scanf("%lld",&v[i]);
        sum += v[i];
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        if(minn>a[i])
        {
            p=i;
            minn=a[i];
        }
    }
    if(minn==a[1])
    {
        ans=sum/d;
        if(sum%d!=0)
            ++ans;
        ans *= a[1];
        printf("%lld\n",ans);
        return 0;
    }
    ans=sum/d;
    for(int i=1;i<p;++i)
        cnt += v[i];
    ans=cnt/d;
    if(cnt%d!=0)
        ++ans;
    ans *= a[1];
    ans += ((sum-cnt)/d+((sum-cnt)%d!=0))*a[p];
    printf("%lld\n",ans);
    return 0;
}
