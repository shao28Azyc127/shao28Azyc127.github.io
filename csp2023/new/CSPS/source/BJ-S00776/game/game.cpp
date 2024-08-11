#include<bits/stdc++.h>
using namespace std;
bool dp[9005][9005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    long long n;
    cin>>n;
    string str;
    cin>>str;
    long long cnt=0;
    for(long long i=0;i<str.length()-1;i++){
        if(str[i]==str[i+1]){
            dp[i][i+1]=1;
            cnt++;
        }
    }
    for(long long i=4;i<=str.length();i+=2){
        for(long long l=0;l<str.length()-i+1;l++){
            long long r=l+i-1;
            if(dp[l+1][r-1]==1&&str[l]==str[r]){
                dp[l][r]=1;
                cnt++;
                continue;
            }
            for(int j=l;j<r;j++){
                if(dp[l][j]==1&&dp[j+1][r]==1){
                    dp[l][r]=1;
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
