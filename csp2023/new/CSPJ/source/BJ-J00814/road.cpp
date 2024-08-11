#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s[N],v[N],dp[N][N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;++i)
    {
        int x;
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s[i]/d;++j)
        {
            dp[i][j+s[i]/d]=max(dp[i][j],dp[i][j]+s[i]/d-v[i]);
        }
    }
    cout<<dp[n][n]<<endl;
}
