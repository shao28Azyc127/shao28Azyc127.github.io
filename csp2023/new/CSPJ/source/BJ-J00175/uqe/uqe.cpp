#include <bits/stdc++.h>
using namespace std;
void print(int q1, int q2, int q3, int r, int q4)
{

    if(r == 1)
    {
        q1 += q3;
        q3 = 0;
    }
    for(int i = 2; i <= min(abs(q1), abs(q2)); i++)
    {
        while(q1 % i == 0 && q2 % i == 0)
        {
            q1 /= i;
            q2 /= i;
        }
    }
    for(int i = 2; i <= min(abs(q3), abs(q4)); i++)
    {
        while(q3 % i == 0 && q4 % i == 0)
        {
            q3 /= i;
            q4 /= i;
        }
    }
    if(q1 == 0 && q3 == 0 || q1 % q2 == 0 && q1 != 0) cout << q1 / q2;
    else if(q1 != 0)
    {
        cout << q1 << "/" << q2;
    }

    if(q3 != 0 && r != 0)
    {
        if(q3 < 0 && q4 < 0)
        {
            q3 = q3 * -1;
            q4 *= -1;
        }
        if(q1 != 0)cout << '+';
        if(q3 != 1) cout << q3 << '*';
        cout << "sqrt(" << r << ')';
        if(q4 != 1) cout << '/' << q4;
    }
    cout << endl;
}
void jie(int a, int b, int c)
{
    int q1 = 0 - b, q2 = 2 * a, q3 = 1, q4 = 2 * a, r = b * b - 4 * a * c;
    //cout << r <<endl;
    for(int i = 2; i * i <= r; i++)
    {
        while(r % (i * i) == 0 && r != 0)
        {
            r /= i * i;
            q3 *= i;
        }
    }
    if(a > 0) print(q1, q2, q3, r, q4);
    else print(q1, q1, 0 - q3, r, q4);
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, n;
    cin >> t >> n;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(b * b - 4 * a * c < 0) cout << "NO" << endl;
        else jie(a, b, c);
    }
    return 0;
}
