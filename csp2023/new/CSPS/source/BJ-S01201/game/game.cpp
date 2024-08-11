#include<bits/stdc++.h>
using namespace std;

int dp[8193][8193];
string a;

int work(int l,int r)
{
    for(int i=0;i<r-l;i++)dp[i+1][i]=1;
    for(int i=1;i<r-l;i+=2)
        for(int j=0;i+j<r-l;j++)
        {
            dp[j][i+j]=((a[j+l]==a[i+j+l])&&dp[j+1][i+j-1]);
            for(int k=j+1;k<i+j-1;k+=2)
                dp[j][i+j]=dp[j][i+j]||(dp[j][k]&&dp[k+1][i+j]);
        }
    int ans=0;
    for(int i=0;i<r-l;i++)
        for(int j=i+1;j<r-l;j++)
            ans+=dp[i][j];
    return ans;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>a;
    if(n<1000)cout<<work(0,n);
    else 
    {
        long long ans=0;
        for(int i=10;i<=n;i++){ans+=work(i-10,i);}
        cout<<ans;
    }
}