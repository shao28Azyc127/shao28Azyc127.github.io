#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


double F(double x)
{
    return x > 0 ? x : -x;
}


bool isInt(double x)
{
    return fabs(x - ((int)x)) < 1e-6;
}


bool Eq(double a, double b)
{
    return fabs(a - b) < 1e-6;
}


void output(double x)
{
    if(isInt(x))
    {
        cout << x;
    }
    else
    {
        for(int i = 2; i < 1000005; ++i)
        {
            if(isInt(x * i))
            {
                cout << (int)(x * i) << "/" << i;
                break;
            }
        }
    }
}



void Solve(int a, int b, int c)
{
    int dt = b * b - 4 * a * c;
    if(dt < 0)
        cout << "NO" << endl;

    else
    {
        double x1 = ((double)0 - b + sqrt(dt)) / 2 / a;
        double x2 = ((double)0 - b - sqrt(dt)) / 2 / a;
        double Max; int symbol;
        if(x1 > x2)
        {
            Max = x1;
            symbol = 1;
        }
        else
        {
            Max = x2;
            symbol = -1;
        }
        if(isInt(sqrt(dt)))
        {
            output(Max); cout << endl;
        }
        else
        {
            /*for(int r = dt; r >= 2; --r)
            {
                if()
            }*/
            double q1 = -((double)b / 2 / a), q2 = symbol * ((double)a / 2);
            if(!Eq(q1, 0))
            { output(q1); cout << '+'; }
            if(Eq(q2, 1)){
                cout << "sqrt(" << dt << ")" << endl;}
            else if(isInt(q2)){ printf("%d*sqrt(%d)\n", (int)q2, dt); }
            else if(isInt((double)1 / q2))
            {
                printf("sqrt(%d)/%d\n", (int)dt, (int)((double)1 / q2));
            }
            else
            {
                for(int d = 2; d < 1000005; ++d)
                {
                    if(isInt(q2 * d))
                    {
                        cout << (int)(q2 * d) << "/" << d;
                        printf("%d*sqrt(%d)/%d\n", (int)(q2 * d), dt, d);
                        break;
                    }
                }
            }
        }
    }
}


int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int t, m;
    cin >> t >> m;
    for(int i = 0; i < t; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        Solve(a, b, c);
    }
}
