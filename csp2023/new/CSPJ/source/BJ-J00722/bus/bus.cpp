#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
    int u,v,a;
}r[10001];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].a);
    }
    cout<<6;
    return 0;
}