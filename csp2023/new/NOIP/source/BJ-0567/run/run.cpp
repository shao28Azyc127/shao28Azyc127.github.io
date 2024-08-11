#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int N=1e3+5,M=1e5+5;
int dp[N][N];
int n,m,k,d;
int c,T;
struct Triumph
{
    int day,rqrd,v;
}t[M];
struct Segs
{
    int l,r,val;
}seg[M];
int tag[M];
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
int jik[101],pos;
void decode(int p)
{
    pos=0;
    while(p) {jik[++pos]=p%2;p/=2;}
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    c=read(),T=read();
    if(c==1||c==2)
    {
        while(T--)
        {
            memset(tag,0,sizeof(tag));
            int n=read(),m=read(),k=read(),d=read();
            for(int i=1;i<=m;i++) t[i].day=read(),t[i].rqrd=read(),t[i].v=read(),tag[t[i].day]=i;
            int ans=-9999999;
            for(int cur=0;cur<pow(2,n);cur++)
            {
                decode(cur);
                int len=0;
                for(int j=1;j<=n;j++)
                {
                    if(jik[j]==1) len++;
                    else len=0;
                }
                if(len>k) continue;
                int cene=0;
                for(int i=1;i<=n;i++)
                {
                    if(tag[i])
                    {
                        bool flag=true;
                        for(int j=i;j>=(i-t[tag[i]].rqrd+1);j--) if(!jik[j]) flag=false;
                        if(flag) cene+=t[tag[i]].v; 
                    }
                    if(jik[i]) cene-=d;
                }
                ans=max(ans,cene);
            }
            cout<<ans<<endl;
        }
    }
    if(c==17||c==18)
    {
        while(T--)
        {
            int n=read(),m=read(),k=read(),d=read();

            for(int i=1;i<=m;i++)
            {
                t[i].day=read(),t[i].rqrd=read(),t[i].v=read();
                seg[i].l=t[i].day-t[i].rqrd+1;
                seg[i].r=t[i].day;
                seg[i].val=t[i].v;

            }
            // cout<<"ok"<<endl;
            int ans=0LL;
            for(int i=1;i<=m;i++)
            {
                if(seg[i].val>d*(seg[i].r-seg[i].l+1) && (seg[i].r-seg[i].l+1)<=k) ans+=seg[i].val-d*(seg[i].r-seg[i].l+1);
            }
            printf("%lld\n",ans);
        }
        
    }
    return 0;
}