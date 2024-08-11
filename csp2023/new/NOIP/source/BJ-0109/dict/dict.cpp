#include <iostream>
using namespace std;
#define int long long
const int N=3e3+5;
int n,m;
char x[N][N];
int cnt[N][26];
int maxn[N],minx[N];
signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int i,j;
    scanf("%lld%lld",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%s",x[i]+1);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cnt[i][x[i][j]-'a']++;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<26; j++)
            if(cnt[i][j])
                break;
        minx[i]=j;
        for(j=25; j>=0; j--)
            if(cnt[i][j])
                break;
        maxn[i]=j;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            if(i!=j && minx[i]>=maxn[j])
                break;
        if(j==n+1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
    return 0;
}
