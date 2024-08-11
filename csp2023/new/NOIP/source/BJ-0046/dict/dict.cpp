#include<bits/stdc++.h>
using namespace std;
const int maxn=6005;
int n,m,t[maxn],num,ans[maxn];
string s[maxn];
pair<string, int> p[2*maxn];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<26;j++) t[j]=0;
        for(int j=0;j<m;j++) t[s[i][j]-'a']++;
        for(int j=1;j<26;j++) t[j]=t[j-1]+t[j];
        for(int j=0;j<t[0];j++) s[i][j]='a';
        for(int j=1;j<26;j++)
            for(int k=t[j-1];k<t[j];k++) s[i][k]=char('a'+j);
        p[2*i-1]=make_pair(s[i],i+n);
        for(int j=0;j<26;j++) t[j]=0;
        for(int j=0;j<m;j++) t[s[i][j]-'a']++;
        for(int j=24;j>=0;j--) t[j]=t[j+1]+t[j];
        for(int j=25;j>=0;j--)
            for(int k=t[j+1];k<t[j];k++) s[i][k]=char('a'+j);
        p[2*i]=make_pair(s[i],i);
    }
    sort(p+1,p+1+2*n);
    for(int i=1;i<=n;i++) t[i]=0;
    for(int i=2*n;i>=1;i--)
    {
        if(p[i].second<=n)
        {
            if(t[p[i].second]==0) num++;
            t[p[i].second]=1;
            continue;
        }
        ans[p[i].second-n]=max(ans[p[i].second-n],num-t[p[i].second-n]);
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==n-1) cout<<1;
        else cout<<0;
    }
    cout<<'\n';
    return 0;
}
