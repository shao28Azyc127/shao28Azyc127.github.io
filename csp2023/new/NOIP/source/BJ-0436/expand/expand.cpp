#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[500005];
int y[500005];
int c,n,m,q;
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
    }

    for(int i=1;i<=q;i++){
        int kx,ky;
        cin>>kx>>ky;
        for(int j=1;j<=kx;j++){
            int p,v;
            cin>>p>>v;
            if(n==1&&m==1){
                cout<<"1";
            }else if(n<=2&&m<=2){
                if(p==1){
                    if((v-y[1])*(x[2]-y[2])>0){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else{
                    if((x[1]-y[1])*(v-y[2])>0){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }
            }
        }
        for(int j=1;j<=ky;j++){
            int p,v;
            cin>>p>>v;
            if(n==1&&m==1){
                cout<<"1";
            }else if(n<=2&&m<=2){
                if(p==1){
                    if((x[1]-v)*(x[2]-y[2])>0){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else{
                    if((x[1]-y[1])*(x[2]-v)>0){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }
            }
        }
    }
    return 0;
}
