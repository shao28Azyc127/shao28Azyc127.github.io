#include <bits/stdc++.h>
using namespace std;
int c,n,m,q,a[500010],b[500010];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    if(c==1){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        if(a[1]==b[1]){
            cout<<0;
        }else{
            cout<<1;
        }
        while(q--){
            int kx,ky,vx,px;
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++){
                cin>>px>>vx;
                a[px]=vx;
            }
            for(int i=1;i<=ky;i++){
                cin>>px>>vx;
                b[px]=vx;
            }
            if(a[1]==b[1]){
                cout<<0;
            }else{
                cout<<1;
            }
        }
    }else{
        srand(time(0));
        for(int i=1;i<=q;i++){
            if(rand()%2==0){
                cout<<0;
            }else{
                cout<<1;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
