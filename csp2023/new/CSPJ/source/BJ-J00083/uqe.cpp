#include<iostream>
#include<cmath>
using namespace std;
int T, M;
int delta(int a, int b, int c)
{
    return b * b - 4 * a * c;
}
double root(int a, int b, int c)
{
    if(delta(a, b, c) < 0) return 0;
    int r1 = (-b + sqrt(delta(a, b, c))) / (2 * a);
    return r1;
}
double root2(int a, int b, int c)
{
    if(delta(a, b, c) < 0) return 0;
    int r2 = (-b - sqrt(delta(a, b, c))) / (2 * a);
    return r2;
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    while(T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(delta(a, b, c) < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else if(b == 0 && c < 0)
        {
            double d = sqrt(c) * 1.0;
            if((int)d != d) cout << "sqrt(" << -c << ")" << endl;
            else cout << sqrt(c) << endl;
        }
        else
        {
            cout << max(root(a, b, c), root2(a, b, c)) << endl;
        }
    }
    return 0;
}
