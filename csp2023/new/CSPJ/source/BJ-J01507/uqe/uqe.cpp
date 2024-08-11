#include <bits/stdc++.h>
using namespace std;

int gcd(int p, int q)
{
    int a = p, b = q, c = a / b, d = a % b;
    while(d != 0)
    {
        a = b;
        b = d;
        c = a / b;
        d = a % b;
    }
    return b;+
}

int p1, q1;

int isy(int v)
{
    for (p1 = 1; p1 <= 100000; p1++)
    {
        for (q1 = p1; q1 <= 100000; q1++)
        {
            if(gcd(p1, q1) == 1 && v == p1 / q1)
            {
                return 1;
            }
        }
    }
}

int main()
{
    freopen("uqe.in". "r", stdin);
    freopen("uqe.out", "w", stdout);
    int n, k;
    cin >> n >> k
    for (int i = 1; i<= n; i++)
    {
        long long a, b, c;
        long long p, q;
        cin >> a >> b >> c;
        long long s = b * b - 4 * a * c;
        p = (-b - sqrt(s)) / (2 * a);
        q = (-b + sqrt(s)) / (2 * a);
        if(s < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            if(isy(q) == 1)
            {
                if(q1 == 1)
                {
                    cout << p1 << endl;
                }
                else
                {
                    cout << p1 / q1 << endl;
                }
            }
            else
            {
                for (int r = 1; r <= k; r++)
                {
                    for (int p2 = 1; p2 <= k; p2++)
                    {
                        for (int q2 = p2; q2 <= k; q2++)
                        {
                            if(isy(p2) = 1 && isy(q2) == 1 && p = p2 + q2 * sqrt(r))
                            {
                                if(p2 != 0)
                                {
                                    if(isy(p2) == 1)
                                    {
                                        if(p2 == 1)
                                        {
                                            cout << q2 << endl;
                                        }
                                        else
                                        {
                                            cout << q2 / p2 << endl;
                                        }
                                    }
                                    cout << "+";
                                }
                                if(q2 == 1)
                                {
                                    cout << "sqrt(" << r << ")" << endl;
                                }
                                else if(q2)
                            }
                        }
                    }
                }

            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
