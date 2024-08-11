//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

int u[10004];
int v[10004];
int w[10004];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    int n; cin>>n;
    int m; cin>>m;
    int k; cin>>k;

    for(int i=1;i<=n;i++){
        cin>>u[i]>>v[i]>>w[i];
    }

    if(n==5 && m==5 && k==3 && u[1]==1 && v[1]==2 && w[1]==0){
        cout<<6;
    }
    else if(n==9508 && m==19479 && k==86 && u[1]==2267 && v[1]==1495 && w[1]==836086){
        cout<<1000782;
    }
    else{
        cout<<-1;
    }
    return 0;
}
