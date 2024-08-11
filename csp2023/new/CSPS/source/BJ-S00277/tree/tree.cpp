#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int max_n=1e5;
int n;
LL a[max_n+1];
int b[max_n+1];
int c[max_n+1];
LL height[max_n+1];
int min_day;

inline void Input()
{
    cin>>n;
    for (int i=1; i<=n; ++i) cin>>a[i]>>b[i]>>c[i];
    for (int i=1; i<=n-1; ++i) {int u, v; cin>>u>>v;}
}

inline void Calc_min_day()
{
    int day=0;
    while (true)
    {
        ++day;
        for (int i=1; i<=day; ++i) height[i]+=max(b[i]+day*c[i], 1);
        bool is_accomplished=true;
        for (int i=1; i<=n; ++i) if (height[i]<a[i]) {is_accomplished=false; break;}
        if (is_accomplished) break;
    }
    min_day=day;
}

inline void Output() {cout<<min_day<<endl;}

int main()
{
    ios::sync_with_stdio(false);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    Input();
    Calc_min_day();
    Output();
    return 0;
}