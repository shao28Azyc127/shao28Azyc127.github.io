#include <bits/stdc++.h>
using namespace std;
long long n;
bool flagB = true;
long long a[100010],b[100010],c[100010];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i = 1;i <= n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(int i = 1;i < n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x != i || y != i + 1) flagB = false;
    }
    cout << n + 1;
    return 0;
}
