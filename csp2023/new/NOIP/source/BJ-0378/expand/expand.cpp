#include <bits/stdc++.h>
using namespace std;
int x[500005],y[500005],tx[500005],ty[500005];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=m;i++) scanf("%d",&y[i]);
    if(x[1]==y[1]||x[n]==y[m]) cout<<0;
    else if(x[1]>y[1]&&x[n]<y[m]||x[1]<y[1]&&x[n]>y[m]) cout<<0;
    else{
        int f=1;
        if(x[1]>y[1]){
            for(int i=1;i<min(n,m);i++){
                if(x[i]<=y[i] && x[i]<=y[i+1] && y[i]>=x[i+1]) f=0;
            }
        }else{
            for(int i=1;i<min(n,m);i++){
                if(x[i]>=y[i] && x[i]>=y[i+1] && y[i]<=x[i+1]) f=0;
            }
        }
        cout<<f<<'\n';
    }
    while(q--){
        for(int i=1;i<=n;i++) tx[i]=x[i];
        for(int i=1;i<=m;i++) ty[i]=y[i];
        int kn,km;cin>>kn>>km;
        for(int i=1;i<=kn;i++){
            int p,v;cin>>p>>v;
            tx[p]=v;
        }
        for(int i=1;i<=km;i++){
            int p,v;cin>>p>>v;
            ty[p]=v;
        }
        for(int i=1;i<=n;i++) cout<<tx[i]<<' ';
        cout<<'\n';
        for(int i=1;i<=m;i++) cout<<ty[i]<<' ';
        cout<<'\n';
        if(tx[1]==ty[1]||tx[n]==ty[m]) cout<<0;
        else if(tx[1]>ty[1]&&tx[n]<ty[m]||tx[1]<ty[1]&&tx[n]>ty[m]) cout<<0;
        else{
            int f=1;
            if(tx[1]>ty[1]){
                for(int i=1;i<min(n,m);i++){
                    if(tx[i]<=ty[i] && tx[i]<=ty[i+1] && ty[i]>=tx[i+1]) f=0;
                }
            }else{
                for(int i=1;i<min(n,m);i++){
                    if(tx[i]>=ty[i] && tx[i]>=ty[i+1] && ty[i]<=tx[i+1]) f=0;
                }
            }
            cout<<f<<'\n';
        }
    }
    return 0;
}
//freopen("expand.in","r",stdin);
/*NOIPRP++*/
