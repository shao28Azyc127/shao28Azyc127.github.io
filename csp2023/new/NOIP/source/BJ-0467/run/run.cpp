#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int tid,T;
int n,m,K,d;
struct nd{int len,v;};
vector<nd> g[N];
bool cmp(nd i,nd j){return i.len<j.len;}
int f[2][N],mx[2],now=1,pre;
int f2[N],totlen[N];
void work(){
    int prer=-1,prel=-1,len,l,r,v;
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&K,&d);
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&r,&len,&v);
            if(len>K)continue;
            l=r-len+1;
            if(l==prer+1 && totlen[i-1]+len>K)
                f2[i] = f2[i-2] - len*d + v;
            else f2[i] = f2[i-1] - len*d + v;
            f2[i] = max(f2[i-1],f2[i]);
            prer=r;
        }
        printf("%lld\n",f2[m]);
    }
}

signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>tid>>T;
    if(tid>14){work();return 0;}
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&K,&d);
        for(int i=1;i<=n;i++)g[i].clear();
        memset(f,0,sizeof f);
        memset(mx,0,sizeof mx);
        for(int i=1;i<=m;i++){
            int r,len,v;scanf("%lld%lld%lld",&r,&len,&v);
            if(len>K)continue;
            g[r].push_back(nd{len,v});
        }
        for(int i=1;i<=n;i++)
            sort(g[i].begin(),g[i].end(),cmp);
        for(int i=1;i<=n;i++){
            swap(now,pre);
            f[now][0]=mx[pre];
            mx[now]=f[now][0];
            int k=0,sum=0;
            for(int j=1;j<=K;j++){
                while(k<g[i].size() && j>=g[i][k].len)
                    sum+=g[i][k++].v;
                f[now][j]=f[pre][j-1]-d+sum;
                mx[now]=max(f[now][j],mx[now]);
                //printf("%lld ",f[i][j]);
            }//puts("");
        }
        printf("%lld\n",mx[now]);
    }
    return 0;
}
