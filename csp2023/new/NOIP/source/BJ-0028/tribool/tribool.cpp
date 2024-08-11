#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001;
int n,m;
int a[MAXN];
int v[MAXN];
bool b[MAXN];
void dfs(int u){
    v[u]=1;
    if(a[u]==-1){
        v[u]=2;
        return;
    }
    if(a[u]==0){
        v[u]=2;
        return;
    }
    if(a[u]<=n){
        if(v[a[u]]==2){
            v[u]=2;
            a[u]=a[a[u]];
            return;
        }
        if(v[a[u]]==1){
            v[u]=2;
            if(b[a[u]]==b[u])a[u]=0;
            else a[u]=-1;
            return;
        }
        b[a[u]]=b[u];
        dfs(a[u]);
        v[u]=2;
        a[u]=a[a[u]];
        return;
    }
    else{
        a[u]-=n;
        if(v[a[u]]==2){
            v[u]=2;
            a[u]=a[a[u]];
            return;
        }
        if(v[a[u]]==1){
            v[u]=2;
            if(b[a[u]]!=b[u])a[u]=0;
            else a[u]=-1;
            return;
        }
        b[a[u]]=b[u]^1;
        dfs(a[u]);
        v[u]=2;
        a[u]=a[a[u]];
        return;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)a[i]=i,v[i]=0;
        while(m--){
            char op[2];
            int i,j;
            cin>>op>>i;
            if(op[0]=='T'||op[0]=='F')a[i]=0;
            if(op[0]=='U')a[i]=-1;
            if(op[0]=='+'){
                cin>>j;
                a[i]=a[j];
            }
            if(op[0]=='-'){
                cin>>j;
                if(a[j]<1)a[i]=a[j];
                else if(a[j]<=n)a[i]=a[j]+n;
                else a[i]=a[j]-n;
            }
        }
        for(int i=1;i<=n;i++){
            if(!v[i]){
                b[i]=1;
                dfs(i);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)if(a[i]==-1)ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
