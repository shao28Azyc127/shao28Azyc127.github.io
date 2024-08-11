#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Challen{
    int x,y,z;
};
vector<Challen> vc;
bool cmp(Challen a,Challen b)
{
    return a.x<b.x;
}
int n,m,k,d;
int maxx=-1e18;
void dfs(int day,int ener,int last,int id)
{
    if(last>k) return ;
    if(day==n)
    {
        maxx=max(maxx,ener);
        return ;
    }
    while(vc[id].x<day) id++;
    if(vc[id].x==day && last>=vc[id].y)
    {
        dfs(day+1,ener+vc[id].z-d,last+1,id);
        dfs(day+1,ener+vc[id].z,0,id);
        return ;
    }
    dfs(day+1,ener-d,last+1,id);
    dfs(day+1,ener,0,id);
}
void work()
{
    scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
    vc.clear();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        vc.push_back((Challen){x,y,z});
    }
    sort(vc.begin(),vc.end(),cmp);
    maxx=-1e18;
    dfs(0,0,0,0);
    printf("%lld\n",maxx);
}
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        work();
    }
    return 0;
}
