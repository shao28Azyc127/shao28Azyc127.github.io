#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,Q;
ll x[500001],y[500001];
void pian2(){
    if(x[n]>=y[m]) cout<<0;
    else cout<<1;
    for(int k=1;k<=Q;k++){
        ll xn=x[n],ym=y[m];
        int kx,ky;
        cin>>kx>>ky;
        int p,v;
        for(int i=1;i<=kx;i++){
            cin>>p>>v;
            if(p==n) xn=v;
        }
        for(int i=1;i<=ky;i++){
            cin>>p>>v;
            if(p==m) ym=v;
        }
        if(xn>=ym) cout<<0;
        else cout<<1;
    }
    return ;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>Q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
    }
    if(c==1){
        if(x[1]==y[1]) cout<<0;
        else cout<<1;
        for(int k=1;k<=Q;k++){
            int xn=x[1],ym=y[1];
            int kx,ky;
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++){
                int p,v;
                cin>>p>>xn;
            }
            for(int i=1;i<=ky;i++){
                int p,v;
                cin>>p>>ym;
            }
            if(xn==ym) cout<<0;
            else cout<<1;
        }
    }

    if(c>=8&&c<=14) pian2();
    return 0;
}
