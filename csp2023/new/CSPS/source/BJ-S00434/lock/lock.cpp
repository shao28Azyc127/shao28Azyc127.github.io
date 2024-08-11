// 昨天漫展居然有大型 fumo！
// 话说上次漫展有一个灵梦 cos，这次变成旧作灵梦了，这是在暗示东方一年不如一年吗（笑

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <utility>
#include <tuple>
#include <vector>
#include <algorithm>

#define wzc(f) freopen(f".in", "r", stdin); freopen(f".out", "w", stdout)

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned i128;

bool b[10][10][10][10][10], c[10][10][10][10][10];
int a[5];

int main()
{
    wzc("lock");
    int n; scanf("%d", &n);
    memset(c, 1, sizeof c);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d %d", a, a + 1, a + 2, a + 3, a + 4);
        memset(b, 0, sizeof b);
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 10; k++)
            {
                a[j]++; if (a[j] == 10) a[j] = 0;
                if (k < 9)
                    b[a[0]][a[1]][a[2]][a[3]][a[4]] = true;
            }
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 10; k++)
            {
                a[j]++; if (a[j] == 10) a[j] = 0;
                a[j + 1]++; if (a[j + 1] == 10) a[j + 1] = 0;
                if (k < 9)
                    b[a[0]][a[1]][a[2]][a[3]][a[4]] = true;
            }
        for (int i = 0; i < 10; i++)
            for (int i2 = 0; i2 < 10; i2++)
                for (int i3 = 0; i3 < 10; i3++)
                    for (int i4 = 0; i4 < 10; i4++)
                        for (int i5 = 0; i5 < 10; i5++)
                            c[i][i2][i3][i4][i5] &= b[i][i2][i3][i4][i5];
    }
    int cnt = 0;
    for (int i = 0; i < 10; i++)
        for (int i2 = 0; i2 < 10; i2++)
            for (int i3 = 0; i3 < 10; i3++)
                for (int i4 = 0; i4 < 10; i4++)
                    for (int i5 = 0; i5 < 10; i5++)
                        cnt += c[i][i2][i3][i4][i5];
    printf("%d\n", cnt);
}