#include<bits/stdc++.h>
using namespace std;
int n,m,h=1e9,ku[20004],v[20004],a[20004];
map<int,int>p[20004];
struct{
    int a[100],b,c[100];
}o[20004];
int dfs(int j,int z){
    if(j==n){
        h=min(h,z);
        return 0;
    }
    if(z>h){
        return 0;
    }
    for(int i=1;i<=m;i++){
        if(o[u[i]].c[++o[u[i]].b]<=z)
        dfs(o[j].a[i],z++);
    }
    return 0;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>a[i];
        o[u[i]].a[++o[u[i]].b]=v[i];
        o[u[i]].c[++o[u[i]].b]=a[i];
    }
    if(k==1){
        dfs(1,0);
        cout<<h<<endl;
        return 0;
    }
    cout<<"-1"<<endl;
    return 0;
}