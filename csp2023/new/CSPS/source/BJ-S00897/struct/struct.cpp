#include <bits/stdc++.h>
using namespace std;
const int N = 105;
#define pii pair<int, int>
#define mp make_pair
#define int long long
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int n;
int addr; // total address number
int cnt; // struct number
int stz[N]; // struct size
int sty[N][N]; // struct type
int maxn[N]; // struct addr
char stn[N][N]; // struct name
char st[N][N][N]; // struct
int cnt2; // member number
char mn[N][N]; // member name
int ma[N]; // member addr
int mad[N][N]; // member addr detail
int mz[N]; // member size
int mbl[N]; // member belong
char cur[N];
map<int, pair<int, int> > bl; // address bl to
int check()
{
    if (cur[1] == 'b' && cur[2] == 'y' && cur[3] == 't' && cur[4] == 'e' && strlen(cur + 1) == 4) return 1;
    if (cur[1] == 's' && cur[2] == 'h' && cur[3] == 'o' && cur[4] == 'r' && cur[5] == 't' && strlen(cur + 1) == 5) return 2;
    if (cur[1] == 'i' && cur[2] == 'n' && cur[3] == 't' && strlen(cur + 1) == 3) return 4;
    if (cur[1] == 'l' && cur[2] == 'o' && cur[3] == 'n' && cur[4] == 'g' && strlen(cur + 1) == 4) return 8;
    for (int i = 1; i <= cnt; i++)
    {
        if (strlen(cur + 1) != strlen(stn[i] + 1)) continue;
        int len = strlen(cur + 1), flag = 1;
        for (int j = 1; j <= len; j++) if (cur[j] != stn[i][j]) flag = 0;
        if (flag == 1) return 8 + i;
    }
    return -1;
}
signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++)
    {
        int op = read();
        if (op == 1)
        {
            cnt++;
            scanf("%s", (stn[cnt] + 1));
            stz[cnt] = read();
            int S = 0;
            for (int j = 1; j <= stz[cnt]; j++)
            {
                scanf("%s", (cur + 1));
                sty[cnt][j] = check();
                S = ((S + sty[cnt][j] - 1) / sty[cnt][j]) * sty[cnt][j];
                maxn[i] = max(maxn[i], check());
                S += sty[cnt][j];
                scanf("%s", st[cnt][j] + 1);
            }
            printf("%lld %lld\n", ((S + maxn[i] - 1) / maxn[i]) * maxn[i], maxn[i]);
        }
        if (op == 2)
        {
            cnt2++;
            scanf("%s", (cur + 1));
            int lht = check();
            // cout << lht << '!' << endl;
            scanf("%s", (mn[cnt2] + 1));
            if (lht <= 8)
            {
                ma[cnt2] = ((addr + lht - 1) / lht) * lht; addr = ma[cnt2];
                for (int j = 0; j < lht; j++) bl[addr + j] = mp(cnt2, 0); 
                addr += lht;
            }
            else
            {
                ma[cnt2] = ((addr + maxn[lht - 8] - 1) / maxn[lht - 8]) * maxn[lht - 8]; addr = ma[cnt2];
                int cc = 0; mz[cnt2] = stz[lht - 8];
                for (int j = 1; j <= stz[lht - 8]; j++)
                {
                    cc = ((cc + sty[lht - 8][j] - 1) / sty[lht - 8][j]) * sty[lht - 8][j];
                    mad[cnt2][j] = addr + cc;
                    for (int k = cc; k < cc + sty[lht - 8][j]; k++) bl[k + addr] = mp(cnt2, j);
                    cc += sty[lht - 8][j];
                }
                addr += ((cc + maxn[lht - 8] - 1) / maxn[lht - 8]) * maxn[lht - 8];
                mbl[cnt2] = lht - 8;
            }
            printf("%lld\n", ma[cnt2]);
        }
        if (op == 3)
        {
            scanf("%s", (cur + 1));
            int len = strlen(cur + 1), ask = 0;
            for (int j = 1; j <= cnt2; j++)
            {
                if (len < strlen(mn[j] + 1)) continue;
                int flag = 1;
                for (int k = 1; k <= strlen(mn[j] + 1); k++) if (cur[k] != mn[j][k]) flag = 0;
                if (!flag) continue;
                ask = j;
                break;
            }
            int len2 = strlen(mn[ask] + 1);
            if (cur[len2 + 1] == '.')
            {
                int len3 = len - len2 - 1, zzt = 0;
                // cout << mbl[ask] << '!' << endl;
                for (int j = 1; j <= mz[ask]; j++)
                {
                    if (len3 != strlen(st[mbl[ask]][j] + 1)) continue;
                    int flag = 1;
                    for (int k = 1; k <= len3; k++)
                    {
                        if (cur[len2 + k + 1] != st[mbl[ask]][j][k]) flag = 0;
                        // cout << st[mbl[ask]][j][k];
                    }
                    // cout << endl;
                    // for (int k = 1; k <= len3; k++)
                    // {
                    //     cout << cur[len2 + k + 1];
                    // }
                    // cout << endl;
                    if (!flag) continue;
                    zzt = j;
                    break;
                }
                // cout << ask << ' ' << zzt << endl;
                printf("%lld\n", mad[ask][zzt]);
            }
            else printf("%lld\n", ma[ask]);
        }
        if (op == 4)
        {
            int cc = read();
            if (bl[cc].first)
            {
                if (bl[cc].second)
                {
                    int pos = bl[cc].first, lht = bl[cc].second;
                    for (int j = 1; j <= strlen(mn[pos] + 1); j++) printf("%c", mn[pos][j]);
                    printf(".");
                    for (int j = 1; j <= strlen(st[mbl[pos]][lht] + 1); j++) printf("%c", st[mbl[pos]][lht][j]);
                    puts("");
                }
                else
                {
                    int pos = bl[cc].first;
                    for (int j = 1; j <= strlen(mn[pos] + 1); j++) printf("%c", mn[pos][j]);
                    puts("");
                }
            }
            else puts("ERR");
        }
    }
    return 0;
}
// 5
// 1 a 2
// short aa
// int ab
// 2 a x
// 3 x.ab