#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int sum[2000005];
int pre[2000005][26];
char s[2000005];
ll ans;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;

    cin>>(s+1);

    for(int i=1;i<=n;i++)
    {
        int v=s[i]-'a';

        if(pre[i-1][v])
        {
            sum[i]=sum[pre[i-1][v]-1]+1;
            for(int j=0;j<26;j++)
                pre[i][j]=pre[pre[i-1][v]-1][j];
        }

        pre[i][v]=i;

        ans+=sum[i];
    }

    cout<<ans<<'\n';

    return 0;
}
