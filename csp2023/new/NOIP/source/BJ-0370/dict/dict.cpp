#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
char minn[3010][3010], maxn[3010][3010];

int n, m;

bool chk(int a, int b)
{
    for(int i = 0;i < m;i++)
        if(minn[a][i] > maxn[b][i]) return 0;
        else if(minn[a][i] < maxn[b][i])
        {
            return 1;
        }
    return 0;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d %d\n", &n, &m);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            scanf("%c", &minn[i][j]);
        }
        scanf("\n");
        sort(minn[i], minn[i] + m);
        for(int j = 0;j <= m-1;j++)
            maxn[i][j] = minn[i][m-j-1];
    }
    //for(int i = 1;i <= n;i++) cout << minn[i] << "\n";
    for(int i = 1;i <= n;i++)
    {
        bool flag = 0;
        for(int j = 1;j <= n;j++)
        {
            if(j == i) continue;
            if(!chk(i, j)) {flag = 1; break;}
        }
        if(flag) printf("0");
        else printf("1");
    }

    return 0;
}
