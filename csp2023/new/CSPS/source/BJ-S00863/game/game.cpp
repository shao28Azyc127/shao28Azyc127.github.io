#include <cstdio>

#define N 2000000 + 10

int n;
char s[N];
char stack[N];
int top;
long long sum[N];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    scanf("%d%s", &n, s);

    for (int i = 0; i < n; i++)
    {
        int j = i;
        top = 0;
        for (; j >= 0; j--)
        {
            if (!top || s[j] != stack[top])
                stack[++top] = s[j];
            else
                top--;
            if (!top)
                break;
        }
        if (j)
            sum[i] = sum[j - 1];
        if (j >= 0)
            sum[i]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += sum[i];

    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}