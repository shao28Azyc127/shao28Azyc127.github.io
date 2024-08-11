#include <bits/stdc++.h>
using namespace std;

int dis[100005];
int a[100005];
//long long sum[100005];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0);
    int n, d;
    cin >> n >> d;
    for(int i=1;i<n;i++){
        cin >> dis[i];
        //sum[i] = sum[i-1]+dis[i];
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[n] = INT_MIN;
    int minn = a[1];
    //int mini = 1;
    long long ans = 0;
    long long cnt = 0;
    for(int i=2;i<=n;i++){
        cnt += dis[i-1];
        if(minn > a[i]){
            long long res = 1LL * (cnt/d+(cnt%d > 0));
            ans += res * minn;
            minn = a[i];
            cnt = cnt - res*d;
        }
    }
    cout << ans;
    return 0;
}