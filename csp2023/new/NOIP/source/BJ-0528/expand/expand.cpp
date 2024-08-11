#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c,n,m,q;
int x[maxn],y[maxn];

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int j=1;j<=m;j++){
        cin>>y[j];
    }
    if(n==1 && m==1 ){
        if(x[1] == y[1]) cout<<0;
        else cout<<1;
        while(q--){
            int kx,ky,a,b;
            cin>>kx>>ky;
            while(kx){kx--;
                cin>>a>>b;
                x[a] = b;
            }
            while(ky){ky--;
                cin>>a>>b;
                y[a] = b;
            }
            if(x[1] == y[1]) cout<<0;
            else cout<<1;
        }
    }
    return 0;
}
