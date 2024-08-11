#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if(b > a) swap(a, b);
    if(a == b) return a;
    else return gcd(a - b, b);
}

ifstream fin("uqe.in", ios::in);
ofstream fout("uqe.out", ios::out);
void f(int a, int b)
{
    if(b / gcd(a, b) == 1)
    {
        fout << a / gcd(a, b);
    }
    else
    {
        fout << a / gcd(a, b) << "/" << b / gcd(a, b);
    }
}
int main()
{
    int t, n;
    fin >> t >> n;
    while(t--)
    {
        int a, b, c;
        fin >> a >> b >> c;
        int o = b * b - 4 * a * c;
        if(o < 0)
        {
            fout << "NO" << endl;
            continue;
        }
        else
        {
            if(pow(int(sqrt(o)), 2) == o)
            {
                double x1 = (-b + sqrt(o)) / (2 * a);
                double x2 = (-b - sqrt(o)) / (2 * a);
                bool flag = false;
                if(x1 < x2) swap(x1, x2), flag = true;
                int xa;
                xa = max(-b + sqrt(o), -b - sqrt(o));
                int xb = 2 * a;
                if(xb / gcd(xa, xb) == 1 || xb / gcd(xa, xb) == -1)
                {
                    fout << xa / gcd(xa, xb) << endl;
                }
                else
                {
                    fout << xa / gcd(xa, xb) << "/" << xb / gcd(xa, xb) << endl;
                }
            }
            else
            {
                int q1_zi = -b / gcd(-b, 2 * a);
                int q1_mu = (2 * a) / gcd(-b, 2 * a);
                int q2_zi = 1;
                int q2_mu = 2 * a;
                int st_o = o;
                for(int i = 1;i < 2000;i++)
                {
                    if(st_o % (i * i) == 0)
                    {
                        st_o /= (i * i);
                        q2_zi *= i;
                    }
                }
                int q2_zi_old = q2_zi, q2_mu_old = q2_mu;
                q2_zi = q2_zi / gcd(q2_zi_old, q2_mu_old);
                q2_mu = q2_mu / gcd(q2_mu_old, q2_zi_old);

                if(q1_zi != 0)
                {
                    f(q1_zi, q1_mu);
                    fout << "+";
                }
                if(q2_zi * 1.0 / q2_mu == 1.0)
                {
                    fout << "sqrt(" << st_o << ")" << endl;
                }
                else if(q2_zi % q2_mu == 0)
                {
                    fout << q2_zi % q2_mu << "*sqrt(" << st_o << ")" << endl;
                }
                else if(int(1 / (q2_zi * 1.0 / q2_mu)) == (1 / q2_zi * 1.0 / q2_mu))
                {
                    fout << "sqrt(" << st_o << ")/" << int(1 / (q2_zi * 1.0 / q2_mu)) << endl;
                }
                else
                {
                    fout << "~" << endl;
                }
            }
        }
    }
}
