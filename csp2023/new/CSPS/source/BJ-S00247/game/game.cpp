#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int n;
string s;
bool can[1000][1000];
void solve1()
{
    ll ans=0;
    for(int l=1;l<n;l++)
    {
        for(int r=l+1;r<=n;r++)
        {
            if(l+1==r)can[l][r]=s[l]==s[r];
            for(int i=l+1;i<r;i++)
            {
                can[l][r]|=can[l][i]&can[i+1][r];
            }
            ans+=can[l][r];
        }
    }
    cout<<ans;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>s;
    s="$"+s;
    if(n<=800)solve1();
    return 0;
}
