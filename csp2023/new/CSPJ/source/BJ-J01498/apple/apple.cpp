#include <cstdio>
using namespace std;

int cnt[100005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n <= 3)
    {
        printf("%d %d", n, n);
        return 0;
    }
    if (n % 3 == 1)
    {
        int t = n;
        int cur = 0;
        while (t != 0)
        {
            if (t % 3 == 0) t -= t / 3;
            else t -= t / 3 + 1;
            cur++;
        }
        printf("%d %d", cur, 1);
        return 0;
    }
    cnt[1] = 2, cnt[2] = 1, cnt[3] = 0;
    int cur = 3, t = -1;
    for (int i = 4; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= cur; j++)
        {
            if (cnt[j] == 2 && flag)
            {
                cnt[j] = 0;
                t = j;
                flag = false;
                break;
            }
            else
            {
                if (flag) cnt[j]++;
            }
        }
        if (flag)
        {
            cur++;
            cnt[cur] = 0;
            t = cur;
        }
    }
    printf("%d %d", cur, t);
    return 0;
}
