#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n, d;
long long money;
int gm = 2e9;
int v[100005];
int a[100005];
double gas;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i=1; i<n; i++) cin >> v[i];
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++)
    {
        gm = min(gm, a[i]);
        money += ceil(1.0 * (v[i] - gas * d) / d) * gm;
        gas += ceil(1.0 * (v[i] - gas * d) / d);
        gas -= 1.0 * v[i] / d;
    }
    cout << money << endl;
    return 0;
}