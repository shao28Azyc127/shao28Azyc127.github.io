#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[100000],b[100000];
long long dp[100000];
long long xsqz(long long x,int c){
    if(x%c==0) return x/c;
    else return x/c+1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int zx=1e6;
    long long lc=0,ljlc=0;
    for(int i=1;i<=n-1;i++){
        ljlc+=a[i];
        zx=min(zx,b[i]);
        dp[i]=dp[i-1];
        if(ljlc<=lc) continue;
        long long yts=xsqz(ljlc-lc,d);
        lc+=yts*d;
        dp[i]+=yts*zx;
    }
    cout<<dp[n-1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
