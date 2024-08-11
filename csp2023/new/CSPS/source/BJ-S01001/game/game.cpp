#include<bits/stdc++.h>
using namespace std;
bool dp[8005][8005]; //dp[i][j]:区间(i,j)可消除
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++) //O(n)
        if(s[i]==s[i+1])
            dp[i][i+1]=1;
    for(int i=0;i<n-1;i++) //O(n^2)
    {
        for(int j=i+1;j<n;j++)
            if(dp[i][j])
            {
                for(int k=1;(i-k)>=0&&(j+k)<n;k++)
                    if(s[i-k]==s[j+k])
                        {
                            dp[i-k][j+k]=1;
                            break;
                        }
            }
    }
    for(int i=0;i<n;i++) //O(n^3)
        for(int j=i+2;j<n;j++)
            for(int k=i+1;k<j;k++)
                    if(dp[i][k]&&dp[k+1][j])
                        {
                            dp[i][j]=1;
                            break;
                        }
    for(int i=0;i<n-1;i++) //O(n^2)
    {
        for(int j=i+1;j<n;j++)
            if(dp[i][j])
            {
                for(int k=1;(i-k)>=0&&(j+k)<n;k++)
                    if(s[i-k]==s[j+k])
                        {
                            dp[i-k][j+k]=1;
                            break;
                        }
            }
    }
    for(int i=0;i<n;i++) //O(n^3)
        for(int j=i+2;j<n;j++)
            for(int k=i+1;k<j;k++)
                    if(dp[i][k]&&dp[k+1][j])
                        {
                            dp[i][j]=1;
                            break;
                        }
    for(int i=0;i<n-1;i++) //O(n^2)
    {
        for(int j=i+1;j<n;j++)
            if(dp[i][j])
            {
                for(int k=1;(i-k)>=0&&(j+k)<n;k++)
                    if(s[i-k]==s[j+k])
                        {
                            dp[i-k][j+k]=1;
                            break;
                        }
            }
    }
    for(int i=0;i<n;i++) //O(n^3)
        for(int j=i+2;j<n;j++)
            for(int k=i+1;k<j;k++)
                    if(dp[i][k]&&dp[k+1][j])
                        {
                            dp[i][j]=1;
                            break;
                        }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(dp[i][j])
                ans++;
    cout<<ans;
    return 0;
}
