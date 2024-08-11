#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005],b[100005],c[100005];
vector<int> edge[100005];
int fa[100005];
void dfs(int now,int f){
    fa[now] = f;
    for(int i = 0; i < edge[now].size(); i++) if(edge[now][i] != f) dfs(edge[now][i],now);
}
signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i = 1; i <= n; i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    bool lian = 1;
    for(int i = 1; i < n; i++){
        int u,v; scanf("%lld%lld",&u,&v);
        if(v != u + 1) lian = 0;
        edge[u].push_back(v),edge[v].push_back(u);
    }
    dfs(1,0);
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            if(c[i] == 0) ans = max(ans,i + (int)ceil((double)a[i] / (double)b[i]));
            if(c[i] > 0){
                int l = 0,r = 1e9,mid;
                while(l <= r){
                    mid = (l + r) / 2;
                    if(b[i] * (mid - i + 1) + (i + mid) * (mid - i + 1) / 2 * c[i] >= a[i]) r = mid-1;
                    else l = mid+1;
                }
                ans = max(ans,l);

            }
            if(c[i] < 0){
                int l = 0,r = 1e9,mid;
                while(l <= r){
                    mid = (l + r) / 2;
                    if(b[i] + c[i] * mid > 1) l = mid + 1;
                    else r = mid - 1;
                }
                if(l <= i) ans = max(ans,a[i] + i - 1);
                if(b[i] * (r - i + 1) + (r + i) * (r - i + 1) / 2 * c[i] >= a[i]){
                    l = 0,r = 1e9;
                    while(l <= r){
                        mid = (l + r) / 2;
                        if(b[i] * (mid - i + 1) + (i + mid) * (mid - i + 1) / 2 * c[i] >= a[i]) r = mid-1;
                        else l = mid+1;
                    }
                    ans = max(ans,l);
                }else ans = max(ans,a[i] - b[i] * (r - i + 1) - (r + i) * (r - i + 1) / 2 * c[i] + r);
            }
        }
        printf("%lld\n",ans);
    return 0;
}
/*
5
100 8 9
100 9 -2
100 4 -7
100 2 0
100 8 6
1 2
2 3
3 4
4 5
*/
