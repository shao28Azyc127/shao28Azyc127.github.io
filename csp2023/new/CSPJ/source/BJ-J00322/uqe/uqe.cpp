#include<bits/stdc++.h>
using namespace std;

int T, m;
bool pr[1000005];
int primes[1000005];
int lp = 0;
void as()
{
    for(int i = 2; i < 1000005; i++)
    {
        if(pr[i])   continue;
        primes[++lp] = i;
        for(int j = 2; i * j < 1000005; j++)    pr[i * j] = 1;
    }
}
int gcd(int a , int b)
{
    if(!b)  return a;
    return gcd(b, a % b);
}
struct node {
    int p, q;
};
node operator + (node a, node b)
{
    int l = a.q * b.q;
    node c;
    c.p = a.p * b.q + a.q * b.p;
    c.q = l;
    return c;
}
void print(node x, int sqr)//p / q || p * sqr / q
{
    int p = x.p, q = x.q;
    int f;
    if((p > 0 && q > 0) || (p < 0 && q < 0))    f = 1;
    else    f = -1;
    p = abs(p), q = abs(q);
    int g = gcd(p, q);
    if(p == 0)  return ;
    else if(sqr == -1)
    {
        if (g == q) cout << f * p / g;
        else    cout << f * p / g << "/" << q / g;
    }
    else
    {
        if(p / g != 1)  cout << p / g << "*";
        if(g == q)  cout <<  "sqrt(" << sqr << ")";
        else    cout << "sqrt(" << sqr << ")" << "/" << q / g;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> m;
    as();
    while(T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if(delta < 0)   cout << "NO";
        else
        {
            int t = delta, cntpri = 1, power = 1, cntpow = 0;
            while(t > 1)
            {
                cntpow = 0;
                while(t >= primes[cntpri] && t % primes[cntpri])  cntpri++;
                while(t % primes[cntpri] == 0)  cntpow++, t /= primes[cntpri];
                while(cntpow > 1)   power *= primes[cntpri], cntpow -= 2;
            }
            node t1 = {-b, 2 * a};
            int de = delta / power / power;
            if(c == 0)
            {
                if(b == 0 || (double) -a *1.0 / b < 0)  cout << 0;
                else    print((node){-b, a}, -1);
            }
            else if(de == 0)
            {
                if(b == 0)  cout << 0;
                else    print(t1, -1);
            }
            else if(de == 1)
            {
                if(a > 0)   print((t1 + (node){power, 2 * a}), -1);
                else    print(t1 + (node){-power, 2 * a}, -1);
            }
            else if(power == 1)
            {
                print(t1, -1);
                if(b != 0)  cout << "+";
                print({1, 2 * a}, de);
            }
            else
            {
                print(t1, -1);
                if(b != 0)  cout << "+";
                print((node){power, 2 * a}, de);
            }
        }
        cout << endl;
    }
    return 0;
}
