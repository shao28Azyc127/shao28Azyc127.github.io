#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int MAXM=1e5+5;
struct Node
{
    int x,y,v;
}a[MAXM];
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        int n,m,k,d;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
        if(c==17||c==18)
        {
            int tot=0;
            for(int i=1;i<=m;i++)
            {
                if(a[i].y>k) continue;
                int dv=a[i].v-a[i].y*d;
                if(dv>0) tot+=dv;
            }
            printf("%lld\n",tot);
        }
    }
    return 0;
}