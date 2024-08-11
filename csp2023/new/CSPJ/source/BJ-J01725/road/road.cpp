#include <iostream>
using namespace std;

int n, d, gas = 0, cnt = 0;
int v[100005], a[100005];
bool flag = false;
void cal(int c)
{
    if (c == n) return;
    int y = c, big = 0, newg;
    while (true)
    {
        y++;
        big += v[y - 1];
        if (a[y] < a[c]) break;
        if (y == n)
        {
            if ((big - gas) % d == 0)
            {
                newg = big - gas;
                gas += newg;
            }
            else
            {
                newg = ((big - gas) / d + 1) * d;
                gas += newg;
            }
            cnt += newg / d * a[c];
            cout << cnt;
            flag = true;
            return;
        }
    }
    if ((big - gas) % d == 0)
    {
        newg = big - gas;
        gas += newg;
    }
    else
    {
        newg = ((big - gas) / d + 1) * d;
        gas += newg;
    }
    cnt += newg / d * a[c];
    gas -= big;
    cal(y);
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    cal(1);
    if (flag) return 0;
    cout << cnt;
    return 0;
}
