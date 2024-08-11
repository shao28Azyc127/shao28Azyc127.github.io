#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    int a,b,c;
} a[100005];
vector<int> g[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i].a>>a[i].b>>a[i].c;
    }
    for(int i=1;i<n;i++){
        int u,v;cin >>u>>v;
        g[u].push_back(v);
    }
    cout <<n;
    return 0;
}
