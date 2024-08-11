#include<iostream>
#include<cstdio>
#include<cstring>
#define DB(x, y) v[x]

const int MAXL = 10e5 + 1;
typedef long long ll;
using namespace std;


int n;//number of site
int p;// distance per L
ll d = 0; // available distance
int s = 1; //present site
ll ans = 0;
int v[MAXL];// distance between two sites;a -> b: v_a
int a[MAXL];// price of every sites;

int main()
{
    void init(void);
    void calc(void);
    void print(void);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    init();
    cin >> n >> p;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    calc();
    print();

    return 0;
}

void init()
{
    memset(v, -1, sizeof(v));
    memset(a, -1, sizeof(a));
}

int disbet(int x, int y)
{
    int ret = 0;
    for (int i = x; i < y; i++)
    {
        ret += v[i];
    }
    return ret;
}

void calc()
{
    int i;
    ll t;//dis
    while(s <= n)
    {
        for (i = s + 1; i <= n; i++)
        {
            if (a[i] < a[s])
                break;
        }
        t = disbet(s, i);
        if (t >= d)
        {
            t -= d;
            d = 0;
            while (t > d)
            {
                d += p;
                ans += a[s];
            }
            d -= t;
        }
        else
        {
            d -= t;
        }

        s = i;
    }

}

void print()
{
    cout << ans << endl;
}