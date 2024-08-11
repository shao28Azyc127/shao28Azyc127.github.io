#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN=2000002;
string s;
int lst[MAXN][26],mat[MAXN];//index [1,n]
int f[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>s;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            mat[i+1]=i;
            for(int j=0;j<26;j++)
                lst[i+1][j]=lst[i-1][j];
            if(i>=2)
                lst[i+1][s[i-2]-'a']=i-1;
        }
        else
        {
            mat[i+1]=lst[i][s[i]-'a'];
            if(!mat[i+1])   continue;
            for(int j=0;j<26;j++)
                lst[i+1][j]=lst[mat[i+1]-1][j];
            if(mat[i+1]>=2)
                lst[i+1][s[mat[i+1]-2]-'a']=mat[i+1]-1;
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<mat[i]<<' ';
    for(int i=1;i<=n;i++)
        if(mat[i])  f[i]=f[mat[i]-1]+1;
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=f[i];
    cout<<ans;
    return 0;
}