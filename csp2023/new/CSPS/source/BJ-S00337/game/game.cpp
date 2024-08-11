#include<bits/stdc++.h>
using namespace std;
const int N=8e3+5;
string s;int n,cnt;bool dp[N][N];
int main()
{
    freopen("game.in","r",stdin);freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<s.size()-1;i++) if(s[i]==s[i+1]) dp[i][i+1]=true;
    for(int len=3;len<=s.size();len++)
    {
        for(int j=0;j+len-1<s.size();j++)
        {
            dp[j][j+len-1]=(s[j]==s[j+len-1]&&dp[j+1][j+len-2]);
            for(int k=j;k<=j+len-1;k++) dp[j][j+len-1]|=dp[j][k]&&dp[k+1][j+len-1];
        }
    }
    for(int len=2;len<=s.size();len++) for(int j=0;j+len-1<s.size();j++) if(dp[j][j+len-1]) cnt++;cout<<cnt;
    return 0;
}
