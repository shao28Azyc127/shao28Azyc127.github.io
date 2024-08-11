#include <iostream>
using namespace std;
long long sqrt(long long a)
{
    long long i, ans = 1;
    for (i = 1; i <= abs(a); i++)
    {
        if (a % (i * i) == 0) ans = i;

    }
    return ans;
}
long long pds(long long a)
{
    for (int i = 1; i <= abs(a); i++)
    {
        if (i * i == a) return i;
        if (i * i > a) return -1;
    }
}
long long gcd(long long a, long long b)
{
    if (a == 0 || b == 0) return 1;
    long long ans = 1;
    for (int i = 2; i <= min(abs(a), abs(b)); i++)
    {
        if (a % i == 0 && b % i == 0) ans = i;
    }
    return ans;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out","w", stdout);
    long long T, M;
    cin >> T >> M;
    while (T--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (b * b - 4 * a * c == 0)
        {
            if (2 * a / gcd(-b, 2 * a) == 1) cout <<  -b / gcd(-b, 2 * a) << endl;
            else cout << -b / gcd(-b, 2 * a) << "/" << 2 * a / gcd(-b, 2 * a) << endl;
            continue;
        }
        int pfh = pds(b * b - 4 * a * c);
        if (pfh != -1)
        {
            if (2 * a / gcd(-b + pfh, 2 * a) == 1) cout <<  (-b + pfh) / gcd(-b + pfh, 2 * a) << endl;
            else cout << (-b + pfh) / gcd(-b + pfh, 2 * a) << "/" << 2 * a / gcd(-b + pfh, 2 * a) << endl;
            continue;
        }
        long long pfdgy = gcd(sqrt(b * b - 4 * a * c), 2 * a);//平方数的最大公约数
        long long pfx = sqrt(b * b - 4 * a * c);
        long long pfj =(b * b - 4 * a * c) / pfx / pfx;//平方数
        pfx = sqrt(b * b - 4 * a * c) / pfdgy;//平方数的系数
        long long pfc = 2 * a / pfdgy;//平方数的除
        long long dcdgy = gcd(-b, 2 * a);//单次项的最大公约数
        long long dcx = -b / dcdgy;//单次项的系数
        //cout << sqrt(b * b - 4 * a * c) << " ";
        long long dcc = 2 * a / dcdgy;//单次项的除数
        if (dcx != 0)
        {
            cout << dcx;
            if (dcc != 1) cout << "/" << dcc;
            cout << "+";
        }
        if (pfx != 1) cout << pfx << "*";
        cout << "sqrt(" << pfj << ")";
        if (pfc != 1) cout << "/" << pfc;
        cout << endl;
    }
    return 0;
}
