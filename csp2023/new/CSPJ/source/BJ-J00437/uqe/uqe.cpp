#include<iostream>
#include<cstdio>
#include<cmath>
#define NO "NO"
#define S(x) ((x >= 0?) : '+' : '-')

using namespace std;


int t, m;
int a = 0, b = 0, c = 0;

int main()
{
    void calc(int, int, int);

    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    cin >> t >> m;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;
        calc(a, b, c);
    }

    return 0;
}

inline int getd(int a, int b, int c)
{
    return b * b - 4 * a * c;
}

int judge(int a, int b, int c)
{
    int d;
    if ((abs(a) > m) || (abs(b) > m) || (abs(c) > m))
        return -1;
    else
    {
        d = getd(a, b, c);
        if (d < 0)
            return -1;
    }
    return d;
}

void calc(int a, int b, int c)
{
    void print();

    int d = judge(a, b, c);
    if (d == -1)
    {
        print();
        return;
    }
    else
    {
        if ((b == 0) && (c == 0))
        {
            cout << 0 << endl;
        }
        cout << (-b + sqrt(d)) / (2 * a) << endl;
    }
}

void print()
{
    cout << NO << endl;
}
