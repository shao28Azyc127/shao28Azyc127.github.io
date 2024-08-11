#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#define int long long int
using namespace std;
int n,d;
int a[100005],v[100005];
int qzh[100005];
int nxt[100005];
int ans,cango;
stack<int> q;
inline int ceill(int x,int y)
{
    return (x/y+(x%y>0?1:0));
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=2;i<=n;i++)
        scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++)
        qzh[i]=qzh[i-1]+v[i];
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    a[n]=-1;
    q.push(n);
    for(int i=n-1;i>=1;i--)
    {
        while(!q.empty() && a[q.top()]>=a[i])
            q.pop();
        nxt[i]=q.top();
        q.push(i);
    }
    nxt[n]=n;
    for(int i=1;i<=n-1;i=nxt[i])
    {
        int dis=qzh[nxt[i]]-qzh[i];
        if(cango>=dis)
        {
            cango-=dis;
            continue;
        }
        int need=ceill((dis-cango),d);
        ans+=need*a[i];
        cango+=need*d;
        cango-=dis;
    }
    cout << ans << endl;
    return 0;
}
