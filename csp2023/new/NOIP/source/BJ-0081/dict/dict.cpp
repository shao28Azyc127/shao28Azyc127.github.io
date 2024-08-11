#include <bits/stdc++.h>
#define MAXN 3010
using namespace std;
string s[MAXN],pre[MAXN],suf[MAXN],sm[MAXN],sb[MAXN];
int n,m,buk[30];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>s[i],s[i]=' '+s[i];
    for(int i=1;i<=n;i++)
    {
        memset(buk,0,sizeof(buk));
        for(int j=1;j<=m;j++) buk[s[i][j]-'a']++;
        for(int j=0;j<26;j++)
            for(int k=1;k<=buk[j];k++)
                sm[i]+=char(j+'a');
        for(int j=25;j>=0;j--)
            for(int k=1;k<=buk[j];k++)
                sb[i]+=char(j+'a');
    }
    pre[1]=sb[1];
    for(int i=2;i<=n;i++) pre[i]=min(pre[i-1],sb[i]);
    suf[n]=sb[n];
    for(int i=n-1;i>=1;i--) suf[i]=min(suf[i+1],sb[i]);
    if(suf[2]>sm[1]) cout<<1;
    else cout<<0;
    for(int i=2;i<n;i++)
    {
        if(min(suf[i+1],pre[i-1])>sm[i]) cout<<1;
        else cout<<0;
    }
    if(pre[n-1]>sm[n]) cout<<1;
    else cout<<0;
}
