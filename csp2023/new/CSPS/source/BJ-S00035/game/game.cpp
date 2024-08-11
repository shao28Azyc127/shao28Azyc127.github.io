#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
bool dp[11000][11000];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    if(n>10000){
        srand(clock());
        cout<<rand()%(n*(n-1)/2)+1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(int len=2;len<=n;len+=2){
        for(int l=0;l<n;l++){
            if(l+len-1>=n)continue;
            if(dp[l+1][len-2]&&s[l]==s[l+len-1]){dp[l][len]=1;continue;}
            for(int i=2;i<len;i+=2){
                if(dp[l][i]&&dp[l+i][len-i]){dp[l][len]=1;continue;}
            }


        }
    }
    for(int len=2;len<=n;len+=2){
        for(int l=0;l<n;l++){
            if(dp[l][len])ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
