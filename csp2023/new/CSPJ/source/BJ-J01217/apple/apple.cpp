#include <cstdio>

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n;
    scanf("%d", &n);

    int sum = 0;
    int ans = 0;
    int pos = n - 1;
    while (n)
    {
        sum++;
        n -= n / 3 + (n % 3 > 0);
        if (!ans)
            if (pos % 3 == 0)
                ans = sum;
            else
                pos = n - 1;
    }

    printf("%d %d\n", sum, ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}