#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,t,nx[2000005],hd[30];
long long dp[2000005],as;
bool v[20000005];
vector<int> e[2000005];
string s;
int hs(int x,int y)
{
    return (1ll*x*1007%19933997+1ll*y*993%17777773)%19999997;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int i,j;
    cin>>n>>s;
    s='#'+s;
    for(i=1;i<=n;i++)
    {
        nx[i]=hd[s[i]-96];
        hd[s[i]-96]=i;
    }
    for(i=2;i<=n;i++)
    {
        if(nx[i]==i-1)
        {
            dp[i]++;
            v[hs(i,i-1)]=1;
            e[i].push_back(i-1);
        }
        if(nx[i]!=0&&v[hs(i-1,nx[i]+1)]==1)
        {
            dp[i]++;
            v[hs(i,nx[i])]=1;
            e[i].push_back(nx[i]);
        }
        if(nx[i]!=0&&v[hs(i,nx[i])]==1)
        {
            dp[i]+=dp[max(0,nx[i]-1)];
            for(j=0;j<e[nx[i]-1].size();j++)
            {
                v[hs(i,e[nx[i]-1][j])]=1;
                e[i].push_back(e[nx[i]-1][j]);
            }
        }
        as+=dp[i];
    }
    cout<<as;
    return 0;
}
