#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
struct aa{ll u,v,a;} l[20005];
ll c[10005][10005];
bool vis[10005];
ll vt[10005],vmin_ct[10005],plann=0;
ll min_ans=0x7fffffff;
void dfs(ll x,ll t,ll min_ct)//wei zhi yu lu shang de yong shi
{
    vis[x]=1;
    if(x==n)//dao da zhong dian
    {
        //cout<<"F";//debug
        vis[x]=0;
        if(t%k==0)//zheng chu
            vt[++plann]=t,vmin_ct[plann]=min_ct;//fang an
        //printf("[%lld]Plan%lld:t%lld min_ct%lld\n",!bool(t%k),plann,t,min_ct);
        return ;
    }
    for(ll i=1;i<=n;i++)//mei ju mu biao dian
        if(c[x][i]!=0&&!vis[i])//lin jie ju zhen biao shi neng dao da i wei zhi
        {
            //printf("fr%lld to%lld t%lld\n",x,i,t+1);
            dfs(i,t+1,max(min_ct,l[c[x][i]].a-t));
            vis[i]=0;
        }
        //else printf("Err:fr%lld to%lld because c%lld vis%lld\n",x,i,c[x][i],vis[i]);
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&l[i].u,&l[i].v,&l[i].a);
        c[l[i].u][l[i].v]=i;//lin jie ju zhen ji lu bian de bian hao
    }
    dfs(1,0,0);
    for(ll i=1;i<=plann;i++)
    {
        //printf("%lld %lld\n",vt[i],vmin_ct[i]);
        min_ans=vt[i]+vmin_ct[i]+bool(vmin_ct[i]%k);
    }
    if(min_ans==0x7fffffff)
        printf("-1");
    else
        printf("%lld",min_ans);
    return 0;
}
//
/*
in1:
5 5 3
1 2 0
2 5 1
1 3 0
3 4 3
4 5 1
out1:
6
*/

/*
tool:
sort in:
#include <bits/stdc++.h>
using namespace std;
struct len{long long u,v,a;}l[1000005];
bool cmp(len x,len y){
    if(x.u>y.u) return 0;
    else if(x.u<y.u) return 1;
    else
        if(x.v>y.v) return 0;
        else return 1;
}
int main(){
    freopen("bus2.in","r",stdin);freopen("bus2_sorted.in","w",stdout);
    long long n,m,k;cin>>n>>m>>k;printf("%lld %lld %lld\n",n,m,k);
    for(long long i=1;i<=n;i++) scanf("%lld%lld%lld",&l[i].u,&l[i].v,&l[i].a);
    sort(l+1,l+1+n,cmp);
    for(long long i=1;i<=n;i++) printf("%lld %lld %lld\n",l[i].u,l[i].v,l[i].a);
    return 0;
}
*/
