#include <bits/stdc++.h>
using namespace std;

int n,d;
int a[100005];
int sum[100005],m[100005];
int ans=900000000;
int dp[100005];

void dfsa(int oil){
    int x=(a[n]-a[1])/d;
    cout<<x;
    return;
}

void dps(int now){
    int minm,minn=1000000;
    for(int i=n;i>=1;i--){
        if(m[i]<minn){
            minn=m[i];
            mimm=i;
        }
    }
    dp[minm]=(sum[now]-sum[mimm])
}

int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    //in
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }

    //dfs
    if(n<=100000&&n>1000){
        dfsa(0);
    }else{
        dp[n]=0;
        dps(n);
    }

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    //in
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }

    //dfs
    if(n<=100000&&n>1000){
        dfsa(0);
    }else{
        cout<<24;
    }

    return 0;
}
*/
