#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,ans;
double now;
int u[100005],a[100005];
struct node{
    int id,x;
    bool operator < (const node &b) const{
        return b.x<x;
    }
};
priority_queue<node> que;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for(int i=1;i<n;i++){
        cin >> u[i];
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        que.push((node){i,a[i]});
        int t = que.top().x,k = ceil(u[i]*1.0/d-now);
        //cout << t << " " << k << endl;
        now+=k;
        now-=u[i]*1.0/d;
        ans+=t*k;
    }
    cout << ans;
    return 0;
}
