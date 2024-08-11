#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void solve();
int gcd(int a,int b);
void solve_x(int a,int b,int c);
int m;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    cin >> t >> m;
    while(t--)
    {
        solve();
    }
    return 0;
}
void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    solve_x(a,b,c);
}
void solve_x(int a,int b,int c)
{
    int x = -b;
    int y = b * b - 4 * a * c;
    int z = 2 * a;
    if(y < 0)
    {
        cout << "NO" << endl;
        return ;
    }
    else if(m == 1)
    {
        if(z < 0)
        {
            x -= 1;
            int t = gcd(x,z);
            x /= t;
            z /= t;
            if(z == 1) cout << x << '\n';
            else cout << x << '/' << z << '\n';
        }
        else
        {
            x += 1;
            int t = gcd(x,z);
            x /= t;
            z /= t;
            if(z == 1) cout << x << '\n';
            else cout << x << '/' << z << '\n';
        }
        return ;
    }
    if(c == 0)
    {
        if(1.0 * x / a < 0)
        {
            cout << 0 << ' ';
        }
        else
        {
            int t = gcd(x,a);
            x /= t;
            a /= t;
            if(a == 1)
            {
                cout << x << '\n';
            }
            else
            {
                cout << x << '/' << a << '\n';
            }
        }
        return ;
    }
    int t1 = (x + sqrt(y)) / z;
    int t2 = (x - sqrt(y)) / z;
    double x1 = (x + sqrt(y)) / z;
    double x2 = (x - sqrt(y)) / z;
    if(t1 == x1 && t2 == x2)
    {
        cout << max(x1,x2) << '\n';
    }
}
int gcd(int a,int b)
{
    if(b == 0) return a;
    return gcd(b,a % b);
}
