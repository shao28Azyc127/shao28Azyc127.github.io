/*
    author: honglan0301

    2023-11-18 08:49:31
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define int long long
#define mod 998244353

int n,m,cnt[3005][29],xx[3005][29],dd[3005][29],mn[29],mnb,cmn[29],cmnb,ans;
int ns[3005],nt[3005];
char s[3005];

bool ck()
{
    //for(int i=1;i<=m;i++) cout<<i<<" "<<ns[i]<<" "<<nt[i]<<endl;
    for(int i=1;i<=m;i++)
    {
        if(ns[i]<nt[i]) return 1;
        if(ns[i]>nt[i]) return 0;
    }
    return 0;
}

signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1) {cout<<"1"<<endl; return 0;}
    for(int i=1;i<=n;i++)
    {
        cin>>s; for(int j=1;j<=m;j++) cnt[i][s[j-1]-'a'+1]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=26;j++) xx[i][j]=xx[i][j-1]+cnt[i][j];
        for(int j=26;j>=1;j--) dd[i][j]=dd[i][j+1]+cnt[i][j];
    }
    mn[26]=m; cmn[26]=m;
    for(int i=1;i<=n;i++)
    {
        bool flag=0;
        for(int j=26;j>=1;j--)
        {
            if(dd[i][j]<mn[j]) {flag=1; break;}
            if(dd[i][j]>mn[j]) {flag=0; break;}
        }
        if(flag) {cmnb=mnb; mnb=i; for(int j=26;j>=1;j--) cmn[j]=mn[j],mn[j]=dd[i][j]; continue;}
        flag=0;
        for(int j=26;j>=1;j--)
        {
            if(dd[i][j]<cmn[j]) {flag=1; break;}
            if(dd[i][j]>cmn[j]) {flag=0; break;}
        }
        if(flag) {cmnb=i; for(int j=26;j>=1;j--) cmn[j]=dd[i][j]; continue;}
    }
    for(int i=1;i<=n;i++)
    {
        if(i==mnb)
        {
            int ncnt=0; for(int i=26;i>=1;i--) for(int j=1;j<=cmn[i]-cmn[i+1];j++) nt[++ncnt]=i;
        }
        else
        {
            int ncnt=0; for(int i=26;i>=1;i--) for(int j=1;j<=mn[i]-mn[i+1];j++) nt[++ncnt]=i;
        }
        int nc=0; for(int j=1;j<=26;j++) for(int p=1;p<=xx[i][j]-xx[i][j-1];p++) ns[++nc]=j;
        if(ck()) cout<<"1"; else cout<<"0";
    }
    cout<<endl;
}
