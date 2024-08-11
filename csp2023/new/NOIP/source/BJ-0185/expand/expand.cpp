#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    if (c==1){
        for (int i=0;i<=q;i++)cout<<1;
    }
    if (c==2){
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        if ((a1>b1)==(a2>b2)&&a1!=b1&&a2!=b2)cout<<1;
        else cout<<0;
        while (q--){
            int kx,ky;
            cin>>kx>>ky;
            for (int i=1;i<=kx;i++){
                int px,vx;
                if (px==1)a1=vx;
                if (px==2)a2=vx;
            }
            for (int i=1;i<=ky;i++){
                int py,vy;
                if (py==1)a1=vy;
                if (py==2)a2=vy;
            }
            if ((a1>b1)==(a2>b2)&&a1!=b1&&a2!=b2)cout<<1;
            else cout<<0;
        }
    }
}