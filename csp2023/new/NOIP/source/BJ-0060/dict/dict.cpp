#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define ll long long
#define _1 first
#define _2 second
#define _mp make_pair
#define _pb push_back
#define MAX_N 3422

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');if(v)return -x;return x;}

int n, m;
char tmp[MAX_N];
char mx[MAX_N], pre[MAX_N], lst[MAX_N], mn[MAX_N];

void MAIN()
{
    n = read();
    m = read();
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", tmp + 1);
        char cmn = 126, cmx = 0;
        for(int j = 1; j <= m; j++)
            cmn = min(cmn, tmp[j]), cmx = max(cmx, tmp[j]);
        mn[i] = cmn, mx[i] = cmx;
    }
    pre[0] = 126;
    for(int i = 1; i <= n; i++)
        pre[i] = min(pre[i - 1], mx[i]);
    lst[n + 1] = 126;
    for(int i = n; i; i--)
        lst[i] = min(lst[i + 1], mx[i]);
    for(int i = 1; i <= n; i++)
        if(mn[i] < min(pre[i - 1], lst[i + 1]))
            putchar('1');
        else
            putchar('0');
    putchar('\n');
}

void CLEAR()
{
    ;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int T = 1;
    while(T--)
        MAIN(), CLEAR();
    return 0;
}
