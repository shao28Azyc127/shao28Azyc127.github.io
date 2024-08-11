#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=8005;
char c[MAXN];
bool dp[MAXN][MAXN];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    //freopen("/home/noip02/CSP-S/game_4.in","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(c[i]==c[j]&&(i-j==1||dp[j+1][i-1])&&!dp[j][i])
            {
                //cout<<j<<' '<<i<<endl;
                dp[j][i]=true;
                cnt++;
                for(int k=j-1;k>=1;k--)
                    if(dp[k][j-1]&&!dp[k][i])
                    {
                        //cout<<k<<' '<<i<<endl;
                        dp[k][i]=true;
                        cnt++;
                    }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}