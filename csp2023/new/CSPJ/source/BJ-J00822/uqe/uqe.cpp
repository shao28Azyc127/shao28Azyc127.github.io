#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define int long long
int gcd(int x,int y)
{
    if(y == 0) return x;
    return gcd(y,x % y);
}
int zysfj(int x)
{
    int mul = 1;
    for(int i = 2; i * i <= x; i++)
    {
        int cnt = 0;
        while(x % i == 0)
        {
            x /= i;
            cnt++;
        }
        for(int j = 1; j <= cnt / 2; j++)
        {
            mul *= i;
        }
    }
    return mul;
}
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    while(t--)
    {
        int a,b,c;
        cin >> a >> b >> c;int ttttt = b * b - 4 * a * c;
        if(ttttt < 0)
        {
            cout << "NO\n";
            continue;
        }

        if(2 * a < 0)
        {
            if(abs((int)(sqrt(ttttt)) - sqrt(ttttt)) <= 1e-5)
            {
                int x = 0 - b - sqrt(ttttt);
                int tttt = 2 * a / gcd(x,2 * a),ttt = x / gcd(x,2 * a);
                //cerr << tttt << " " << ttt << endl;
                if(tttt < 0) tttt = -tttt,ttt = -ttt;
                if(tttt == 1 && ttt != 0) cout << ttt / tttt << endl;
                else if(ttt == 0) cout << "0\n";
                else cout << ttt << "/" << tttt <<endl;
                continue;
            }
            int tttt = 2 * a / gcd(-b,2 * a),ttt = -b / gcd(-b,2 * a);
            if(tttt < 0) tttt = tttt * -1,ttt = ttt * -1;
            if(tttt == 1 && ttt != 0) cout << ttt / tttt << "+";
            else if(ttt != 0)cout << ttt << "/" << tttt << "+";
            int x = zysfj(ttttt);
            if(-x / gcd(-x,2 * a) != 1)
            {
                if(2 * a / gcd(-x,2 * a) != 1)
                {
                    cout << -x / gcd(-x,2 * a) << "*sqrt(" << (ttttt) / x / x << ")" << "/" << 2 * a / gcd(-x,2 * a) << endl;
                }
                else{
                    cout << -x / gcd(-x,2 * a) << "*sqrt(" << (ttttt) / x / x << ")" << endl;
                }
            }
            else if(-x != 1)
            {
                if(2 * a / gcd(-x,2 * a) != 1)
                {
                    cout << "sqrt(" << ttttt / x / x << ")" << "/" << 2 * a / gcd(-x,2 * a)<< endl;
                }
                else{
                    cout << "sqrt(" << ttttt / x / x << ")" << endl;
                }
            }
            else if(2 * a / gcd(-x,2 * a) != 1) cout << "sqrt(" << ttttt << ")" << "/" << 2 * a << endl;
            else cout << "sqrt(" << ttttt << ")" << endl;
        }
        else
        {
            if(abs((int)(sqrt(ttttt)) - sqrt(ttttt)) <= 1e-5)
            {
                int x = 0 - b + sqrt(ttttt);
                int tttt = 2 * a / gcd(x,2 * a),ttt = x / gcd(x,2 * a);
                if(tttt < 0) tttt = -1 * tttt,ttt = -1 * ttt;
                //cerr << tttt << " " << ttt << endl;
                if(tttt == 1 && ttt != 0) cout << ttt / tttt << endl;
                else if(ttt == 0) cout << "0\n";
                else cout << ttt << "/" << tttt <<endl;
                continue;
            }
            int tttt = 2 * a / gcd(-b,2 * a),ttt = -b / gcd(-b,2 * a);
            if(tttt < 0) tttt = -tttt,ttt = -ttt;
            if(tttt == 1 && ttt != 0) cout << ttt / tttt << "+";
            else if(ttt != 0)cout << ttt << "/" << tttt << "+";
            int x = zysfj(ttttt);
            if(x / gcd(x,2 * a) != 1)
            {
                if(2 * a / gcd(x,2 * a) != 1)
                {
                    cout << x / gcd(x,2 * a) << "*sqrt(" << (ttttt) / x / x << ")" << "/" << 2 * a / gcd(x,2 * a) << endl;
                }
                else{
                    cout << x / gcd(x,2 * a) << "*sqrt(" << (ttttt) / x / x << ")" << endl;
                }
            }
            else if(x != 1)
            {
                if(2 * a / gcd(x,2 * a) != 1)
                {
                    cout << "sqrt(" << ttttt / x / x << ")" << "/" << 2 * a / gcd(x,2 * a)<< endl;
                }
                else{
                    cout << "sqrt(" << ttttt / x / x << ")" << endl;
                }
            }
            else if(2 * a / gcd(x,2 * a) != 1) cout << "sqrt(" << ttttt << ")" << "/" << 2 * a << endl;
            else cout << "sqrt(" << ttttt << ")" << endl;
        }
    }
    return 0;
}
