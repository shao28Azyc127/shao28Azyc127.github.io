#include <iostream>
#include <cmath>
using namespace std;
int D[100010], v[100010];
int t[100010];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    //int sum = 0, ans = 0;
    for(int i = 1; i < n; i ++)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i ++) cin >> D[i];
    int ans = 0;
    double left = 0;
    for(int i = 1; i <= n; i ++)
    {
        double x = (v[i] * 1.0) / (d * 1.0);
        int j;
        //double left = ceil(v[i] * 1.0 / d * 1.0) - x;
        //int x = ceil(v[i] * 1.0 / d * 1.0), j;
        //double left = x - (v[i] * 1.0 / d * 1.0);
        for(j = i + 1; j <= n; j ++)
        {
            if(D[j] >= D[i])
            {
                //if(left > 1.0) x -= v[j] * (x / 1);
                x += ((v[j]) * 1.0 / (d * 1.0));
                //left += ceil((v[j]) * 1.0 / d * 1.0) - ((v[j]) * 1.0 / d * 1.0);
                //left += x - (v[i] * 1.0 / d * 1.0);
            }
            else break;
            //cout << v[j] << endl;
        }
        i = j - 1;
        left = ceil(x) - x;
        ans += (round(x - left) * D[i]);
        left = 0;
        //cout <<x - left << " " << ans << " " << D[i] << endl;
    }
    cout << ans;
    return 0;
}