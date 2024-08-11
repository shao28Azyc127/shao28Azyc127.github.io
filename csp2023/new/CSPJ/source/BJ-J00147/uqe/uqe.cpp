#include<bits/stdc++.h>
#define int long long
using namespace std;
void cal(int a1, int a2)
{
    for(int i = 2; i <= max(a1, a2); i++)
    {
        while(a1 % i == 0 && a2 % i == 0)
        {
            a1 /= i;
            a2 /= i;
        }
    }
    if(a2 == 1) cout << a1 << endl;
    else cout << a1 << '/' << a2 << endl;
}
void cal4(int a1, int a2)
{
    for(int i = 2; i <= max(a1, a2); i++)
    {
        while(a1 % i == 0 && a2 % i == 0)
        {
            a1 /= i;
            a2 /= i;
        }
    }
    if(a1 == 0) return ;
    if(a2 == 1) cout << a1 << '+';
    else cout << a1 << '/' << a2 << '+';
}
int cal3(int a)
{
    int ans = 1;
    for(int i = 2; i * i <= a; i++)
    {
        while(a % (i * i) == 0)
        {
            a /= i;
            a /= i;
            ans *= i;
        }
    }
    return ans;
}
void cal2(int a1, int a2)
{
    for(int i = 2; i <= max(a1, a2); i++)
    {
        while(a1 % (i * i) == 0 && a2 % i == 0)
        {
            a1 /= i;
            a1 /= i;
            a2 /= i;
        }
    }
    int t = cal3(a1);
    if(t == 1)
    {
        if(a2 == 1) cout << "sqrt(" << a1 / t / t << ')' << endl;
        else cout << "sqrt(" << a1 / t / t << ")/" << a2 << endl;
    }
    else
    {
        if(a2 == 1) cout << t << "*sqrt(" << a1 / t / t << ')' << endl;
        else cout << t << "*sqrt(" << a1 / t / t << ")/" << a2 << endl;
    }
}
signed main()
{
    freopen("upe.in", "r", stdin);
    freopen("upe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        double d = b * b - 4 * a * c;
        if(d < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if((int)sqrt(d) * (int)sqrt(d) == d)
        {
            int a1 = sqrt(d) - b;
            int a2 = 2 * a;
            cal(a1, a2);
            continue;
        }
        cal4(-b, 2 * a);
        cal2(d, 2 * a);
    }
    return 0;
}
