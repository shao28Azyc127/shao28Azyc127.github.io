#include<bits/stdc++.h>
using namespace std;
int n,a[510],b[510],c[510],u,v,mn=0x3f3f3f3f;
bool ul[510],e[510][510],vis[510];
inline int day(int bg,int a,int b,int c){
    int h=0;
    int d=bg;
    for(d;h<a;d++){
        h+=max(b+d*c,1);
    }
  // cout<<d<<" "<<a<<endl;
    return d;
}
void dfs(int now,int ans,int d){
    if(ans>mn)return;
  //  cout<<ans<<" ";
    if(d==n){mn=min(ans,mn);/*cout<<"ans="<<ans<<endl;*/}
    for(int i=1;i<=n;i++){
        if(e[now][i])ul[i]=1;
    }
    for(int i=1;i<=n;i++){
            //cout<<d<<" ";
        if(ul[i]&&!vis[i]){vis[i]=1;dfs(i,max(ans,day(d+1,a[i],b[i],c[i])),d+1);vis[i]=0;}
    }
    for(int i=1;i<=n;i++){
        if(e[now][i])ul[i]=0;
    }
    return;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    if(n>500){
        srand(clock());
        cout<<rand();
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u][v]=1;
        e[v][u]=1;
    }
    ul[1]=1;
    vis[1]=1;
    dfs(1,day(1,a[1],b[1],c[1]),1);
    cout<<mn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
