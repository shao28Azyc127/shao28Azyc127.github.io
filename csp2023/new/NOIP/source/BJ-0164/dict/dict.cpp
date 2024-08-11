#include <bits/stdc++.h>
#define int long long
#define MAXN 3010
using namespace std;
int n,m,cnt[26],tot;
string a[MAXN],b[MAXN];
signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=0;j<m;j++)
            cnt[a[i][j]-'a']++;
        tot=0;
        for(int j=0;j<26;j++)
        {
            while(cnt[j])
            {
                a[i][tot++]=j+'a';
                cnt[j]--;
            }
        }
        b[i]=a[i];
        reverse(b[i].begin(),b[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=0;
        for(int j=1;j<=n;j++)
            if(i!=j&&b[j]<=a[i])
            {
                flag=1;
                break;
            }
        if(flag) cout<<0;
        else cout<<1;
    }
    return 0;
}
