#include<bits/stdc++.h>
using namespace std;
const int N=2010,M=5e5+10;
int c,n,m,q,a[M],b[M],u[M],v[M],dp[N][N];
int calc1(){
    if(u[1]<=v[1]||u[n]<=v[m])return 0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(u[i]>v[j])
                if(i==1&&j==1){
                    dp[1][1]=1;
                }
                else{
                    if(dp[i-1][j]|dp[i-1][j-1]|dp[i][j-1])dp[i][j]=1;
                }
    return dp[n][m];
}
int calc2(){
    if(u[1]>=v[1]||u[n]>=v[m])return 0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(u[i]<v[j])
                if(i==1&&j==1){
                    dp[1][1]=1;
                }
                else{
                    if(dp[i-1][j]|dp[i-1][j-1]|dp[i][j-1])dp[i][j]=1;
                }
    return dp[n][m];
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),u[i]=a[i];
    for(int i=1;i<=m;i++)scanf("%d",&b[i]),v[i]=b[i];
    if(u[1]>v[1])cout<<calc1();
    else if(u[1]<v[1])cout<<calc2();
    else cout<<0;
    while(q--){
        int kx,ky,x,y;
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=n;i++)u[i]=a[i];
        for(int i=1;i<=m;i++)v[i]=b[i];
        for(int i=1;i<=kx;i++){
            scanf("%d%d",&x,&y);
            u[x]=y;
        }
        for(int j=1;j<=ky;j++){
            scanf("%d%d",&x,&y);
            v[x]=y;
        }
        if(u[1]>v[1])printf("%d",calc1());
        else if(u[1]<v[1])printf("%d",calc2());
        else printf("0");
    }
    return 0;
}
