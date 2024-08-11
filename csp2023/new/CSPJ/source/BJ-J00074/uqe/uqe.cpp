#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int T, m;

inline int Ceil(double x)
{
    int t = x + 1;
    if (t * 1.0 - x == 1) return x;
    else return t;
}

int Gcd(int x, int y)
{
    if (y == 0) return abs(x);
    else return Gcd(y, x % y);
}

inline void print(int x, int y)
{
    if (y < 0) x *= -1, y *= -1;
    printf("%d/%d", x, y);
}

void work(int x, int y)
{
    if (x == 0) return;
    if (x % y == 0) printf("%d", x / y);
    else print((x / Gcd(x, y)), (y / Gcd(x, y)));
    return ;
}

void work1(int x, int y)
{
    if (sqrt(x) - Ceil(sqrt(x)) == 0)
    {
        work(sqrt(x), y);
        return ;
    }
    int a = 0, b = x, c = y;
    for (int i = 2; i * i * 2 <= x; i++)
    {
        if (x % (i * i) == 0)
        {
            a = i;
            b = x / (i * i);
        }
    }
    int k = Gcd(a, c);
    if (a != 0) a /= k, c /= k;
    if (a > 1) printf("%d*", a);
    printf("sqrt(%d)", b);
    if (c != 1) printf("/%d", c);
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &T, &m);
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0)
        {
            printf("NO\n");
            continue;
        }
        double tmp_tmp = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        double tmp_tmp1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        if (tmp_tmp - Ceil(tmp_tmp) == 0 && tmp_tmp1 - Ceil(tmp_tmp1) == 0)
        {
            printf("%d\n", (int)max(tmp_tmp1, tmp_tmp));
            continue;
        }
        double tmp = sqrt(b * b - 4 * a * c);
        if (tmp - Ceil(tmp) == 0)
        {
            if (a < 0) work(min(-b + sqrt(b * b - 4 * a * c), -b - sqrt(b * b - 4 * a * c)), 2 * a);
            else work(-b + sqrt(b * b - 4 * a * c), 2 * a);
            printf("\n");
            continue;
        }
        if (a < 0)
        {
            work(-b, 2 * a);
            if (b * b - 4 * a * c == 0) continue;
            if (b != 0) printf("+");
            work1(b * b - 4 * a * c, -2 * a);
        }
        else
        {
            work(-b, 2 * a);
            if (b * b - 4 * a * c == 0) continue;
            if (b != 0) printf("+");
            work1(b * b - 4 * a * c, 2 * a);
        }
        printf("\n");
    }
    return 0;
}
