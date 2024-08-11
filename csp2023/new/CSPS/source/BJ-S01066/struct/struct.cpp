#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 110, K = 110;
//ll bsc[4], bsctab[4];

int n;
int k[N];
map <ll, ll> id[N], typid;
ll typ[N][K];
ll siz[N], tab[N], pre[N][K], nm[N][K];
int cnt = 4;

char in[15], len;
ll haxi()
{
    ll res = 0;
    for (int i = 0; i < len; i++)
        res = (res * 27) + (in[i] - 'a' + 1);
    return res;
}
char c = '#';
int getstr()
{
    len = 0;
    scanf(" %c", &c);
    while (true)
    {
        in[len++] = c;
        if (scanf("%c", &c) == EOF) return 0;
        if (c == '.') return 1;
        else if (c < 'a' || c > 'z') return 0;
    }
}
void out(ll x)
{
    len = 0;
    while (x)
    {
        in[++len] = (x % 27) + 'a' - 1;
        x /= 27;
    }
    for (int i = len; i >= 1; i--)
        printf("%c", in[i]);
}

void dfs1(ll now, ll sum)
{
    //printf("dfs1: %lld %lld\n", now, sum);
    int t = getstr();
    ll nxt = haxi();
    //printf("go to: %lld, %lld\n", nxt, id[now][nxt]);
    nxt = id[now][nxt];
    sum += pre[now][nxt];
    if (t == 0)
    {
        printf("%lld\n", sum);
        return;
    }
    else dfs1(typ[now][nxt], sum);
}

ll ans[K], anslen;
bool dfs2(ll now, ll x)
{
    //printf("dfs2: %lld %lld\n", now, x);
    if (now >= 1 && now <= 4) return true;
    for (int i = 1; i <= k[now]; i++)
    {
        if (pre[now][i] > x) return false;
        if (pre[now][i] + siz[typ[now][i]] > x)
        {
            anslen++;
            ans[anslen] = nm[now][i];
            return dfs2(typ[now][i], x - pre[now][i]);
        }
    }
    return false;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    in[0] = 'b', in[1] = 'y', in[2] = 't', in[3] = 'e';
    len = 4;
    typid[haxi()] = 1;
    siz[1] = tab[1] = 1;
    in[0] = 's', in[1] = 'h', in[2] = 'o', in[3] = 'r', in[4] = 't';
    len = 5;
    typid[haxi()] = 2;
    siz[2] = tab[2] = 2;
    in[0] = 'i', in[1] = 'n', in[2] = 't';
    len = 3;
    typid[haxi()] = 3;
    siz[3] = tab[3] = 4;
    in[0] = 'l', in[1] = 'o', in[2] = 'n', in[3] = 'g';
    len = 4;
    typid[haxi()] = 4;
    siz[4] = tab[4] = 8;

    scanf("%d", &n);
    int op;
    ll now2;
    while (n--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            cnt++;
            getstr();
            ll now = haxi();
            typid[now] = cnt;
            scanf("%d", &k[cnt]);
            ll sum = 0;
            for (int i = 1; i <= k[cnt]; i++)
            {
                getstr();
                now = haxi();
                now = typid[now];
                typ[cnt][i] = now;
                tab[cnt] = max(tab[cnt], tab[now]);
                pre[cnt][i] = (sum + tab[now] - 1) / tab[now] * tab[now];
                sum = pre[cnt][i] + siz[now];

                getstr();
                now2 = haxi();
                id[cnt][now2] = i;
                nm[cnt][i] = now2;
            }
            siz[cnt] = (sum + tab[cnt] - 1) / tab[cnt] * tab[cnt];
            printf("%lld %lld\n", siz[cnt], tab[cnt]);
        }
        if (op == 2)
        {
            getstr();
            ll now = haxi();
            now = typid[now];
            k[0]++;
            typ[0][k[0]] = now;
            pre[0][k[0]] = (siz[0] + tab[now] - 1) / tab[now] * tab[now];
            siz[0] = pre[0][k[0]] + siz[now];
            printf("%lld\n", pre[0][k[0]]);

            getstr();
            now2 = haxi();
            id[0][now2] = k[0];
            nm[0][k[0]] = now2;
        }
        if (op == 3)
        {
            dfs1(0, 0);
        }
        if (op == 4)
        {
            ll x;
            scanf("%lld", &x);
            anslen = 0;
            if (dfs2(0, x))
            {
                for (int i = 1; i <= anslen; i++)
                {
                    out(ans[i]);
                    if (i != anslen) printf(".");
                }
                printf("\n");
            }
            else printf("ERR\n");
        }
    }
    return 0;
}
