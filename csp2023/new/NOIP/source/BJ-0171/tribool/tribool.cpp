#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int N=1e5+5;
struct NODE{int stat,r;}a[N];
int C,T,n,m,ans,vzf[N],rev;
bool vis[N];
vector<int>g[N],e[N];

bool dfs(int x,int val,int curstat){
    if(vis[x]&&curstat==0){
        if(vzf[x]!=val)return true;
        return false;
    }
    if(vis[x]&&a[x].stat==3)return true;
    vis[x]=true;
    vzf[x]=val;
    if(curstat==1)a[x].stat=3;
    for(auto v:g[x]){
        if(a[x].stat==3||curstat==1){
            dfs(v,val,1);
            return true;
        }
        if(a[v].stat==5){
            if(dfs(v,-val,0)){
                dfs(x,val,1);
                a[x].stat=3;
                return true;
            }
        }
        else{
            if(dfs(v,val,0)){
                dfs(x,val,1);
                a[x].stat=3;
                return true;
            }
        }
    }
    return false;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%d",&n,&m);
        ans=0;
        memset(vis,false,sizeof(vis));
        memset(vzf,false,sizeof(vzf));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)g[i].clear(),e[i].clear();
        while(m--){
            int op,i,j;
            scanf(" %c%d",&op,&i);
            if(op=='T')a[i].stat=1;
            else if(op=='F')a[i].stat=2;
            else if(op=='U')a[i].stat=3;
            else if(op=='+'){
                scanf("%d",&j);
                if(a[j].stat==1||a[j].stat==2||a[j].stat==3)a[i].stat=a[j].stat;
                else{
                    a[i].stat=4;
                    a[i].r=j;
                }
            }
            else{
                scanf("%d",&j);
                if(a[j].stat==1)a[i].stat=2;
                else if(a[j].stat==2)a[i].stat=1;
                else if(a[j].stat==3)a[i].stat=a[j].stat;
                else a[i].stat=5,a[i].r=j;
            }
        }
        for(int i=1;i<=n;i++)
            if(a[i].stat==4||a[i].stat==5)
                g[a[i].r].push_back(i);
        for(int i=1;i<=n;i++){
            rev=0;
            if(!g[i].empty())dfs(i,1,a[i].stat==3?1:0);
        }
        for(int i=1;i<=n;i++){
            if(a[i].stat==3)ans++;//printf("III%d\n",i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
//Workingmen of all countries, unite!