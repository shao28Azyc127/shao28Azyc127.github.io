#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int NR = 1e5+4;
int gcd(int a, int b)
{
    if(a == b) return a;
    if(b == 1) return 1;
    if(a < b) return gcd(b, a);
    return (b, a - b);
}
void workA(int a, int b, int c)
{
    int derta = b * b - 4 * a * c;
        if(derta < 0)
        {
            puts("NO");
            return;
        }
        int x1 = (-b + sqrt(1.0 * derta)) / (2 * a);
        int x2 = (-b - sqrt(1.0 * derta)) / (2 * a);
        cout << max(x1, x2)  << endl;
}
void workB(int a, int b, int c)
{
    double derta = b * b - 4 * a * c;
    if(sqrt(derta) == int(sqrt(derta))){workA(a, b, c); return ;}
    printf("sqrt(%d)/%d\n", -a*c, a);
}
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, m;
    cin >> T >> m;
    while(T--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int derta = b * b - 4 * a * c;
        if(derta < 0)
        {
            puts("NO");
            continue;
        }
        if(b == 0)
        {
            workB(a, b, c);
            continue;
        }
        int x1 = (-b + sqrt(1.0 * derta)) / (2 * a);
        int x2 = (-b - sqrt(1.0 * derta)) / (2 * a);
        cout << max(x1, x2)  << endl;
    }
    return 0;
}
