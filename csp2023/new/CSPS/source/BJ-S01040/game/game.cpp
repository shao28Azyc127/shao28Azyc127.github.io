#include<bits/stdc++.h>
using namespace std;
long long n,dp[8010][8010],sum;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int len=2;len<=n;len+=2){
        for(int i=0;i<n;i++){
            int j=i+len-1;
            if(s[i]==s[j]&&(dp[i+1][j-1]==true||j==i+1)){
                sum++;
                dp[i][j]=true;
                continue;
            }
            for(int k=i;k<=i+len-1;k++){
                if(dp[i][k]&&dp[k+1][j]){
                    dp[i][j]=true;
                    sum++;
                    break;
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
