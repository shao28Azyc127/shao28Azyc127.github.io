#include<iostream>
#include<vector>
using namespace std;
struct sss{
    int type,x,y;
}s[100005];
int c,t,n,m;
int zt[100005],ans=0,zt2[100005],color[100005],vis[100005];
vector<int> ss[100005];
bool check(){
    for(int i=1;i<=n;i++){
        zt2[i]=zt[i];
    }
    for(int i=1;i<=m;i++){
        int x=s[i].x,y=s[i].y;
        if(s[i].type==1){
            zt[x]=y;
        }else if(s[i].type==2){
            zt[x]=zt[y];
        }else if(s[i].type==3){
            if(zt[y]==1) zt[x]=2;
            else if(zt[y]==2) zt[x]=1;
            else if(zt[y]==3) zt[x]=3;
        }
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(zt2[i]!=zt[i]){
            flag=1;
        }
        zt[i]=zt2[i];
    }
    if(flag==1) return false;
    return true;
}
void dfs(int now){
    if(now==n+1){
        if(check()){
            int sum=0;
            for(int i=1;i<=n;i++){
                if(zt[i]==3) sum++;
            }
            ans=min(ans,sum);
        }
        return;
    }
    for(int i=1;i<=3;i++){
        zt[now]=i;
        dfs(now+1);
    }
}
void dfs2(int now){
    if(vis[now]==1) return;
    vis[now]=1;
    color[now]=1;
    for(int i=0;i<ss[now].size();i++){
        dfs2(ss[now][i]);
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        if(c==1||c==2){
            for(int i=1;i<=m;i++){
                char c;
                cin>>c;
                if(c=='+'){
                    s[i].type=2;
                    cin>>s[i].x>>s[i].y;
                }else if(c=='-'){
                    s[i].type=3;
                    cin>>s[i].x>>s[i].y;
                }else{
                    s[i].type=1;
                    cin>>s[i].x;
                    if(c=='T'){
                        s[i].y=1;
                    }else if(c=='F'){
                        s[i].y=2;
                    }else{
                        s[i].y=3;
                    }
                }
            }
            ans=1e9;
            dfs(1);
            cout<<ans<<endl;
        }else if(c==3||c==4){
            for(int i=1;i<=m;i++){
                int x;
                char c;
                cin>>c>>x;
                if(c=='T'){
                    zt[x]=1;
                }else if(c=='F'){
                    zt[x]=2;
                }else{
                    zt[x]=3;
                }
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                if(zt[i]==3){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }else if(c==5||c==6){
            ans=0;
            for(int i=1;i<=m;i++){
                char c;
                cin>>c;
                if(c=='U'){
                    int x;
                    cin>>x;
                    color[x]=1;
                }else if(c=='+'){
                    int x,y;
                    cin>>x>>y;
                    ss[y].push_back(x);
                }
            }
            for(int i=1;i<=n;i++){
                if(color[i]==1&&vis[i]==0){
                    dfs2(i);
                }
            }
            for(int i=1;i<=n;i++){
                if(color[i]==1){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }else if(c==7||c==8){
            return 0;
        }
    }
    return 0;
}
