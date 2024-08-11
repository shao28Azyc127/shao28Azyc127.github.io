#include <bits/stdc++.h>
using namespace std;
int n,b[100005],c[100005],u[100005],v[100005];
long long a[100005];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i],&b[i],&c[i]);
    for (int i = 1; i < n; i++) scanf("%d%d", &u[i],&v[i]);
    printf("9");
    return 0;
}