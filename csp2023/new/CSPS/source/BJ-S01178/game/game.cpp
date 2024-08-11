#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=802;

int n,ans,a[N],dp[N][N];
string s;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=1;i<=n;i++)
        a[i]=s[i-1];
    if(n<=800)
    {
        //O(n^3),35pts
        for(int i=1;i<n;i++)
            if(a[i]==a[i+1])
            {
                dp[i][i+1]=1;
                ans++;
            }
        for(int len=4;len<=n;len++)
            for(int i=1;i+len-1<=n;i++)
            {
                int j=i+len-1;
                if(dp[i+1][j-1]&&a[i]==a[j])
                {
                    ans++;
                    dp[i][j]=1;
                    continue;
                }
                for(int k=i+1;k<j;k++)
                    if(dp[i][k]&&dp[k+1][j])
                    {
                        ans++;
                        dp[i][j]=1;
                        break;
                    }
            }
        cout<<ans<<endl;
    }
    else
        cout<<0<<endl;
    return 0;
}
