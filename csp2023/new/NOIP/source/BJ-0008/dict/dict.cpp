#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int cur,pos;
char s[3005];
int cnt[3005][26];
int a[3005],b[3005];
char ans[3005];
bool vis[3005];

inline bool cmp1(int x,int y)
{
    for(int i=0;i<26;i++)
    {
        if(cnt[x][i]!=cnt[y][i])
            return cnt[x][i]>cnt[y][i];
    }

    return 0;
}

inline bool cmp2(int x,int y)
{
    for(int i=25;i>=0;i--)
    {
        if(cnt[x][i]!=cnt[y][i])
            return cnt[x][i]<cnt[y][i];
    }

    return 0;
}

inline bool cpr(int x,int y)
{
    int mn,mx;

    for(int i=0;i<26;i++)
    {
        if(cnt[x][i])
        {
            mn=i;
            break;
        }
    }

    for(int i=25;i>=0;i--)
    {
        if(cnt[y][i])
        {
            mx=i;
            break;
        }
    }

    return mx<=mn;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>(s+1);

        for(int j=1;j<=m;j++)
            cnt[i][s[j]-'a']++;

        a[i]=b[i]=i;
    }

    sort(a+1,a+n+1,cmp1);
    sort(b+1,b+n+1,cmp2);

    cur=n;
    pos=1;

    for(int i=1;i<=n;i++)
    {
        while(pos<=n&&cpr(a[i],b[pos]))
        {
            vis[b[pos]]=1;
            cur--,pos++;
        }

        if(cur==n||(cur==n-1&&vis[a[i]]))
            ans[a[i]]='1';
        else
            ans[a[i]]='0';
    }

    cout<<(ans+1)<<'\n';

    return 0;
}
