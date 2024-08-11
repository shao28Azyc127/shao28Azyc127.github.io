#include<bits/stdc++.h>
using namespace std;
#define int long long
int d;
int n,m;
int x[1000009];
int y[1000009];
int xx1[1000009];
int yy1[1000009];
bool f[3009][3009];
bool ck(){
    f[0][0]=1;
    if(xx1[1]==yy1[1]){
        return 0;
    }
    if(xx1[1]>yy1[1]){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=(f[i-1][j]|f[i-1][j-1]|f[i][j-1])&xx1[i]>yy1[j];
            }
        }
        return f[n][m];
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=(f[i-1][j]|f[i-1][j-1]|f[i][j-1])&xx1[i]<yy1[j];
            }
        }
        return f[n][m];
    }
    return 1;
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int q;
    cin>>d>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        xx1[i]=x[i];
    }
    for(int i=1;i<=m;i++){
        cin>>y[i];
        yy1[i]=y[i];
    }
    cout<<ck();
    for(int i=1;i<=q;i++){
        int x1,x2;
        cin>>x1>>x2;
        for(int i=1;i<=n;i++){
        //cin>>x[i];
        xx1[i]=x[i];
    }
    for(int i=1;i<=m;i++){
        //cin>>y[i];
        yy1[i]=y[i];
    }
        for(int i=1;i<=x1;i++){
            int a,b;
            cin>>a>>b;
            xx1[a]=b;
        }
        for(int i=1;i<=x2;i++){
            int a,b;
            cin>>a>>b;
            yy1[a]=b;
        }
        cout<<ck();
    }
    return 0;
}
