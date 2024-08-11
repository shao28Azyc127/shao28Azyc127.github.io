#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(m <= 1) cout << 0 << endl;
        if(b == 0)
        {
            int t = -c;
            if(t < 0) cout << "NO" << endl;
            else
            {
                int sqr = sqrt(t);
                if(sqr * sqr == t) cout << sqr << endl;
                else
                {
                    for(int i = sqr; i >= 1; i--)
                        if(t % (i * i) == 0)
                        {
                            cout << i << "*" << "sqrt(" << t / i / i << ")" << endl;
                            break;
                        }
                }
            }
        }
        if(c == 0)
        {
            if(0 > -b / a) cout << 0 << endl;
            else
            {
                int g = __gcd(a, b);
                if(a < 0 && -b < 0)
                {
                    a = -a;
                    b = -b;
                }
                if(a / g == 1)
                    cout << b / g << endl;
                else
                    cout << -b / g << '/' << a / g << endl;
            }
        }
    }
    return 0;
}
