#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 3005
#define MAXM 3005

int n, m;
int ans[MAXN];

struct vol
{
    //char v[MAXM], rev[MAXM];
    int id, box[27], a[27], rea[27];
    bool f;
}vo[MAXN];

char read()
{
    char c = getchar();
    while (c < 'a' || c > 'z')
    {
        c = getchar();
    }
    return c;
}

bool cmp1(char x, char y)
{
    return x < y;
}

bool cmp2(vol x, vol y)
{
    for (int i = 25; i >= 0; --i)
    {
        if (x.box[i] != y.box[i]) return x.box[i] < y.box[i];
    }
    return true;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(vo[i].box, 0, sizeof(vo[i].box));
        for (int j = 1; j <= m; ++j)
        {
            vo[i].box[read() - 'a']++;
        }
        vo[i].a[0] = vo[i].box[0];
        vo[i].rea[0] = vo[i].box[25];
        for (int i = 1; i < 26; ++i)
        {
            vo[i].a[i] = vo[i].a[i - 1] + vo[i].box[i];
            vo[i].rea[i] = vo[i].rea[i + 1] + vo[i].box[25 - i];
        }
        //sort(vo[i].v + 1, vo[i].v + m + 1, cmp1);
        vo[i].id = i;
        /*for (int j = 1; j <= m; ++j)
        {
            vo[i].rev[j] = vo[i].v[m + 1 - j];
        }*/
    }
    sort(vo + 1, vo + n + 1, cmp2);
    for (int i = 1; i <= n; ++i)
    {
        int cp = 1 + (i == 1);
        vo[i].f = false;
        int curi = 0, curp = 25;
        while (vo[i].box[curi] == 0)
        {
            curi++;
        }
        while (vo[cp].box[curp] == 0)
        {
            curp--;
        }
        if (curi < curp) vo[i].f = true;
        else if (curi == curp)
        {
            if (vo[i].box[curi] < vo[cp].box[curp]) vo[i].f = true;
            else if (vo[i].box[curi] == vo[cp].box[curp] && vo[i].box[curi] != m) vo[i].f = true;
        }
        ans[vo[i].id] = vo[i].f;
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d", ans[i]);
    }
    return 0;
}
