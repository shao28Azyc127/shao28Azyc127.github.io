#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3010];
int cnt[26];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; ++i) cin>>s[i],s[i]=' '+s[i];
    if(n==1) return cout<<1,0;
    string in1,in2; int wz1,wz2;
    for(int i=0; i<=m; ++i) in1+='z',in2+='z';
    for(int i=1; i<=n; ++i)
    {
        memset(cnt,0,sizeof(cnt));
        for(int j=1; j<=m; ++j) ++cnt[s[i][j]-'a'];
        string now=" ";
        for(int j=25; j>=0; --j)
        {
            for(int k=1; k<=cnt[j]; ++k) now+='a'+j;
        }
        if(in1>now) in2=in1,wz2=wz1,in1=now,wz1=i;
        else if(in2>now) in2=now,wz2=i;
    }
    for(int i=1; i<=n; ++i)
    {
        memset(cnt,0,sizeof(cnt));
        for(int j=1; j<=m; ++j) ++cnt[s[i][j]-'a'];
        string now=" ";
        for(int j=0; j<26; ++j)
        {
            for(int k=1; k<=cnt[j]; ++k) now+='a'+j;
        }
        if(wz1==i) cout<<(now<in2?1:0);
        else cout<<(now<in1?1:0);
    }
    cout<<'\n';
    return 0;
}
