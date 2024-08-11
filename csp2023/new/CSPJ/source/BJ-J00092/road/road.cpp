#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, d, v[N], ans, a[N];
struct node{
    int x;
    bool operator<(const node y)const{
        return x > y.x;
    }
};
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    for(int i = 1;i < n;i++)cin >> v[i];
    for(int i = 1;i <= n;i++)cin >> a[i];
    priority_queue<node>q;
    int now = 0;
    q.push({a[1]});
    for(int i = 2;i <= n;i++){
        int x = q.top().x;
        if(v[i - 1] <= now){
            now -= v[i - 1];
            continue;
        }
        int anow = (int)(ceil((v[i - 1] - now) * 1.0 / d));
        ans += anow * x;
        now = anow * d - (v[i - 1] - now);
        q.push({a[i]});
    }
    cout << ans;
    return 0;
}
