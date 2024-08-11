#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int N=8010;
const int INF=0x3f3f3f3f;

bool f[N][N];
char c[N];
int n;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    scanf("%d",&n);
    scanf("%s",(c+1));

    for (int i=1;i<n;i++)
    {
        if (c[i]==c[i+1]) f[i][i+1]=1;
    }
    for (int len=3;len<=n;len++)
    {
        for (int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            for (int k=l;k<r;k++)
            {
                if (f[l][k] && f[k+1][r]) f[l][r]=true;
            }
            if (!f[l][r] && c[l]==c[r]) f[l][r]=f[l+1][r-1];
        }
    }
    int res=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            if (f[i][j]) res++;
        }
    }
    printf("%d",res);
    return 0;
}
