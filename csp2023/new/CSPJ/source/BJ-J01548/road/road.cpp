#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d;
int len[N];
int money[N];
pair<long long, long long> dp[N];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>d;
    len[1]=0;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        len[i]=a+len[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>money[i];
    }
    for(int i=0;i<=N;i++){
        dp[i].first=0x3f3f3f3f3f3f3f3f;
        dp[i].second=0;
    }
    dp[1].first=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            long long len2=len[i]-len[j]-dp[j].second;
            long long need;
            if(len2%d==0){
                need=len2/d;
            }
            else{
                need=len2/d+1;
            }
            if(dp[i].first>dp[j].first+need*money[j]){
                dp[i]={dp[j].first+need*money[j], need*d+dp[j].second-len[i]+len[j]};
            }
            else if(dp[i].first==dp[j].first+need*money[j]){
                dp[i]={dp[j].first+need*money[j], max(need*d+dp[j].second-len2, dp[i].second)};
            }
        }
    }
    cout<<dp[n].first;
    return 0;
}
