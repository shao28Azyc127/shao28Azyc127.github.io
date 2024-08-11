#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,x[500005],y[500005],X[500005],Y[500005],kx,ky,a,b;
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>X[i],x[i]=X[i];
    for(int i=1;i<=m;i++)cin>>Y[i],y[i]=Y[i];
    cout<<(x[1]!=y[1]);
    while(q--){
        cin>>kx>>ky;
        while(kx--)cin>>a>>b,x[a]=b;
        while(ky--)cin>>a>>b,y[a]=b;
        cout<<(x[1]!=y[1]);
        for(int i=1;i<=n;i++)x[i]=X[i];
        for(int i=1;i<=m;i++)y[i]=Y[i];
    }
    return 0;
}
