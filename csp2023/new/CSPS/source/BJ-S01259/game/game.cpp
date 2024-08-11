#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
int n;
long long ans;
int iden[MAXN][MAXN];
char s[MAXN];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i+1])
        {
            ans++;
            iden[i][i+1]=1;
        }
    }
    for(int len=4;len<=n;len+=2)
    {
        for(int l=1;l<=n-len+1;l++)
        {
            int r=l+len-1;
            if(s[l]==s[r]&&iden[l+1][r-1])
            {
                iden[l][r]=1;
                ans++;
                continue;
            }
            for(int k=l+1;k<r-1;k++)
            {
                if(iden[l][k]&&iden[k+1][r])
                {
                    iden[l][r]=1;
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
