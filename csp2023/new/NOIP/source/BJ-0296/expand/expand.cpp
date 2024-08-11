#include<bits/stdc++.h>
using namesace std;
int c,n,m,q,x[500005],y[500005],kx,ky,px,vx,py,vy;
void slv1(){
    cout<<x[1]!=y[1];
    while(q--){
        cin>>kx>>ky;
        while(kx--){
            cin>>px>>vx;
            x[px]=vx;
        }
        while(ky--){
            cin>>py>>vy;
            y[py]=vy;
        }
        cout<<x[1]!=y[1];
    }return;
}
void slv2(){
    cout<<(x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2]);
    while(q--){
        cin>>kx>>ky;
        while(kx--){
            cin>>px>>vx;
            x[px]=vx;
        }
        while(ky--){
            cin>>py>>vy;
            y[py]=vy;
        }
        cout<<0;
    }return;
}
void slv4(){
    cout<<(x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2]);
    while(q--){
        cin>>kx>>ky;
        while(kx--){
            cin>>px>>vx;
            x[px]=vx;
        }
        while(ky--){
            cin>>py>>vy;
            y[py]=vy;
        }
        cout<<1;
    }return;
}
void slv3(){
    if(n==1){
    cout<<(x[1]>y[1]&&x[1]>y[2])||(x[1]<y[1]&&x[1]<y[2]);
    while(q--){
        cin>>kx>>ky;
        while(kx--){
            cin>>px>>vx;
            x[px]=vx;
        }
        while(ky--){
            cin>>py>>vy;
            y[py]=vy;
        }
        cout<<(x[1]>y[1]&&x[1]>y[2])||(x[1]<y[1]&&x[1]<y[2]);
    }}
    else{
    cout<<(x[1]>y[1]&&x[2]>y[1])||(x[1]<y[1]&&x[2]<y[1]);
    while(q--){
        cin>>kx>>ky;
        while(kx--){
            cin>>px>>vx;
            x[px]=vx;
        }
        while(ky--){
            cin>>py>>vy;
            y[py]=vy;
        }
        cout<<(x[1]>y[1]&&x[2]>y[1])||(x[1]<y[1]&&x[2]<y[1]);
    }  
    }return;
}
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
    if(c==1){
        slv1();
    }
    if(c==2){
        if(n==1||y==1)slv3();
        else slv2();
    }
    if(c>2)slv4();
    return 0;
}