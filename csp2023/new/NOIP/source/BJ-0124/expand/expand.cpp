#include<bits/stdc++.h>
#define MaxN 500000
using namespace std;
int c,n,m,q,x[MaxN],y[MaxN];
void check(){
    if((x[1]>y[1]&&x[n]>y[m])||(x[1]<y[1]&&x[n]<y[m])){
        cout << 1;
    }else{
        cout << 0;
    }
    return;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >>q;
    for(int i = 1;i<=n;i++){
        cin >> x[i];
    }
    for(int i = 1;i<=m;i++){
        cin >> y [i];
    }
    check();
    for(int i = 1;i<=q;i++){
        int kx,ky;
        cin >> kx >> ky;
        for(int j =1;j<=kx;j++){
            int p,v;
            cin >> p >>v;
            x[p] = v;
        }
        for(int j = 1;j<=ky;j++){
            int p,v;
            cin >> p >>v;
            y[p] = v;
        }
        check();
    }
    return 0;
}
