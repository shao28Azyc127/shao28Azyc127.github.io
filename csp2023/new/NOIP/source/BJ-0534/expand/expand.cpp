#include <bits/stdc++.h>
using namespace std;
int dp[3000][3000];
int ay[3000],by[3000];
int an[3000],bn[3000];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    for (int i=1;i<=n;i++){
        cin>>ay[i];
        an[i]=ay[i];
    }
    for (int i=1;i<=m;i++){
        cin>>by[i];
        bn[i]=by[i];
    }
    for (int tt=0;tt<=q;tt++){

        if ((an[1]-bn[1])*(an[n]-bn[m])<=0) {
            cout<<0;
        }
        else if (an[1]<bn[1]){
            dp[0][0]=1;
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    dp[i][j]=0;
                    for (int k=j;k>=1;k--){
                        if (an[i]<bn[k]&&(dp[i-1][k-1]==1||dp[i-1][k]==1)){
                            dp[i][j]=1;
                            break;
                        }
                        if (an[i]>=bn[k]) {
                            break;
                        }
                    }
                }
            }
            if (dp[n][m]==1) cout<<1;
            else cout<<0;
        }
        else{
            dp[0][0]=1;
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    dp[i][j]=0;
                    for (int k=j;k>=1;k--){
                        if (an[i]>bn[k]&&(dp[i-1][k-1]==1||dp[i-1][k]==1)){
                            dp[i][j]=1;
                            break;
                        }
                        if (an[i]<=bn[k]) {
                            break;
                        }
                    }
                    //cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
                }
            }
            if (dp[n][m]==1) cout<<1;
            else cout<<0;
        }
        for (int i=1;i<=n;i++){
            an[i]=ay[i];
        }
        for (int i=1;i<=m;i++){
            bn[i]=by[i];
        }
        int kx,ky;
        cin>>kx>>ky;
        for (int i=1;i<=kx;i++){
            int p,v;
            cin>>p>>v;
            an[p]=v;
        }
        for (int i=1;i<=ky;i++){
            int p,v;
            cin>>p>>v;
            bn[p]=v;
        }
    }
    return 0;
}
