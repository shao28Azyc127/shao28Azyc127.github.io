#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,xx,yy,xxx,yyy,xr,yr,kx,ky,px,vx,py,vy;
int main(){
        freopen("expand.in","r",stdin);
        freopen("expand.out","w",stdout);
        cin>>c>>n>>m>>q;
        for (int i=1;i<=n-1;i++){
                cin>>xr;}
        cin>>xx;
        for (int i=1;i<=m-1;i++){
                cin>>xr;}
        cin>>yy;
        if(xx<yy){cout<<"1";}
        else{cout<<"0";}
while(q--){
        cin>>kx>>ky;
        while(kx--){
                cin>>px>>vx;
                if(px==n){xx=vx;}
        }while(ky--){
                cin>>py>>vy;
                if(py==m){yy=vy;}
        }
        if(xx<yy){cout<<"1";}
        else{cout<<"0";}
}
return 0;}


// Nov.18, 2023 NOIP
//By Tim Kevin
//Beijing, P.R.China
