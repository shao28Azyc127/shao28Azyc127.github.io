#ifdef OJ
#include <iostream>
#else
#include <fstream>
#endif
#include <math.h>

using namespace std;

#ifndef OJ
ifstream cin("uqe.in");
ofstream cout("uqe.out");
#endif

int T, M, a, b, c, delt, iq;

int gcdi(int x, int y)
{
    return (x == y || y == 0) ? x : (gcdi(y, x%y));
}

int gcd(int x, int y)
{
    if(x < y) swap(x, y);
    return gcdi(x, y);
}

void fracout(int x, int y)
{
    bool sgnd = (x*y<0);
    x = ((x>0) ? x : (-x));
    y = ((y>0) ? y : (-y));
    if(sgnd) cout << '-';
    int t = gcd(x, y);
    if(y/t == 1) cout << x/t;
    else cout << x/t << '/' << y/t;
}

void deltout(int x, int y, int s)
{
    x = ((x>0) ? x : (-x));
    y = ((y>0) ? y : (-y));
    int t = gcd(x, y);
    x /= t, y /= t;
    if(x != 1) cout << x << '*';
    cout << "sqrt(" << s << ")";
    if(y != 1) cout << "/" << y;
}

int isqrt(int x)
{
    return sqrt(x);
}

void ansq(int x, int iq, int &n, int &p)
{
    for(int i = iq; i > 0; i--)
    {
        if(x%(i*i) == 0)
        {
            n = i, p = x/(i*i);
            return;
        }
    }
}

int main(int argc, char **argv)
{
    cin >> T >> M;
    while(T--)
    {
        cin >> a >> b >> c;
        delt = b*b-4*a*c;
        if(delt < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        iq = isqrt(delt);
        if(iq*iq == delt)
        {
            b = ((a > 0) ? (-b+iq) : (-b-iq));
            fracout(b, 2*a);
            cout << endl;
            continue;
        }
        else
        {
            if(b != 0)
            {
                fracout(-b, 2*a);
                cout << "+";
            }
            int n, p;
            ansq(delt, iq, n, p);
            deltout((n > 0) ? n : (-n), (2*a > 0) ? (2*a) : (-2*a), p);
            cout << endl;
        }
    }
    return 0;
}