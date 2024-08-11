#include<iostream>
#include<cmath>
using namespace std;
const int N=1e4+9;
int v[N], a[N], pre[N];
int n; int d;
const int MAXN=0x3f3f3f;
int dist(int l, int r)
{
    return pre[r-1]-pre[l-1];
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=1; i<n; i++)
    {
        cin >> v[i];
        pre[i]=pre[i-1]+v[i];
    }
    for(int i=1; i<=n; i++) cin >> a[i];
    cout << a[1]*ceil(pre[n]/d) << endl;
    return 0;
}
