#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a, int b)
{
    if(b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out","w",stdout);
    int T, M;
    cin >> T >> M;
    while(T--)
    {
        int a, b, c;
        cin >> a >>b >>c;
        int delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            double t = sqrt(delta);
            if(t==(int)t)
            {
                int upper = 0;
                if(a > 0) upper = 0 - b + t;
                else upper = 0 - b - t;
                int lower = 2 * a;
                bool op = (upper >= 0);
                int all = 0;
                if(op)
                    all = gcd(upper, lower);
                else
                    all = gcd(0 - upper, lower);
                upper /= all;
                lower /= all;
                if(lower < 0)
                {
                    lower *= -1;
                    upper *= -1;
                }
                if(lower == 1)
                {
                    cout << upper << endl;
                }
                else
                {
                    cout << upper << "/" << lower << endl;
                }
            }
            else
            {
                int upper = 0 - b;
                int lower = 2 * a;
                if(upper != 0)
                {
                    bool op = (upper >= 0);
                    int all = 0;
                    if(op)
                        all = gcd(upper, lower);
                    else
                        all = gcd(0 - upper, lower);
                    upper /= all;
                    lower /= all;
                    if(lower < 0)
                    {
                        lower *= -1;
                        upper *= -1;
                    }
                    if(lower == 1)
                    {
                        if(upper != 0)cout << upper << "+";
                    }
                    else
                    {
                        cout << upper << "/" << lower << "+";
                    }
                }
                int q2=1;
                for(int i = 1; i <= t; i++)
                {
                    if(delta % (i * i) == 0) q2 = i;
                }
                int r = delta / q2 / q2;
                upper = q2;
                lower = 2 * a;
                int all = gcd(upper, lower);
                upper /= all;
                lower /= all;
                if(lower < 0)
                {
                    lower *= -1;
                    upper *= -1;
                }
                if(abs(upper) == 1 && lower == 1)
                {
                    cout << "sqrt(" << r  << ")" << endl;
                }
                else if(abs(upper) != 1 && lower == 1)
                {
                    cout << abs(upper) << "*" <<"sqrt(" << r  << ")" << endl;
                }
                else if(abs(upper) == 1 && lower != 1)
                {
                    cout << "sqrt(" << r  << ")/" << lower << endl;
                }
                else
                {
                    cout << abs(upper) << "*" <<"sqrt(" << r  << ")/" << lower << endl;
                }
            }
        }
    }
    return 0;
}
