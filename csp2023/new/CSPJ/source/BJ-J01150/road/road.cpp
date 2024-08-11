#include<bits/stdc++.h>
using namespace std;

int v[100001], a[100001], mi[100001];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    mi[0] = 100001;
    int n, d;
    long long cnt = 0, o = 0;
    cin >> n >>d;
    for(int i = 1; i < n; i++)
        cin >>v[i];
    for(int i = 1; i < n; i++)
    {
        cin >>a[i];
        mi[i] = min(mi[i - 1], a[i]);
        if(o >= v[i])
        {
            o -= v[i];
            continue;
        }
        cnt += int((v[i] - o + d - 1) / d) * mi[i];
        o = int((v[i] - o + d - 1) / d) * d - (v[i] - o);
    }
    cin >>a[n];
    cout << cnt << endl;
    return 0;
}