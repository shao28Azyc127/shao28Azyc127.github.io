#include<bits/stdc++.h>
using namespace std;
//#define int long long
void out_put(int a, int b)
{
    int tmp = __gcd(a, b);
    a /= tmp; b /= tmp;
    if (b < 0) a = -a, b = -b;
    if (a == 0) cout << 0;
    else if (b == 1) cout << a;
    else cout << a << "/" << b;
    cout << "\n";
}
int get_mx(int a)
{
    int x = sqrt(a);
    for (int i = x; i >= 1; i --)
        if (a % (i * i) == 0)
            return i;
    return 1;
}
void solve1(int a, int b, int c)
{
    int delta = b * b - 4 * a * c;
    if (b == 0)
    {
        int x = sqrt(delta);
        if (x * x == delta)
            out_put(x, 2 * a);
        else
        {
            int p = 1, q = 2 * a;
            x = get_mx(delta);
            delta /= (x * x); p *= x;
            int tmp = __gcd(p, q);
            p /= tmp, q /= tmp;
            if (p == 0)
            {
                cout << 0 << "\n";
                return ;
            }
            else if (p != 1)
                cout << p << "*";
            cout << "sqrt(" << delta << ")";
            if (q != 1)
                cout << "/" << q;
            cout << "\n";
        }
    }
    else if (c == 0)
    {
        if (abs(b) == b)
            cout << 0 << "\n";
        else
            out_put(-b, a);
    }
    else
    {
        int tmp = sqrt(delta);
        if (tmp * tmp != delta)
        {
            cout << "***\n";
            return ;
        }
        tmp = (-b + sqrt(delta)) / 2 / a;
        if (tmp * 2 * a != -b + sqrt(delta))
        {
            cout << "***\n";
            return ;
        }
        out_put(-b + sqrt(delta), 2 * a);
    }
}
void solve2(int a, int b, int c)
{
    int delta = b * b - 4 * a * c;
    if (b == 0)
    {
        int x = sqrt(delta);
        if (x * x == delta)
            out_put(-x, 2 * a);
        else
        {
            int p = 1, q = -2 * a;
            x = get_mx(delta);
            delta /= (x * x); p *= x;
            int tmp = __gcd(p, q);
            p /= tmp, q /= tmp;
            if (p == 0)
            {
                cout << 0 << "\n";
                return ;
            }
            else if (p != 1)
                cout << p << "*";
            cout << "sqrt(" << delta << ")";
            if (q != 1)
                cout << "/" << q;
            cout << "\n";
        }
    }
    else if (c == 0)
    {
        if (abs(b) != b)
            cout << 0 << "\n";
        else
            out_put(-b, a);
    }
    else
    {
        int tmp = sqrt(delta);
        if (tmp * tmp != delta)
        {
            cout << "***\n";
            return ;
        }
        tmp = (-b - sqrt(delta)) / 2 / a;
        if (tmp * 2 * a != -b - sqrt(delta))
        {
            cout << "***\n";
            return ;
        }
        out_put(-b - sqrt(delta), 2 * a);
    }
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T, M; cin >> T >> M;
    while (T --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            cout << "NO\n";
            continue;
        }
        if (a > 0)
            solve1(a, b, c);
        else
            solve2(a, b, c);
    }

    return 0;
}
