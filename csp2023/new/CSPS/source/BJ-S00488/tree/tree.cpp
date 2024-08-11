#include <bits/stdc++.h>

using namespace std;
vector<int> v[100010];
int a[100010],b[100010],c[100010];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    int h,g;
    for(int i=1;i<n;i++){
        cin>>h>>g;
        v[h].push_back(g);
        v[g].push_back(h);
    }
    int ma=0,need;
    for(int i=1;i<=n;i++){
        need=(a[i]+b[i]-1)/b[i];
        ma=max(ma,need);
    }
    cout<<ma;
    return 0;
}
