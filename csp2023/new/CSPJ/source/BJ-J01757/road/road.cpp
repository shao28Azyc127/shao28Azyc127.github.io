#include<iostream>
using namespace std;

int n, d, ans, oil, mile, minn = 1e9;
int v[100005], a[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        mile += v[i - 1];
        if(minn > a[i] || i == n)
        {
            int x = (mile - oil) / d;
            if((mile - oil) % d != 0) x++;
            oil = x * d - (mile - oil);
            ans += x * minn;
            mile = 0;
            minn = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}
