#include<bits/stdc++.h>
using namespace std;
struct Range
{
    int st, ed;
};
int st[9][6];
int ans;
// int sing, duos;
int dist(int a,int b)
{
    if (a > b) b += 10;
    return b - a;
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
            scanf("%d", &st[i][j]);
    }
    // if (n==1) {printf("81"); return 0;}
    // start
    for (int i = 0; i <= 99999; i++)
    {
        int num[6];
        num[1] = i / 10000;
        num[2] = (i / 1000) % 10;
        num[3] = (i / 100) % 10;
        num[4] = (i / 10) % 10;
        num[5] = i % 10;
        // printf("i = %d, {%d, %d, %d, %d, %d}", i, num[1], num[2], num[3], num[4], num[5]);
        bool valid = 1;
        for (int j = 1; j <= n; j++)
        {
            int diff=0, duo = 0;
            for (int k = 1; k <= 5; k++)
            {
                if (num[k] != st[j][k])
                {
                    diff++;
                    if (diff == 1 && duo == 0) duo = k;
                    else if (diff == 2 && duo == k-1 && dist(num[k-1], num[k]) == dist(st[j][k-1], st[j][k])) duo = -1;
                    else {valid = 0; break;}
                }
            }
            if (diff == 0) valid = 0;
            if (!valid) break;
            // else if (duo != -1) {printf("%d\n", i);}
            // else if (duo == -1) duos++;
            // else sing++;
        }
        if (valid) {ans++;}
    }
    // printf("%d, %d\n", sing, duos);
    printf("%d\n", ans);
    return 0;
}
