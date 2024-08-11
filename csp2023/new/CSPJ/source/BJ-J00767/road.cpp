#include<cstdio>
#include<algorithm>
const int N=1e5+5;
int v[N],a[N];
int cal(int d,int perl,int need)
{
    if(need%d==0) return need/d*perl;
    else return (need/d+1)*perl;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,minn=2e9,sum=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&v[i]);
        sum+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        minn=std::min(minn,a[i]);
    }
    if(minn==a[1])
    {
        if(sum%minn==0) printf("%d",sum/minn);
        else printf("%d",sum/minn+1);
        return 0;
    }
    int tonow=a[1],ans=cal(d,tonow,v[1]);
    for(int i=2;i<n;i++)
    {
        tonow=std::min(tonow,a[i]);
        ans+=cal(d,tonow,v[i]);
    }
    printf("%d",ans);
    return 0;
}