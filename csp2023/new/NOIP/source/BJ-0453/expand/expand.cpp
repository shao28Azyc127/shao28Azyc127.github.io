#include <bits/stdc++.h>
using namespace std;
int x[3],y[3],x1[3];
int yl[3];
long long ans,sums;
int c,q,m,n;
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >>c >>n >>m >>q;
    for(int i=1;i<=n;i++) cin >>x[i],x1[i]=x[i];
    for(int i=1;i<=m;i++) cin >>y[i],yl[i]=y[i];
    if(c==1){
        if(x[1]==y[1]) cout <<"0";
        else cout <<"1";
        while(q--){
            for(int i=1;i<=n;i++){
                x1[i]=x[i];
            }
            for(int i=1;i<=m;i++){
                yl[i]=y[i];
            }

            int kx,ky;
            cin >>kx >>ky;
            for(int i=1;i<=kx;i++){
                int id,v;
                cin >>id >>v;
                x1[id]=v;
            }
            for(int i=1;i<=ky;i++){
                int id,v;
                cin >>id >>v;
                yl[id]=v;
            }
            if(x1[1]==yl[1]) cout <<"0";
            else cout <<"1";
        }
    }else if(c==2){
        if(x[1]==y[1] || x[2]==y[2]){
            cout <<"0";
        }else cout <<"1";
        while(q--){
            for(int i=1;i<=n;i++){
                x1[i]=x[i];
            }
            for(int i=1;i<=m;i++){
                yl[i]=y[i];
            }

            int kx,ky;
            cin >>kx >>ky;
            for(int i=1;i<=kx;i++){
                int id,v;
                cin >>id >>v;
                x1[id]=v;
            }
            for(int i=1;i<=ky;i++){
                int id,v;
                cin >>id >>v;
                yl[id]=v;
            }
            if(x1[1]==yl[1] || x1[2]==yl[2]) cout <<"0";
            else cout <<"1";
        }
    }else{
        int lxx=0;
        for(int i=1;i<=min(n,m);i++){
            if(x[i]==y[i]) lxx++;
        }
        if(x[1]==y[1] || x[n]==y[m] || lxx+2==min(n,m)){
            cout <<"0";
        }else cout <<"1";
        while(q--){
            for(int i=1;i<=n;i++){
                x1[i]=x[i];
            }
            for(int i=1;i<=m;i++){
                yl[i]=y[i];
            }

            int kx,ky;
            cin >>kx >>ky;
            for(int i=1;i<=kx;i++){
                int id,v;
                cin >>id >>v;
                x1[id]=v;
            }
            for(int i=1;i<=ky;i++){
                int id,v;
                cin >>id >>v;
                yl[id]=v;
            }
            int lxx=0;
            for(int i=1;i<=min(n,m);i++){
                if(x[i]==y[i]) lxx++;
            }
            if(x1[1]==yl[1] || x1[n]==yl[m] || lxx+2==min(n,m)) cout <<"0";
            else cout <<"1";
        }
    }
    return 0;
}
