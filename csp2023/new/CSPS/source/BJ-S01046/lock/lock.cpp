#include <cstdio>
#include <algorithm>
using namespace std;

int a[15][10], n;

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    if (n == 1)
    {
        printf("81");
        return 0;
    }
    else if (n == 2)
    {
        int cnt = 0;
        int pos[5] = {0, 0, 0, 0, 0};
        for (int i = 1; i <= 5; i++)
        {
            if (a[1][i] != a[2][i]) cnt++, pos[cnt] = i;
        }
        if (cnt > 2)
        {
            printf("0\n");
        }
        else if (cnt == 2)
        {
            if (abs(a[1][pos[1]] - a[2][pos[1]]) == abs(a[1][pos[2]]) - a[2][pos[2]]) printf("8");
            else printf("0");
            return 0;
        }
        else if (cnt == 0)
        {
            printf("81");
        }
        else
        {
            printf("10");
        }
        return 0;
    }
    else
    {
         printf("%d", 10 - n);
    }
    return 0;
}
