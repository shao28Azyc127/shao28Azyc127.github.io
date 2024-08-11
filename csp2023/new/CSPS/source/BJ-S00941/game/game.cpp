#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second
#define mp make_pair
#define MAXN 8010
typedef long long ll;
int f[MAXN][MAXN];
ll n,ans;
string s;
signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>s;
    s=' '+s;
    for(int i=1;i<=n;i++) f[i][i-1]=1;
    for(int i=n;i>=1;i--)
    {
        int tp=0;
        for(int j=i;j<=n;j++)
        {
            if(s[i]==s[j] && f[i+1][j-1])
                f[i][j]=1,tp=j,ans++;
            else if(tp && f[tp+1][j])
                f[i][j]=1,ans++;
        }
    }
    cout<<ans;
    return 0;
}
