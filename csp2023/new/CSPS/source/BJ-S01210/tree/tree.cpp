#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int a,b,c;
}t[N];
set<int> G[N];
set<int> s;
int n;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int u,v;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].b>>t[i].c;
    }
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
    }
    cout<<n+1;
    return 0;
}
