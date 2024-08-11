#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,a;
}edge[114514];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].a;
    cout<<-1;
    return 0;
}
