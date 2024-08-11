#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,f[100005],ans,t[13],f56[100005];
void dfs(int now,int cnt){
    if(cnt>=ans)return;
    if(now>n){
        for(int i=1;i<=n;i++){
            if(f[i]>=2||f[i]<=-2)
            if(t[abs(f[i]/2)]*f[i]/abs(f[i])!=t[i])return;
        }
        ans=min(ans,cnt);
        return;
    }
    if(f[now]!=0&&f[now]!=-1){
        t[now]=1;
        dfs(now+1,cnt);
    }
    if(f[now]!=0&&f[now]!=1){
        t[now]=-1;
        dfs(now+1,cnt);
    }
    if(f[now]!=1&&f[now]!=-1){
        t[now]=0;
        dfs(now+1,cnt+1);
    }
}
vector<int> e[100005];
queue<int> q;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        ans=n;
        for(int i=1;i<=n;i++){
            f[i]=2*i;
        }
        for(int i=1;i<=m;i++){
            char op;
            int x,y;
            cin>>op>>x;
            if(op=='U')f[x]=0;
            if(op=='T')f[x]=1;
            if(op=='F')f[x]=-1;
            if(op=='+'){
                cin>>y;
                f[x]=f[y];
            }
            if(op=='-'){
                cin>>y;
                f[x]=-f[y];
            }
        }
        if(c<=2){
            dfs(1,0);
            cout<<ans<<'\n';
        }else
        if(c<=4){
            for(int i=1;i<=n;i++){
                if(f[i])ans--;
            }
            cout<<ans<<'\n';
        }else
        if(c<=6){
            for(int i=1;i<=n;i++){
                e[i].clear();
            }
            for(int i=1;i<=n;i++){
                if(f[i]==0){
                    q.push(i);
                }else{
                    int v=f[i]/2;
                    if(v!=i){
                        e[i].push_back(v);
                        e[v].push_back(i);
                    }
                }
            }
            memset(f56,0,sizeof(f56));
            while(!q.empty()){
                int u=q.front();q.pop();
                f56[u]=1;
                for(int i=0;i<e[u].size();i++){
                    int v=e[u][i];
                    if(f56[v]==0){
                        f56[v]=1;
                        q.push(v);
                    }
                }
            }
            ans=0;
            for(int i=1;i<=n;i++){
                if(f56[i])ans++;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
