#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#define int long long
using namespace std;
const int N=1e5+5;
int n;
int tot,head[N],ver[N<<1],nxt[N<<1];
struct Land
{
    int a,b,c;
    int rt;
    int days_rqrd;
}t[N];
int ans;
priority_queue<pair<int,int> > q;
bool havetree[N];
int dep[N];
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
void add(int x,int y)
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
void TaskA()
{
    for(int i=1;i<=n;i++) t[i].rt=max((int)t[i].b,(int)1);
    for(int i=1;i<=n;i++)
    {
        bool tmp=t[i].a%t[i].rt;
        t[i].days_rqrd=t[i].a/t[i].rt+tmp+dep[i];
    } 
    q.push(make_pair(t[1].days_rqrd,1));
    int curd=-1;
    while(!q.empty())
    {
        curd++;
        int cur=q.top().second;
        q.pop();
        if(havetree[cur]) continue;
        havetree[cur]=true;
        ans=max((int)ans,t[cur].days_rqrd);
        for(int i=head[cur];i;i=nxt[i])
        {
            int xt=ver[i];
            if(!havetree[xt]) q.push(make_pair(t[xt].days_rqrd,xt));
        }
    }
    printf("%lld\n",ans);
}
void getdep(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=ver[i];
        if(v==fa) continue;
        getdep(v,u);
    }
}
bool check(int daysb,int id)
{
    if(t[id].a<(t[id].b*daysb+(id+daysb)*(daysb-id+1)/2*t[id].c))
        return true;
    return false;
}
void TaskB(int ifoutput)
{
    int kaka=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i].c>0)
        {
            int l=i,r=1000000001;
            int mid;
            while(l<r)
            {
                mid=(l+r)>>1;
                if(check(mid,i)) r=mid-1;
                else l=mid+1;
            }
            t[i].days_rqrd=mid;
        }
        else if(t[i].c==0)
        {
            t[i].rt=max((int)t[i].b,(int)1);
            bool tmp=t[i].a%t[i].rt;
            t[i].days_rqrd=t[i].a/t[i].rt+tmp;
        } 
        else
        {
            int finallyitcomes=t[i].b/t[i].c;
            int atdoomsday=t[i].b*finallyitcomes+t[i].c*(i+finallyitcomes)*(finallyitcomes-i+1)/2;
            if(atdoomsday>t[i].a) 
            {
                int l=i,r=atdoomsday;
                int mid;
                while(l<r)
                {
                    mid=(l+r)>>1;
                    if(check(mid,i)) r=mid-1;
                    else l=mid+1;
                }
                t[i].days_rqrd=mid;
            }
            else t[i].days_rqrd=atdoomsday+(t[i].a-atdoomsday);
        }
        // cout<<t[i].days_rqrd<<" ";
        t[i].days_rqrd-=2;
        kaka=max(kaka,t[i].days_rqrd+i);
    }
    if(ifoutput) cout<<kaka<<endl;
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    int flag1=1,flag2=1,flag3=1;
    for(int i=1;i<=n;i++)
    {
        t[i].a=read(),t[i].b=read(),t[i].c=read();
        if(t[i].c!=0) flag1=0;
    } 
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        add(x,y),add(y,x);
        // if(x>y) swap(x,y);
        if(x!=i || y!=i+1) flag2=0;
        if(x!=1) flag3=0;
    }
    dep[0]=-1;
    getdep(1,0);
    if(flag1) TaskA();
    else if(flag2) TaskB(1);
    return 0;
}
/*
4
12 1 1
2 4 -1
10 3 0
7 10 -2
1 2
2 3
3 4
*/