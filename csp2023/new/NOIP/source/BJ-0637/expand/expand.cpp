#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,q;
int x,y;
int _x;
int _y;
int kx,ky;
int px,vx;
int py,vy;

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    if(c==1){
            for(int i=1;i<=n;i++) cin>>_x;
    for(int i=1;i<=m;i++) cin>>_y;
    for(int i=1;i<=n;i++){
        if(_x!=_y) cout<<"1";
        else cout<<"0";
    }
    while(q--){
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++){
            cin>>px>>vx;
        }
        for(int i=1;i<=ky;i++){
            cin>>py>>vy;
        }
        if(kx==0 && ky!=0){
            if(x!=ky) cout<<"1";
            else cout<<"0";
        }
        else if(kx!=0 && ky==0){
            if(kx!=y) cout<<"1";
            else cout<<"0";
        }
        else if(kx==0 && ky==0){
            if(x!=y) cout<<"1";
            else cout<<"0";
        }
        else{
            if(kx!=ky) cout<<"1";
            else cout<<"0";
        }
    }
    }
    return 0;
}
