#include <cstdio>

using namespace std;

const int NR = 10;
int n, lock[NR];
int cnt[NR][NR][NR][NR][NR];
int ans;

int jump(int x, int step)
{
    if (x + step > 9) return x + step - 10;
    return x + step;
}

void dfs(int step)
{
    if (step == 6) return;
    int tmp1 = lock[step], tmp2 = lock[step + 1];
    for (int i = 1; i <= 9; i++)
    {
        lock[step] = jump(lock[step], i);
        if (++cnt[lock[1]][lock[2]][lock[3]][lock[4]][lock[5]] == n) ans++;
        if (step != 5)
        {
            lock[step + 1] = jump(lock[step + 1], i);
            if (++cnt[lock[1]][lock[2]][lock[3]][lock[4]][lock[5]] == n) ans++;
            lock[step + 1] = tmp2;
        }
        lock[step] = tmp1;
    }
    dfs(step + 1);
}


int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 5; j++)
            scanf("%d", &lock[j]);
        dfs(1);
    }
    printf("%d\n", ans);
    return 0;
}