#include<bits/stdc++.h>
using namespace std;
struct xx{
    long long q,k;
}a[100001];
int main(){
    long long n,m,minn = 1e5 + 1,mini,ans = 0,now = 0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++)cin >> a[i].k;
    a[n - 1].k = 0;
    cin >> a[0].q;
    minn = a[0].q;
    for(int i = 1; i < n; i++){
        cin >> a[i].q;
        if(a[i].q < minn){
            minn = a[i].q;
            if(a[mini].k % m != 0)
                    now += (a[mini].k / m + 1) * m - a[mini].k;
            ans += ceil((a[mini].k - now) / m) * a[mini].q;
            mini = i;
        }else a[mini].k += a[i].k;
    }
    if(mini != n - 1)ans += ceil((a[mini].k - now) / m) * a[mini].q;
    cout << ans;
    return 0;
}
