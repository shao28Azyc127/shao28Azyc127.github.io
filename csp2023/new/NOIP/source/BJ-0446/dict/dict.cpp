#include<iostream>
#include<cstdio>
using namespace std;
string s[3010],mins[3010],maxs[3010];
char minn[3010][3010],maxn[3010][3010];
long long minx[3010][3010],maxx[3010][3010];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)
    {
        cin >> s[i];
        s[i] = '$' + s[i];
    }
    for (int i = 1;i <= n;i++)
    {
        minn[i][m + 1] = 'z' + 1;
        for (int j = m;j >= 1;j--)
        {
            if (minn[i][j + 1] > s[i][j])
            {
                minn[i][j] = s[i][j];
                minx[i][j] = j;
            }
            else
            {
                minn[i][j] = minn[i][j + 1];
                minx[i][j] = minx[i][j + 1];
            }
        }
    }
    for (int i = 1;i <= n;i++)
    {
        maxn[i][m + 1] = 'a' - 1;
        for (int j = m;j >= 1;j--)
        {
            if (maxn[i][j + 1] < s[i][j])
            {
                maxn[i][j] = s[i][j];
                maxx[i][j] = j;
            }
            else
            {
                maxn[i][j] = maxn[i][j + 1];
                maxx[i][j] = maxx[i][j + 1];
            }
        }
    }
    for (int i = 1;i <= n;i++)
    {
        mins[i] = s[i];
        for (int j = 1;j <= m;j++)
            if (mins[i][j] > minn[i][j])
            {
                swap(mins[i][j],mins[i][minx[i][j]]);
                break;
            }
    }
    for (int i = 1;i <= n;i++)
    {
        maxs[i] = s[i];
        for (int j = 1;j <= m;j++)
            if (maxs[i][j] < maxn[i][j])
            {
                swap(maxs[i][j],maxs[i][maxx[i][j]]);
                break;
            }
    }
    for (int i = 1;i <= n;i++)
    {
        bool flag = true;
        for (int j = 1;j <= n;j++)
            if (j != i && mins[i] >= maxs[j])
                flag = false;
        if (flag) printf("1");
        else printf("0");
    }
    return 0;
}
