#include <iostream>
#include <cstdio>

using namespace std;

int n, a[10][10], ans;

inline int check(int x, int j)
{
    int sum = 0, tot1 = 0, tot2 = 0, tmp1, tmp2;
    for(register int i = 5;i >= 1;i--)
    {
        if(a[j][i] == x % 10)
            sum++;
        else if(tot1)
            tot2 = i, tmp2 = a[j][i] < x % 10 ? 10 + a[j][i] - x % 10 : a[j][i] - x % 10;
        else
            tot1 = i, tmp1 = a[j][i] < x % 10 ? 10 + a[j][i] - x % 10 : a[j][i] - x % 10;
        x /= 10;
    }
    if(sum == 5)
        return false;
    if(sum < 3)
        return false;
    if(sum == 4)
        return true;
    if(tot1 == tot2 + 1 && tmp1 == tmp2)
        return true;
    return false;
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for(register int i = 1;i <= n;i++)
        for(register int j = 1;j <= 5;j++)
            scanf("%d", &a[i][j]);
    for(register int i = 0;i < 100000;i++)
    {
        bool flag = false;
        for(register int j = 1;j <= n;j++)
            if(!check(i, j))
                flag = true;
        if(!flag)
            ans++;
    }
    printf("%d", ans);
    return 0;
}
