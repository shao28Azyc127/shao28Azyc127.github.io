#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#include <cstdlib>
#include <bitset>
using namespace std;
#define int long long
#define mod 998244353
#define mp make_pair
#define fi first
#define se second
#define pb push_back

int n,a[2000005],dp[2000005],bef[2000005],ans;
char s[2000005];

signed main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n>>s; for(int i=1;i<=n;i++) a[i]=s[i-1]-'a'+1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1]) bef[i]=i-1,dp[i]=dp[bef[i]-1]+1;
        else
        {
            int nj=bef[i-1];
            while(nj&&a[nj-1]!=a[i]) nj=bef[nj-1];
            if(nj&&a[nj-1]==a[i]) bef[i]=nj-1,dp[i]=dp[bef[i]-1]+1;
        }
        ans+=dp[i];
    }
    cout<<ans<<endl;
}
