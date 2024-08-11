#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxd = 3000;

ll T, M;
ll a, b, c, delta, sd;
ll p, q, p1, p2, r;
ll sq[maxd];

struct frac
{
    ll a, b;
} f;

ll gcd (ll a, ll b)
{
    if (a % b == 0)
        return b;
    return gcd (b, a % b);
}

void initsq ()
{
    for (int i = 1; i <= 3 * M; i ++)
    {
        sq[i] = i * i;
    }
}

void init ()
{
    a = b = c = delta = sd = 0;
    p = q = p1 = p2 = r = 0;
}


void frac (ll a, ll b, ll c)
{
    string ans = "";
    ll gab = 0;
    if (c == 1)
        c = 0;
    if (a % b == 0)
    {
        if (c == 0)
            printf ("%lld", a / b);
        else if (a / b == 1)
            printf ("sqrt(%lld)", c);
        else
            printf ("%lld*sqrt(%lld)", a / b, c);
        return;
    }
    if (a * b < 0)
        printf ("-");
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    gab = gcd (a, b);
    a /= gab;
    b /= gab;
    if (a == 1 && c != 0)
    {
        printf ("sqrt(%lld)/%lld", c, b);
        return;
    }
    if (c == 0)
        printf ("%lld/%lld", a, b);
    else
        printf ("%lld*sqrt(%lld)/%lld", a, c, b);
}


int main ()
{
    freopen ("uqe.in", "r", stdin);
    freopen ("uqe.out", "w", stdout);
    cin >> T >> M;
    initsq ();
    while (T --)
    {
        init ();
        scanf ("%lld%lld%lld", &a, &b, &c);
        delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        sd = delta;
        if (floor (sqrt (delta)) == ceil (sqrt (delta)))
        {
            sd = sqrt (delta);
            p = (a > 0 ? sd - b : -sd - b);
            q = 2 * a;
            frac (p, q, 0);
            if (T)
                printf ("\n");
            continue;
        }
        p2 = 1;
        r = delta;
        for (int i = floor (sqrt (delta)); i >= 2; i --)
        {
            if (delta % sq[i] == 0)
            {
                r = delta / sq[i];
                p2 = i;
                break;
            }
        }
        p1 = -b;
        q = 2 * a;
        if (p1 != 0)
            frac (p1, q, 0);
        if (b != 0)
            printf ("+");
        frac ((q > 0 ? p2 : -p2), q, r);
        if (T)
            printf ("\n");
    }
    cout << endl;
    return 0;
}
