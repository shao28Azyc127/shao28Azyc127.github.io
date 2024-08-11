#include<bits/stdc++.h>
using namespace std;
int x[500005],y[500005],px[500005],py[500005],ans[105];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        px[i]=x[i];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
        py[i]=y[i];
    }
    if((x[1]<y[1]&&x[n]<y[m])||(x[1]>y[1]&&x[n]>y[m])){
        ans[0]=1;
    }else{
        ans[0]=0;
    }
    int posa=1;
    while(q--){
        int kx,ky;
        cin>>kx>>ky;
        for(int i=1;i<=kx;i++){
            int pxx,v;
            cin>>pxx>>v;
            x[pxx]=v;
        }
        for(int i=1;i<=ky;i++){
            int pxx,v;
            cin>>pxx>>v;
            y[pxx]=v;
        }
        if((x[1]<y[1]&&x[n]<y[m])||(x[1]>y[1]&&x[n]>y[m])){
            ans[posa]=1;
        }else{
            ans[posa]=0;
        }
        posa++;
        for(int i=1;i<=n;i++){
            x[i]=px[i];
        }
        for(int i=1;i<=m;i++){
            y[i]=py[i];
        }
    }
    for(int i=0;i<posa;i++){
        cout<<ans[i];
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
