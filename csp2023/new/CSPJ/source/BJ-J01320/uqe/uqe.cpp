#include<bits/stdc++.h>
using namespace std;
int T,M;
double gcd(double a,double b)
{
    double t = a / b;
    t *= b;
    if (t == 0) return b;
    return gcd(b,t);
}
void solve()
{
    double a,b,c;
    cin >> a >> b >> c;
    double drt = b * b - 4.0 * a * c;
    if (drt < 0)
    {
        cout << "NO";
        return ;
    }
    double x1 = (sqrt(drt) - b) / (2.0 * a),x2 = (sqrt(drt) + b) / (2.0 * a);
    if (drt == 0)
    {

        if (x1 == int(x1)) cout << x1;
        else cout << x1 << "/" << x2;
    }

    return ;
}
int main()
{
    freopen("uqe1.in","r",stdin);
    freopen("uqe1.out","w",stdout);
    cin >> T >> M;
    while (T > 0)
    {
        solve();
        cout << endl;
        T--;
    }
    return 0;
}