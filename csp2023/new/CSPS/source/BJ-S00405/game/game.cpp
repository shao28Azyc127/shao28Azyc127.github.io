#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int N = 2e6 + 10, SN = 2e5;
int stk[N];
char str[N];
int n;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, str);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int size = 0;
        for (int j = i; j < n; ++j)
        {
            if (size > 0 && stk[size - 1] == str[j])
            {
                --size;
            }
            else
            {
                stk[size++] = str[j];
            }
            if (size == 0)
            {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
}
