#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,d,v;
long long ans,lt;
long long dis[MAXN],p[MAXN];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&v);
        dis[i]=dis[i-1]+v;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&p[i]);
    }
    p[n]=0;
    int cur=1,nxt;
    while(cur!=n)
    {
        for(int i=cur+1;i<=n;i++)
        {
            if(p[i]<p[cur])
            {
                nxt=i;
                break;
            }
        }
        long long l=ceil((double)(dis[nxt]-dis[cur]-lt)/d);
        ans+=p[cur]*l;
        lt=d*l-(dis[nxt]-dis[cur]-lt);
        cur=nxt;
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
