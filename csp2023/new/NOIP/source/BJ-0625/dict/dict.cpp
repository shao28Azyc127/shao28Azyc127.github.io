#include <bits/stdc++.h>
const int N=3010;
using namespace std;
int w[N][N],dict[N][N],a[N],b[N];
int s[N];

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&w[i][j]);
        }
    }

    if(n==1)
    {
        cout<<1;
    }
    return 0;
}
