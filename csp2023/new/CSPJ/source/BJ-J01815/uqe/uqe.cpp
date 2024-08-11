#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a,int b)
{
    while (b)
    {
        mod = a % b;
        a = b;
        b = mod;
    }
    return a;
}

void print(int a,int b);
{
    int _gcd = gcd(a,b);
    a /= _gcd;
    b /= _gcd;
    if (b == 1)
    {
        cout << a << endl;
    }
    else
    {
        cout << a << "/" << b << endl;
    }
}

void main2()
{
    int a,b,c;
    cin >> a >> b >> c;
    int delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        cout << "NO" << endl;
        return;
    }
    double _sqrt = sqrt(delta);
    if (int(_sqrt) == _sqrt))
    {
        print(-b + _sqrt,2 * a);
        return;
    }
}

int main()
{
    int t,m;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    while (t--)
    {
        go();
    }
    return 0;
}