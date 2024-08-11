#include<bits/stdc++.h>
using namespace std;

int t, m;
int a, b, c;
int x;
int fenzi, fenmu;
int fz, fm;
int xishu = 1;
int q1fenzi, q1fz;
int q2fenzi, q2fz;
int qfenmu, qfm;
int abc;

int gcd(int x, int y)
{
    if(x < y)
    {
        swap(x, y);
    }
    if(x % y == 0)
    {
        return y;
    }
    return gcd(y, x % y);
}

bool isSquare(int x)
{
    int a = sqrt(x);
    if(x == a * a)
    {
        return true;
    }
    return false;
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    while(t--)
    {
        fenzi = 0;
        fenmu = 0;
        cin >> a >> b >> c;
        int delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            if(isSquare(delta) == true)
            {
                fenzi = (abs(a) / a) * sqrt(delta) - b;
                fenmu = 2 * a;
                fz = abs(fenzi) / fenzi;
                fm = abs(fenmu) / fenmu;
                fenzi = abs(fenzi);
                fenmu = abs(fenmu);
                if(fenzi % fenmu == 0)
                {
                    if(fz * fm < 0)
                    {
                        cout << "-" << fenzi / fenmu << endl;
                    }
                    else
                    {
                        cout << fenzi / fenmu << endl;
                    }
                }
                else
                {
                    if(fz * fm < 0)
                    {
                        cout << "-" << fenzi / gcd(fenzi, fenmu) << "/" << fenmu / gcd(fenzi, fenmu) << endl;
                    }
                    else
                    {
                        cout << fenzi / gcd(fenzi, fenmu) << "/" << fenmu / gcd(fenzi, fenmu) << endl;
                    }
                }
            }
            else
            {
                xishu = 1;
                abc = 0;
                q1fenzi = -b;
                qfenmu = 2 * a;
                q1fz = abs(q1fenzi) / q1fenzi;
                qfm = abs(qfenmu) / qfenmu;
                q1fenzi = abs(q1fenzi);
                qfenmu = abs(qfenmu);
                if(q1fenzi == 0)
                {
                    abc = 1;
                }
                else
                {
                    if((q1fenzi / gcd(q1fenzi, qfenmu)) % (qfenmu / gcd(q1fenzi, qfenmu)) == 0)
                    {
                        if(q1fz * qfm < 0)
                        {
                            cout << "-" << (q1fenzi / gcd(q1fenzi, qfenmu)) / (qfenmu / gcd(q1fenzi, qfenmu));
                        }
                        else
                        {
                            cout << (q1fenzi / gcd(q1fenzi, qfenmu)) / (qfenmu / gcd(q1fenzi, qfenmu));
                        }
                    }
                    else
                    {
                        if(q1fz * qfm < 0)
                        {
                            cout << "-" << q1fenzi / gcd(q1fenzi, qfenmu) << "/" << qfenmu / gcd(q1fenzi, qfenmu);
                        }
                        else
                        {
                            cout << q1fenzi / gcd(q1fenzi, qfenmu) << "/" << qfenmu / gcd(q1fenzi, qfenmu);
                        }
                    }
                }
                for(int i = int(sqrt(delta));i >= 1;i--)
                {
                    if(delta % (i * i) == 0)
                    {
                        delta /= (i * i);
                        xishu *= i;
                    }
                }
                q2fenzi = (abs(a) / a) * xishu;
                q2fz = abs(q2fenzi) / q2fenzi;
                q2fenzi = abs(q2fenzi);
                if(q2fenzi / gcd(q2fenzi, qfenmu) == 1)
                {
                    if(qfenmu / gcd(q2fenzi, qfenmu) == 1)
                    {
                        if(q2fz * qfm < 0)
                        {
                            cout << "-sqrt(" << delta << ")" << endl;
                        }
                        else
                        {
                            if(abc == 1)
                            {
                                cout << "sqrt(" << delta << ")" << endl;
                            }
                            else
                            {
                                cout << "+sqrt(" << delta << ")" << endl;
                            }
                        }
                    }
                    else
                    {
                        if(q2fz * qfm < 0)
                        {
                            cout << "-sqrt(" << delta << ")/" << qfenmu / gcd(q2fenzi, qfenmu) << endl;
                        }
                        else
                        {
                            if(abc == 1)
                            {
                                cout << "sqrt(" << delta << ")/" << qfenmu / gcd(q2fenzi, qfenmu) << endl;
                            }
                            else
                            {
                                cout << "+sqrt(" << delta << ")/" << qfenmu / gcd(q2fenzi, qfenmu) << endl;
                            }
                        }
                    }
                }
                else
                {
                    if((q2fenzi / gcd(q2fenzi, qfenmu)) % (qfenmu / gcd(q2fenzi, qfenmu)) == 0)
                    {
                        if(q2fz * qfm < 0)
                        {
                            cout << "-" << (q2fenzi / gcd(q2fenzi, qfenmu)) / (qfenmu / gcd(q2fenzi, qfenmu)) << "*sqrt(" << delta << ")" << endl;
                        }
                        else
                        {
                            if(abc == 1)
                            {
                                cout << (q2fenzi / gcd(q2fenzi, qfenmu)) / (qfenmu / gcd(q2fenzi, qfenmu)) << "*sqrt(" << delta << ")" << endl;
                            }
                            else
                            {
                                cout << "+" << (q2fenzi / gcd(q2fenzi, qfenmu)) / (qfenmu / gcd(q2fenzi, qfenmu)) << "*sqrt(" << delta << ")" << endl;
                            }
                        }
                    }
                    else
                    {
                        if(q2fz * qfm < 0)
                        {
                            cout << "-" << (q2fenzi / gcd(q2fenzi, qfenmu)) << "*sqrt(" << delta << ")" << "/" <<  (qfenmu / gcd(q2fenzi, qfenmu)) << endl;
                        }
                        else
                        {
                            if(abc == 1)
                            {
                                cout << (q2fenzi / gcd(q2fenzi, qfenmu)) << "*sqrt(" << delta << ")" << "/" <<  (qfenmu / gcd(q2fenzi, qfenmu)) << endl;
                            }
                            else
                            {
                                cout << "+" << (q2fenzi / gcd(q2fenzi, qfenmu)) << "*sqrt(" << delta << ")" << "/" <<  (qfenmu / gcd(q2fenzi, qfenmu)) << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
