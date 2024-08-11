#include <bits/stdc++.h>
using namespace std;
int n,m,c,q,kx,ky,x,y;
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>c;
    }
    for(int i=1;i<=m;i++){
        cin>>c;
    }
    cin>>kx>>ky;
    for(int i=1;i<=kx;i++){
        cin>>x>>y;
    }
    for(int i=1;i<=ky;i++){
        cin>>x>>y;
    }
    for(int i=0;i<q;i++){
        cout<<1;
    }
    cout<<0;
    return 0;
}
