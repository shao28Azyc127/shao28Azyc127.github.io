#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,v[100005],a[100005],cnt,oil;
bool vis[100005];
vector<int> ve;
int buyam(int x){
    if (x % d == 0) return x / d;
    return x / d + 1;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin >> n >> d;
    for (int i = 1;i < n;i++) cin >> v[i];
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i < n;i++){
        if (vis[i]) continue;
        ve.push_back(i);
        int t = buyam(v[i] - oil);
        cnt += a[i] * t;
        oil = t * d - v[i];
        int j = i;
        while (a[j] < a[j + 1]){
            vis[j + 1] = true;
            int tmp = buyam(v[j + 1] - oil);
            cnt += a[i] * tmp;
            oil = tmp * d - v[i];
            j++;
        }
    }
    /*sort(ve.begin(),ve.end(),greater<int>());
    for (int i = 0;i < ve.size();i++){
        cnt -= (oil[ve[i]] * a[ve[i]]);
        for (int j = v[i] + 1;j <= n;j++) oil[j] -= oil[v[i]];
    }*/
    cout << cnt;
    return 0;
}
