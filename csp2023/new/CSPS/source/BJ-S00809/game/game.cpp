#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=8005;
int N;
char s[MAXN];
bool b[MAXN][MAXN];
int cnt[MAXN];
LL ans=0;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&N);
    scanf("%s",s+1);
    for(int i=2;i<=N;i++)
    {
        int l=i;
        if(s[i]==s[i-1]) b[i-1][i]=1,l=i-1;
        else
        {
            for(int j=i-1;j>=1;j--)
            {
                if(b[j][i-1]&&s[j-1]==s[i])
                {
                    l=j-1;
                    b[j-1][i]=1;
                    break;
                }
            }
        }
        if(i==l) continue;
        cnt[i]=1+cnt[l-1];
        for(int j=1;j<i;j++)
        {
            if(b[j][l-1]) b[j][i]=1;
        }
        ans+=cnt[i];
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}