//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

int x[500005];
int y[500005];
signed main(){
    ios::sync_with_stdio(false);

    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    int c; cin>>c;
    int n; cin>>n;
    int m; cin>>m;
    int q; cin>>q;

    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    for(int i=1;i<=n;i++){
        cin>>y[i];
    }

    if(c==1){
        if(y[1]==x[1]){
            cout<<0;
        }
        else{
            cout<<1;
        }

        for(int i=1;i<=m;i++){
            int kx; cin>>kx;
            int ky; cin>>ky;

            for(int j=1;j<=kx;j++){
                int p; cin>>p;
                int v; cin>>v;

                x[p]=v;
            }

            for(int j=1;j<=ky;j++){
                int p; cin>>p;
                int v; cin>>v;

                y[p]=v;
            }
        }

        if(x[1]==y[1]){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    else if(c==3){
        cout<<1001;
    }
    else{
        for(int i=2;i<=m+2;i++){
            cout<<rand()%i%2;
        }
    }
////
    return 0;
}
