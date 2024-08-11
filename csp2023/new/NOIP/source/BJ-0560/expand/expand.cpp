#include<bits/stdc++.h>
using namespace std;
int c,n,m,q;
const int Nm=500007;
int xx[Nm];
int yy[Nm];
int x[Nm];
int y[Nm];
bool ju(int z){
    if(x[1]>y[1]&&x[n]<y[m]) return 1;
    else if(x[1]<y[1]&&x[n]<y[m]) return 1;
    else return 0;
}
int main(){
    //freopen("expand2.in","r",stdin);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>xx[i];
        x[i]=xx[i];
    }
    for(int i=1;i<=m;i++){
        cin>>yy[i];
        y[i]=yy[i];
    }
    cout<<ju(0);
    for(int i=1;i<=q;i++){
        for(int i=1;i<=n;i++) x[i]=xx[i];
        for(int i=1;i<=m;i++) y[i]=yy[i];
        int kx,ky;
        cin>>kx>>ky;
        for(int j=1;j<=kx;j++){
            int p,v;
            cin>>p>>v;
            x[p]=v;
        }
        for(int j=1;j<=ky;j++){
            int p,v;
            cin>>p>>v;
            y[p]=v;
        }
        /*cout<<endl;
        for(int j=1;j<=n;j++) cout<<x[j]<<" ";
        cout<<endl;
        for(int j=1;j<=m;j++) cout<<y[j]<<" ";
        cout<<endl<<endl;
        */
        cout<<ju(i);
    }
    return 0;
}
