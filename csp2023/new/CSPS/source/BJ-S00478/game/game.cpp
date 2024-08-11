#include <bits/stdc++.h>
using namespace std;
int dp[20000][20000];

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string ss;
    cin>>ss;
    long long cntt=0;
    for(int i = 0;i+1<n;i++)
        if(ss[i]==ss[i+1])
        {
            dp[i][i+1]=1;
            cntt++;
        }
    for(int w=2;w<=n-1;w++)
    {
        if(w%2==0) continue;
        for(int i = 0;i+w<n;i++)
        {
            int j=i+w;
            if(ss[i]==ss[j]&&dp[i+1][j-1]==1)
            {
                dp[i][j]=1;
                cntt++;
                continue;
            }
            for(int k = i;k<j;k++)
                if(dp[i][k]==1&&dp[k+1][j]==1)
                {
                    dp[i][j]=1;
                    cntt++;
                    break;
                }
        }
    }
    cout<<cntt;
    return 0;
}
