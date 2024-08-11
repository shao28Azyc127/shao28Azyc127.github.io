#include <cstdio>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, all = 0, last = 0;
    scanf("%d", &n);
    for (int i = 1; n > 0; ++i)
    {
        if (n % 3 == 1 && last == 0)
        {
            last = i;
        }
        n -= (n + 2) / 3;
        all = i;
    }
    printf("%d %d", all, last);

}
