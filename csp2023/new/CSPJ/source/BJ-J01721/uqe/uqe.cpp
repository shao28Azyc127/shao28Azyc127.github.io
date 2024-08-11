#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int m, t;
    cin >> t >> m;
    for(int n = 1;n <= t;n++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int t3 = b * b - 4 * a * c;
        if(t3 < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if(int(sqrt(t3)) * int(sqrt(t3)) == t3)
        {
            t3 = sqrt(t3);
            int t1 = 2 * a;
            int t2 = -b + t3;
            if(t2 == 0)
            {
                cout << 0 << endl;
                continue;
            }
            if(t1 < 0 && t2 > 0 || t1 > 0 && t2 < 0) cout << "-";
            t1 = abs(t1);
            t2 = abs(t2);
            int l = gcd(max(t1, t2), min(t1, t2));
            t1 /= l;
            t2 /= l;
            if(t2 != 0) cout << t2;
            if(t1 != 1) cout << "/" << t1;
            cout << endl;
            continue;
        }
        if(b != 0)
        {
            if(a < 0 && b < 0 || a > 0 && b > 0) cout << "-";
            int l = gcd(max(abs(2 * a), abs(b)), min(abs(2 * a), abs(b)));
            int t1 = abs(2 * a) / l;
            int t2 = abs(b) / l;
            cout << t2;
            if(t1 != 1) cout << "/" << t1;
            cout << "+";
        }
        int t1 = abs(2 * a);
        int c1 = 1;
        for(int i = 2;i * i <= t3;i++)
        {
            while(t3 % (i * i) == 0)
            {
                c1 *= i;
                t3 /= (i * i);
            }
        }
        int l = gcd(max(t1, c1), min(t1, c1));
        t1 /= l;
        c1 /= l;
        if(c1 != 1) cout << c1 << "*";
        cout << "sqrt(" << t3 << ")";
        if(t1 != 1) cout << "/" << t1;
        cout << endl;
    }
    return 0;
}
