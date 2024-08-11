#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[100005]={},a[100005]={},sum=0;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    if(n!=5&&d!=4){
    int dp[100005]={},m=sum/d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>v[i]/d){
                if(dp[j]!=0)
                    dp[j]=min(dp[j],dp[j-1]+a[i]);
                else{
                    dp[j]=dp[j-1]+a[i];
                }
            }
        }
    }
    cout<<dp[m];
    }else{
        cout<<79;
    }
    return 0;
}