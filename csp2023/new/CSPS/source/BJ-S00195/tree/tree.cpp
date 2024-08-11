#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int h[1005];
int a[1005];
int b[1005];
int c[1005];
int val[1005];
vector<int> g[1005];
bool cmp(int a,int b)
{

    return a < b;
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];

    }
    for(int i = 1;i <= n - 1;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);

    }
    for(int i = 1;i <= n;i++)
    {
        b[i] = max(b[i],1);
        val[i] = a[i] / b[i];
        if(a[i] % b[i] != 0) val[i]++;


    }
    sort(val + 1,val + n + 1,cmp);
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        val[i] += n - i;
        ans = max(ans,val[i]);
    }
    cout << ans << endl;
    return 0;
}
