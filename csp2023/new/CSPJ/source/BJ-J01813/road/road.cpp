#include<bits/stdc++.h>
using namespace std;
int n,d;
long long cost,oil;
int v[100010],a[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    for(int i = 1; i < n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++){
        a[i] = min(a[i],a[i - 1]);
    }
    for(int i = 1; i < n; i++){
        int nd = (v[i] - oil) / d + 1;
        if((v[i] - oil) % d == 0) nd--;
        cost = cost + nd * a[i];
        oil = oil + nd * d - v[i];
    }
    cout << cost << endl;
    return 0;
}