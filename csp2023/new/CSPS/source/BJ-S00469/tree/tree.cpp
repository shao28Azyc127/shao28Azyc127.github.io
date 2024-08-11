#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n;
vector<int> nei[N];
struct land{
    long long a, b, c;
}a[N];
int main (){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >>n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].a >>a[i].b >> a[i].c;
    }
    for (int i=1;i<n;i++)
    {
        int u, v;
        cin >> u >> v;
        nei[u].push_back(v);
        nei[v].push_back(u);
    }
    cout << n+1 <<endl;
    return 0;
}
