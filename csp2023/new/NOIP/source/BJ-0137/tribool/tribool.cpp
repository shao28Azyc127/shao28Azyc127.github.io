#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[100009];
int v[100009];
bool hs(int i){
    return f[i]==0||(f[i]>1e6||(-f[i])>1e6);
}
void dfs(int x,bool l){
    if(hs(x)){
        return;
    }
    int o;
    o=l;
    o=o*2-1;
    if(v[x]){
        if(o!=v[x]){
            f[x]=0;
        }else{
            f[x]=-1e9;
        }
        return;
    }
    v[x]=o;
    int x1;
    bool l1;
    if(f[x]<0){
        l1=!l;
        x1=-f[x];
    }else{
        l1=l;
        x1=f[x];
    }
    dfs(x1,l1);
    if(f[x]<0){
        f[x]=-f[x1];
    }else{
        f[x]=f[x1];
    }
}
void _main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        f[i]=i;
        v[i]=0;
    }
    for(int i=1;i<=m;i++){
        char t;
        cin>>t;
        if(t=='+'){
            int x,y;
            cin>>x>>y;
            f[x]=f[y];

        }else if(t=='-'){
            int x,y;
            cin>>x>>y;
            f[x]=-f[y];
        }else if(t=='T'){
            int x;
            cin>>x;
            f[x]=1e9;
        }else if(t=='F'){
            int x;
            cin>>x;
            f[x]=-1e9;
        }else if(t=='U'){
            int x;
            cin>>x;
            f[x]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(!hs(i)){
            dfs(i,1);
        }
    }
    int ans;
    ans=0;
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int id,t;
    cin>>id>>t;
    while(t--){
        _main();
    }
    return 0;
}
