#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,len;
char ch[N];
long long s[26][N];
long long ans;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf(" %s",ch+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)s[i][j]=s[i-1][j];
        s[i][ch[i]-'a']++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            bool flag=1;
            for(int k=0;k<26;k++)
            {
                if((s[j][k]-s[i-1][k])%2!=0)flag=0;
                //printf("%lld ",s[j][k]-s[i-1][k]);
            }
            if(flag==1)
            {
                ans++;
                //printf("%d %d\n",i,j);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
