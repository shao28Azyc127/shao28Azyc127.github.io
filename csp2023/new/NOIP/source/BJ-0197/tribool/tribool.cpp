#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[100005];
char a[100005];
bool vis[100005];
int find(int x){
    bool t=false;
    if(x<0){
        x=-x;
        t=true;
    }
    if(abs(f[x])==x){
        if(t) return -f[x];
        return f[x];
    }
    if(vis[x]){
        if(t) return -x;
        return x;
    }
    vis[x]=true;
    f[x]=find(f[x]);
    vis[x]=false;
    //cout<<"x="<<x<<" f[x]="<<f[x]<<endl;
    if(t) return -f[x];
    return f[x];
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t;
    cin>>c>>t;
    while(t--){
        int n, m, ans=0;
        cin>>n>>m;
        memset(a, 'T', sizeof(a));
        if(c==3||c==4){
            for(int i=1;i<=m;i++){
                char opt;
                cin>>opt;
                int x;
                cin>>x;
                a[x]=opt;
            }
            for(int i=1;i<=n;i++){
                if(a[i]=='U') ans++;
            }
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=m;i++){
            char opt;
            cin>>opt;
            if(opt=='U'||opt=='F'||opt=='T'){
                int x;
                cin>>x;
                a[x]=opt;
            }
            else if(opt=='+'){
                int x, y;
                cin>>x>>y;
                f[x]=y;
            }
            else if(opt=='-'){
                int x, y;
                cin>>x>>y;
                f[x]=-y;
            }
        }
        for(int i=1;i<=n;i++){
            f[i]=find(i);
            a[i]=a[abs(f[i])];
            if(f[i]==-i){
                a[i]='U';
            }
            //cout<<f[i]<<" ";
        }
        for(int i=1;i<=n;i++){
            a[i]=a[abs(f[i])];
            if(a[i]=='U') ans++;
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
