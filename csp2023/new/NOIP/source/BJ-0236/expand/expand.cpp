#include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
const int N=5e5+4;
int x[N],y[N];
void ask(){
    if(n==1) cout<<1;
    else{
        if(x[1]>y[1]&&x[2]>y[2]) cout<<1;
        else if(x[1]<y[1]&&x[2]<y[2]) cout<<1;
        else cout<<0;
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int j=1;j<=m;j++) cin>>y[j];
    ask();
    while(q--){
        int k1,k2;
        cin>>k1>>k2;
        int p,k;
        for(int i=1;i<=k1;i++) cin>>p>>k,x[p]=k;
        for(int i=1;i<=k2;i++) cin>>p>>k,y[p]=k;
        ask();
    }
    return 0;
}