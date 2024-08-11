#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=20;
int n;
char ch[maxn];
int f[maxn][maxn];
int dp(int l,int r)
{
    if(f[l][r]!=-1) return f[l][r];
    if(l>=r) return f[l][r]=0;
    int ans=0;
    if(ch[l]==ch[r])  ans=dp(l-1,r-1);
    for(int k=l+1;k<=r-1;k++)
        if(dp(l,k-1)+dp(k,r)>ans) ans=f[l][k-1]+f[k][r];
    return f[l][r]=ans;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    scanf("%s",ch+1);
    if(n<=8000)
    {
        ms(f,-1);
        _for(i,1,n) f[0][i]=f[i][0]=0;

        cout<<dp(1,n)<<endl;
    }
    else cout<<"100";
    return 0;
}
