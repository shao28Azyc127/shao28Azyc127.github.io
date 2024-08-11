#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,q,kx,ky,x[500010],y[500010],cx[500010],cy[500010],pp[500010];
bool dp[2010][2010];
bool check(){
    int q=x[1]-y[1];
    //cout<<q<<'\n';
    memset(dp,0,sizeof(dp));dp[0][0]=1;
    
    /*for(int i=1;i<=n;i++){
        cout<<x[i]<<' ';
    }cout<<'\n';
    for(int j=1;j<=m;j++){
        cout<<y[j]<<' ';
    }cout<<"\n\n";
    */
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((x[i]-y[j])*q>0){
                dp[i][j]=(dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1]);
            }//cout<<dp[i][j]<<' ';
        }//cout<<'\n';
    }return dp[n][m];
}signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        cx[i]=x[i];
    }for(int j=1;j<=m;j++){
        cin>>y[j];
        cy[j]=y[j];
    }for(int nowq=0;nowq<=q;nowq++){
        for(int i=1;i<=n;i++){
            x[i]=cx[i];
        }for(int j=1;j<=m;j++){
            y[j]=cy[j];
        }if(nowq!=0){
            cin>>kx>>ky;
            for(int i=1;i<=kx;i++){
                int p,v;
                cin>>p>>v;
                x[p]=v;
            }for(int i=1;i<=ky;i++){
                int p,v;
                cin>>p>>v;
                y[p]=v;
            }
        }int nowans=check();
        cout<<nowans;
    }return 0;
}