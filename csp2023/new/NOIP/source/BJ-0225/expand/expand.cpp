#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,q;
int x[500005],y[500005];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
    }
    cout<<(x[1]!=y[1]);
    while(q--){
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++){
            int p,v;
            cin>>p>>v;
            x[p]=v;
        }
        for(int i=1;i<=ky;i++){
            int p,v;
            cin>>p>>v;
            y[p]=v;
        }
        cout<<(x[1]!=y[1]);
    }
    return 0;
}