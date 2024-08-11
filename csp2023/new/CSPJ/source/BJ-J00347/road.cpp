#include <bits/stdc++.h>
using namespace std;
int n, d, v[100005],a[100005], sum, cishu, zhia, lu;

void zhi()
{
    zhia = 1;
    lu = 0;
    while (zhia != n)
    {
        if (a[zhia + 1] > a[zhia])
        {
            cishu = (v[zhia] + v[zhia + 1]) / d;
            if ((v[zhia] + v[zhia + 1]) % d != 0)
            {
                cishu += 1;
                lu = d - (v[zhia] + v[zhia + 1]) % d;
            }
            else
                lu = 0;
            sum += cishu * a[zhia];
            zhia += 2;
            v[zhia] -= lu;
        }
        else
        {
            cishu = v[zhia] / d;
            if (v[zhia] % d != 0)
            {
                cishu += 1;
                lu = d - v[zhia] % d;
            }
            else
                lu = 0;
            sum += cishu * a[zhia];
            zhia += 1;
            v[zhia] -= lu;
        }
    }
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i = 1;i < n;i++)
    {
        cin >> v[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    zhi();
    cout << sum;
    return 0;
}













