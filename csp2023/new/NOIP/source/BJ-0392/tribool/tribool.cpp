#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct San;
vector <San> a;

struct San
{
    int from, value;  bool fan;

    inline void fu_v(char v)
    {
        if(v == 'T')  value = 1;
        if(v == 'F')  value = -1;
        if(v == 'U')  value = 0;
        from = fan = 0;
    }
    inline void fu(int x, bool xf)
    {
        if(a[x].value != 9)
        {
            if(xf)  value = -a[x].value;
            else    value =  a[x].value;
            from = fan = 0;
            return;
        }
        from = a[x].from;
        if(a[x].from == 0)  from = x;
        fan = xf ^ a[x].fan;
        value = 9;
    }
} ss;

const int Fadd = 100000;
const int Tfa = 200005;
const int Ffa = 200006;
const int Ufa = 200007;
int C, T, n, m, x, y, ans, fa[200010];
char o;

int getfa(int x)
{
    if(fa[x] == x)  return x;
    return fa[x] = getfa(fa[x]);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    scanf("%d%d", &C, &T);
    for(int i = 1; i <= 100005; i++)
    {
        a.push_back(ss);
    }
    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d", &n, &m);

        ans = 0;
        fa[Tfa] = Tfa;  fa[Ffa] = Ffa;  fa[Ufa] = Ufa;
        for(int i = 1; i <= n; i++)
        {
            fa[i] = i;  fa[i + Fadd] = i + Fadd;
            a[i].value = 9;
            a[i].from = a[i].fan = 0;
        }

        for(int i = 1; i <= m; i++)
        {
            o = getchar();
            while(o != 'T' && o != 'F' && o != 'U' && o != '+' && o != '-')  o = getchar();
            if(o == 'T' || o == 'F' || o == 'U')
            {
                scanf("%d", &x);
                a[x].fu_v(o);
            }
            else
            {
                scanf("%d%d", &x, &y);
                a[x].fu(y, o == '-');
            }
        }
        for(int i = 1; i <= n; i++)
        {
            //printf("%d: %d %d %d\n", i, a[i].value, a[i].from, a[i].fan);
            if(a[i].value == 9)
            {
                if(a[i].from == 0)  continue;
                if(a[i].fan)
                {
                    fa[getfa(i)] = getfa(a[i].from + Fadd);
                    fa[getfa(i + Fadd)] = getfa(a[i].from);
                }
                else
                {
                    fa[getfa(i)] = getfa(a[i].from);
                    fa[getfa(i + Fadd)] = getfa(a[i].from + Fadd);
                }
            }
            else
            {
                if(getfa(i) == getfa(i + Fadd))  continue;
                if(a[i].value == 1)
                {
                    fa[getfa(i)] = Tfa;
                    fa[getfa(i + Fadd)] = Ffa;
                }
                else if(a[i].value == -1)
                {
                    fa[getfa(i)] = Ffa;
                    fa[getfa(i + Fadd)] = Tfa;
                }
                else
                {
                    fa[getfa(i)] = fa[getfa(i + Fadd)] = Ufa;
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            //printf("%d: %d %d\n", i, getfa(i), getfa(i + Fadd));
            if(getfa(i) == getfa(i + Fadd) || getfa(i) == Ufa || getfa(i + Fadd) == Ufa)  ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
