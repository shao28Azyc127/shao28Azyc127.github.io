#include<bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, m;
short bucket[N][26];
short mn[N], mx[N];
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    memset(mn, 0x3f, sizeof(mn));
    scanf("%d%d", &n, &m);
    if (n == 1)
    {
        char tmp;
        while (m--) scanf(" %c", &tmp);
        printf("1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        char tmp;
        for (int j = 1; j <= m; j++)
        {
            scanf(" %c", &tmp);
            bucket[i][tmp-'a']++;
            if (mn[i] > tmp) mn[i] = tmp;
            if (mx[i] < tmp) mx[i] = tmp;
        }
    }
    int flag=1;
    for (int i = 1; i <= n; i++)
    {
        flag = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if ((mn[i] > mx[j]) || 
            (mn[i] == mx[j] && bucket[i][mn[i]-'A'] != bucket[j][mx[j] - 'A']))
            {
                flag = 0;
                break;
            }
        }
        printf("%d", flag);
    }
    return 0;
}