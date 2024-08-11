# include <bits/stdc++.h>
using namespace std;
string s;
int n;
long long ans = 0;
int dp[20005][20005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    bool bj = 1;
    int i;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1] = 1;
            ans++;
        }
    }
    for(int i=4;i<=n;i*=2){
        for(int j=0;j+i<=n;j++){
            int z = j+i-1;
            if(dp[j][j+i/2-1]==1&&dp[z+1-i/2][z]==1){
                dp[j][z] = 1;
                ans++;
            }else if(s[j]==s[z]){
                int minn=999999,maxn=-1;
                for(int ii=j+1;ii+i/2<z;ii++){
                    if(dp[ii][ii+i/2-1]==1){
                        minn = min(minn,ii);
                        maxn = max(maxn,ii-1+i/2);
                    }
                }
                if(minn==j+1&&maxn==z-1) dp[j][z] = 1;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
