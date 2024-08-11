#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N (3000 + 10)

char s[N][N];
char big[N][N], smallest[N];
char small[N][N];

inline bool cmp(char a, char b)
{
    return a > b;
}

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    memcpy(big, s, sizeof(s));
    memcpy(small, s, sizeof(s));
    for (int i = 0; i < m; i++)
        smallest[i] = 'z' + 1;

    for (int i = 0; i < n; i++)
    {
        sort(big[i], big[i] + m, cmp);
        sort(small[i], small[i] + m);

        bool flag = false;
        for (int j = 0; j < m; j++)
            if (big[i][j] < smallest[j])
            {
                flag = true;
                break;
            }
            else if (big[i][j] > smallest[j])
                break;
        if (flag)
            memcpy(smallest, big[i], sizeof(big[i]));
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
            if (small[i][j] < smallest[j])
                break;
            else if (small[i][j] > smallest[j])
            {
                flag = false;
                break;
            }
        putchar(flag + '0');
    }
    putchar('\n');

    fclose(stdin);
    fclose(stdout);

    return 0;
}