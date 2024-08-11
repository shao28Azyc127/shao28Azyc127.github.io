#include<iostream>
#define int long long
using namespace std;
int n, d, a, x, sum, qwq;
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i < n; i++)
    {
        cin >> x;
        sum += x;
    }
    cin >> a;
    qwq = sum / d;
    if(qwq * d < sum) qwq++;
    cout << qwq * a << endl;
    return 0;
}
