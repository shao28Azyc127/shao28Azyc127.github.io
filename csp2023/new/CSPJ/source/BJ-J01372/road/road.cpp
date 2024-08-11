#include<iostream>
#include<cmath>
using namespace std;

const int N = 1000010;
int v[N], a[N], DD;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, sum = 0, sumv = 0;
    cin >> n >> d;
    for(int i = 1; i < n; i++)
    {
        cin >> v[i];
        sumv += v[i];
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
    {
        if(i != 1)
        {
            int z = min(a[i], a[i - 1]);
            sum += (v[i] / d + 1) * z;
        }
        else
            sum += (v[1] / d + 1) * a[1];
    }
    int ss = (sumv / d + 1) * a[1];
    sum = min(sum, ss);
    cout << sum << endl;
    return 0;
}
