#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-5;

long long gcd(long long a, long long b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

long long a, b, c, dl, T, M;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> M;
    for(int rw = 1; rw <= T; rw++)
    {
        cin >> a >> b >> c;
        dl = b * b - 4 * a * c;
        if(dl < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if(abs(sqrt(dl) - (double)((long long)(sqrt(dl)))) < eps)
        {
            long long upr = -b + ((long long)(sqrt(dl)));
            long long lwr = 2 * a;
            if(a < 0)
            {
                upr = min(-b + ((long long)(sqrt(dl))), -b - ((long long)(sqrt(dl))));
            }
            else
            {
                upr = max(-b + ((long long)(sqrt(dl))), -b - ((long long)(sqrt(dl))));
            }
            long long tmpg = gcd(abs(upr), abs(lwr));
            upr /= tmpg;
            lwr /= tmpg;
            if(abs(lwr) == 1)
            {
                cout << upr / lwr << endl;
            }
            else
            {
                if(upr < 0 && lwr > 0)
                {
                    cout << upr << "/" << lwr << endl;
                }
                else if(upr > 0 && lwr > 0)
                {
                    cout << upr << "/" << lwr << endl;
                }
                else
                {
                    cout << -upr << "/" << -lwr << endl;
                }
            }
        }
        else
        {
            long long uprf = -b;
            long long lwr = 2 * a;
            long long tmpgf = gcd(abs(uprf), abs(lwr));
            //cerr << "asd " << tmpgf << " " << rw << " " << uprf << " " << lwr << endl;
            uprf /= tmpgf;
            if(uprf != 0)
            {
                if(abs(lwr / tmpgf) == 1)
                {
                    cout << uprf / (lwr / tmpgf) << "+";
                }
                else
                {
                    if((uprf > 0 && lwr > 0) || (uprf < 0 && lwr > 0))
                    {
                        cout << uprf << "/" << lwr / tmpgf << "+";
                    }
                    else
                    {
                        cout << -uprf << "/" << -lwr / tmpgf << "+";
                    }
                }
            }
            long long upre = dl;
            long long uprec = 1;
            for(long long i = (long long)(sqrt(dl)); i >= 1; i--)
            {
                if(abs(upre) % (i * i) == 0)
                {
                    uprec *= i;
                    upre /= (i * i);
                    break;
                }
            }
            if(abs(uprec) == abs(lwr))
            {
                cout << "sqrt(" << upre << ")" << endl;
            }
            else if((abs(uprec)) % abs(lwr) == 0)
            {
                cout << abs(uprec / lwr) << "*" << "sqrt(" << upre << ")" << endl;
            }
            else if(abs(lwr) % (abs(uprec)) == 0)
            {
                cout << "sqrt(" << upre << ")" << "/" << abs(lwr / uprec) << endl;
            }
            else
            {
                long long tmpge = gcd((abs(uprec)), abs(lwr));
                uprec /= tmpge;
                lwr /= tmpge;
                cout << abs(uprec) << "*" << "sqrt(" << upre << ")" << "/" << abs(lwr) << endl;
            }
        }
    }
    return 0;
}