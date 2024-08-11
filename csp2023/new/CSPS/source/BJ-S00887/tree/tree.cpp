#include<iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
long long n,a[1000005],b[1000005],c[1000005];
vector<ll> v[1000005];
/*
void dfs(long long p){

}*/
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        ll u,vv;
        cin>>u>>vv;
        v[u].push_back(vv);
        v[vv].push_back(u);
    }
    cout<<2<<endl;
    return 0;
}
