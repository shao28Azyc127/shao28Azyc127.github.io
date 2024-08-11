#include <bits/stdc++.h>
#define N 100005

using namespace std;

int h[N], hu[N], hf[N], hb[N];

struct dian
{
    char fu_hao;
    int xa;
    int xb; // xb = xa
};
dian st[N];

bool pai_xu(dian a, dian b)
{
    if(h[a.xa] == 100) return true;
    if(h[b.xa] == 100) return false;
    return a.xa < b.xa;
}
int ans, l;


void work(int x)
{
    int i, j, k;
    for(j=1; j<x; j++)
    {
        int a = st[j].xa;
        int b = st[j].xb;
        if(h[a] == 100 && h[b] != 100)
        {
            h[b] = 100;
            ans++;
        }
        if(h[b] == 100 && h[a] != 100)
        {
            h[a] = 100;
            ans++;
        }
    }
    return ;
}


int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while(T--)
    {
        int i, j, k;
        int n, m;
        cin >> n >> m;
        for(i=1; i<=n; i++)
        {
            h[i] = hu[i] = 0;
        }
        ans = 0;
        l = 0;
        char v;
        while(m--)
        {
            cin >> v;
            if(v == 'T' || v == 'F' || v == 'U')
            {
                int x;
                cin >> x;
                if(v == 'T')
                {
                    h[x] = 2;
                }
                else if(v == 'F')
                {
                    h[x] = -2;
                }
                else
                {
                    h[x] = 100;
                    hu[x]++;
                    if(hu[x] == 1)
                    {
                        ans++;
                    }
                }
            }
            else
            {
                st[++l].fu_hao = v;
                cin >> st[l].xb >> st[l].xa;
                if(st[l].xb < st[l].xa) swap(st[l].xb, st[l].xa);
            }
        }
        sort(st + 1, st + 1 + l, pai_xu);
        int a, b;
        int x;
        if(v == '+') x = 1;
        else x = -1;
        for(i=1; i<=l; i++) // yi you U
        {
            a = st[i].xa;
            b = st[i].xb;
            if(h[a] != 100 && h[b] != 100) continue;
            if(h[a] == 100)
            {
                h[b] = 100;
                hu[b]++;
                if(hu[b] == 1)
                {
                    ans++;
                }
                continue;
            }
            if(h[b] == 100)
            {
                h[a] = 100;
                hu[a]++;
                if(hu[a] == 1)
                {
                    ans++;
                }
                continue;
            }
        }
        for(i=1; i<=l; i++) // yi you T F
        {
            a = st[i].xa;
            b = st[i].xb;
            if(h[a] == 100) continue;
            if(h[a] == 0 && h[b] == 0) continue;
            if(h[a] != 0 && h[b] != 0) continue;

            if(h[a] == 0)
            {
                h[a] = x * h[b];
            }
            else
            {
                h[b] = x * h[a];
            }
        }
        int gs = 0;
        for(i=1; i<=l; i++)
        {
            a = st[i].xa;
            b = st[i].xb;
            if((h[a] == 100 && h[b] == 100) || h[a] == 2 || h[a] == -2) continue;
            // h[b] = x * h[a];
            if(h[a] == 0 && h[b] == 0)
            {
                h[a] = 1;
                h[b] = x * h[a];
            }
            else if(h[a] == 100)
            {
                h[b] = 100;
                ans++;
            }
            else if(h[b] == 100)
            {
                h[a] = 100;
                ans++;
            }
            else if(h[a] == 0 && h[b] != 0)
            {
                h[a] = x * h[b];
            }
            else if(h[a] != 0 && h[b] == 0)
            {
                h[b] = x * h[a];
            }
            else if(h[b] == -x * h[a])
            {
                h[a] = h[b] = 100;
                ans += 2;
                work(i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
