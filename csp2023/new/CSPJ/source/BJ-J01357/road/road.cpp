#include <bits/stdc++.h>
using namespace std;
int j[1000],m[1000],dp[1000][1000],s=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,mi=INT_MAX;
    cin>>n>>d;
    for(int i=1;i<=(n-1);i++){
        cin>>j[i];
        s=s+j[i];
    }
    if(s%d==0){
        s=s/d;
    }else{
          s=s/d+1;
    }

    for(int i=1;i<=n;i++){
        cin>>m[i];
        mi=min(m[i],mi);
    }
    if(m[1]==mi){
        cout<<s*mi;
        return 0;
    }

    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=d;j++){
            dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+m[i]*j);
        }
    }
    return 0;
}

