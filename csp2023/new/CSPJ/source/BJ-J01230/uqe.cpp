#include <fstream>
using namespace std;

ifstream fin("uqe.in");
ofstream fout("uqe.out");

int gcd(int A, int B)
{
    if (B == 0)
    {
        return A;
    }
    return gcd(B, A % B);
}

void print(int p, int q)
{
    int d = gcd(p, q);
    p /= d;
    q /= d;

    if (q == 1)
    {
        fout << p;
        return;
    }
    if (q == -1)
    {
        fout << -p;
        return;
    }
    if (p == 0)
    {
        fout << 0;
        return;
    }

    if (p < 0 && q < 0)
    {
        p = -p;
        q = -q;
    }
    if (p > 0 && q < 0)
    {
        p = -p;
        q = -q;
    }
    fout << p << '/' << q;
}

int main()
{
    int t, m;
    fin >> t >> m;
    int A, B, C;
    while (t--)
    {
        fin >> A >> B >> C;

        int delta = B * B - 4 * A * C;
        if (delta < 0)
        {
            fout << "NO" << endl;
            continue;
        }
        else if (delta == 0)
        {
            print(-B, 2 * A);
            fout << endl;
        }
        else
        {
            int r = 1;
            for (int i = 2; i * i <= delta; i++)
            {
                if (delta % (i * i) == 0)
                {
                    r = i;
                }
            }
            int x = r;
            r = delta / r / r;
            if (r == 1)
            {
                if (A > 0)
                {
                    print(x - B, 2 * A);
                    fout << endl;
                }
                else
                {
                    print(B - x, 2 * A);
                    fout << endl;
                }
                continue;
            }


            if (B != 0)
            {
                print(-B, 2 * A);
                fout << '+';
            }
            if (A < 0)
            {
                A = -A;
            }

            if (2 * A == x)
            {
                fout << "sqrt(" << r << ")" << endl;
            }
            else if (x % (2 * A) == 0)
            {
                fout << (x / (2 * A)) << "*sqrt(" << r << ")" << endl;
            }
            else if ((2 * A) % x == 0)
            {
                fout << "sqrt(" << r << ")/" << ((2 * A) / x) << endl;
            }
            else
            {
                int gc = gcd(2 * A, x);
                int C = x / gc, D = 2 * A / gc;
                fout << C << "*sqrt(" << r << ")/" << D << endl;
            }
        }
    }
}
