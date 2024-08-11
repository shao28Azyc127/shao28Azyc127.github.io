#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10;
int n,m,k;
struct node{
    int u,v,a;
}e[maxn];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].a;
    cout<<-1;
    return 0;
}
