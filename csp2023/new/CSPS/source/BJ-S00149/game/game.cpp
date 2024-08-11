#include<bits/stdc++.h>
using namespace std;
const int N=8005;
string s;
int n,ans;
bool dp[N][N];
bool f(int x,int y)
{
    if(dp[x][y]) return 1;
    if(x+1==y&&s[x]==s[y])
    {
        dp[x][y]=1;
        return 1;
    }
    if(s[x]==s[y]&&f(x+1,y-1))
    {
        dp[x][y]=1;
        return 1;
    }
    if(y-x>2)
    {
        for(int k=x+1;k<y-1;k+=2)
        {
            if(f(x,k)&&f(k+1,y))
            {
                dp[x][y]=1;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j+=2)
        {
            if(f(i,j))
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
