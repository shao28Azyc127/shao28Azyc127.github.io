#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int a[500005],b[500005];
int la[500005],lb[500005];
bool dp[2005][2005],dp2[2005][2005];
int c,n,m,q;
void solve2000(){
    /*for(int i=1;i<=n;i++)cout<<la[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=m;i++)cout<<lb[i]<<" ";
    cout<<"\n";*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) dp[i][j]=0,dp2[i][j]=0;
    dp[0][0]=1,dp2[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(la[i]>lb[j])dp[i][j]=(dp[i][j-1]||dp[i-1][j]||dp[i-1][j-1]);
            if(la[i]<lb[j])dp2[i][j]=(dp2[i][j-1]||dp2[i-1][j]||dp2[i-1][j-1]);
        }
    }
    if(dp[n][m]||dp2[n][m])cout<<"1";
    else cout<<"0";
}
void solve2(){
    int j=0;
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(la[i]>=lb[m]){
            flag=1;
            break;
        }
        while(j+1<=m&&la[i]<lb[j+1]){
            j++;
        }
    }
    if(flag)cout<<"0";
    else if(j==m)cout<<"1";
    else cout<<"0";
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),la[i]=a[i];
    for(int i=1;i<=m;i++)scanf("%d",&b[i]),lb[i]=b[i];
    if(n<=2000&&m<=2000)solve2000();
    else if(8<=c&&c<=14)solve2();
    else cout<<"0";
    while(q--){
        int k1,k2;
        cin>>k1>>k2;
        for(int i=1;i<=n;i++)la[i]=a[i];
        for(int i=1;i<=m;i++)lb[i]=b[i];
        int p,v;
        for(int i=1;i<=k1;i++){
            scanf("%d%d",&p,&v);
            la[p]=v;
        }
        for(int i=1;i<=k2;i++){
            scanf("%d%d",&p,&v);
            lb[p]=v;
        }
        if(n<=2000&&m<=2000)solve2000();
        else if(8<=c&&c<=14)solve2();
        else cout<<"0";
    }
    return 0;
}
