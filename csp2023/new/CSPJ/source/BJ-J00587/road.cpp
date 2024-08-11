#include <bits/stdc++.h>
using namespace std;

int n,d,o[100005];
int v[100005];
int a[100005];
int dp[100005]={0x3f};

int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dp[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            float sum=(v[i]-v[j])/d;
            sum=sum*a[j];
            int suma=int(sum);
            if(sum>suma){
                suma=(v[i]-v[j])/d+1;
                suma=suma*a[j];
            }
            if(dp[i]==0){
                dp[i]=suma;
                continue;
            }
            dp[i]=min(dp[i],suma);
        }
    }
    cout<<dp[n];
    return 0;
}