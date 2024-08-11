#include <bits/stdc++.h>
using namespace std;
int cpoint;
int t;
int T;
int n,m;
struct node{
    int c,v,u;
}inpt[100005];
int a[100005];
int ap[15];
int colorsame[100005];
int colcnt;
int ans=2147483647;
bool vis[100005];

int getf(int x){
    if(vis[x]){
        return x;
    }
    vis[x]=1;
    if(colorsame[x]==0){
        return 0;
    }
    if(colorsame[x]==x){
        return x;
    }
    return colorsame[x]=getf(colorsame[x]);
}

void dfs(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++){
            ap[i]=a[i];
        }
        for(int i=1;i<=m;i++){
            char ch;
            int u,v;
            ch = inpt[i].c;
            u = inpt[i].u;
            v = inpt[i].v;
            if(ch=='+'){
                    ap[v]=ap[u];
            }
            if(ch=='-'){
                    ap[v]=-ap[u];
            }
            if(ch=='T'){
                    ap[v]=1;
            }
            if(ch=='F'){
                    ap[v]=-1;
            }
            if(ch=='U'){
                    ap[v]=0;
            }
        }
        bool cheeck=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=ap[i]){
                cheeck=0;
                break;
            }
        }
        if(cheeck){
            ans=min(ans,colcnt);
        }
        return;
    }
    for(int i=-1;i<=1;i++){
        a[k]=i;
        if(i==0){
            colcnt++;
        }
        dfs(k+1);
        if(i==0){
            colcnt--;
        }
    }
}


int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>cpoint>>T;
    while(T--){
        cin>>n>>m;
        if(cpoint<=2){
            ans=2147483647;
            for(int i=1;i<=m;i++){
                char ch;
                int u=0,v;
                cin>>ch;
                if(ch=='+'){
                        cin>>v>>u;
                }
                if(ch=='-'){
                        cin>>v>>u;
                }
                if(ch=='T'){
                        cin>>v;
                }
                if(ch=='F'){
                        cin>>v;
                }
                if(ch=='U'){
                        cin>>v;
                }
                inpt[i].c=ch;
                inpt[i].v=v;
                inpt[i].u=u;
            }
            dfs(1);
            cout<<ans<<endl;
        }
        if(cpoint>2&&cpoint<=4){
            ans=0;
            memset(a,0,sizeof(a));
            for(int i=1;i<=m;i++){
                char ch;
                int v;
                cin>>ch;
                if(ch=='T'){
                    cin>>v;
                    a[v]=1;
                }
                if(ch=='F'){
                    cin>>v;
                    a[v]=-1;
                }
                if(ch=='U'){
                    cin>>v;
                    a[v]=-2;
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i]==-2){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
        if(cpoint>4&&cpoint<=6){
            ans=0;
            for(int i=1;i<=n;i++){
                colorsame[i]=i;
            }
            for(int i=1;i<=m;i++){
                char ch;
                int v,u;
                cin>>ch;
                if(ch=='+'){
                    cin>>v>>u;
                    colorsame[v]=u;
                }
                if(ch=='U'){
                    cin>>v;
                    colorsame[v]=0;
                }
                inpt[i].c=ch;
                inpt[i].v=v;
                inpt[i].u=u;
            }
            for(int i=m;i>=1;i--){
                char ch;
                int v,u;
                ch=inpt[i].c;
                v=inpt[i].v;
                u=inpt[i].u;
                if(ch=='+'){
                    if(colorsame[v]==v)
                    {
                        colorsame[v]=u;
                    }
                }
                if(ch=='U'){
                    if(colorsame[v]==v)
                    {
                        colorsame[v]=0;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                memset(vis,0,sizeof(vis));
                if(getf(i)==0){
                    ans++;
                }

            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
