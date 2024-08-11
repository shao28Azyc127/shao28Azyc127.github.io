// 5pts + 5pts = 10pts
#include <iostream>
#include <cstdio>
using namespace std;
int n, m, q;
int x[100005], y[100005];
void n1()
{
    if(x[1] != y[1]) cout << 1;
    else cout << 0;
}
void n2()
{
    if(n == 1) x[2] = x[1];
    if(m == 1) y[2] = y[1];
    if((x[1] - y[1]) * (x[2] - y[2]) > 0) cout << 1;
    else cout << 0;
}
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c;
    cin >> c >> n >> m >> q;
    ios::sync_with_stdio(false);
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= m; i++) cin >> y[i];
    if(c == 1) n1();
    else if(c == 2) n2();
    while(q--)
    {
        int k1, k2;
        cin >> k1 >> k2;
        for(int i = 1; i <= k1; i++)
        {
            int a, b;
            cin >> a >> b;
            x[a] = b;
        }
        for(int i = 1; i <= k2; i++)
        {
            int a, b;
            cin >> a >> b;
            y[a] = b;
        }
        if(c == 1) n1();
        else n2();
    }
}
