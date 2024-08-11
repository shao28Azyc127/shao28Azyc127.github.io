#include<iostream>
#include<cmath>
using namespace std;

int v[100005];
int a[100005];
long long dn[100005];
int p[100005];
int q[100005];
long long len[100005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,d; cin >> n >> d;
    for(int i = 1; i <= n-1; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = n-1; i >= 1; i--){
        dn[i] = dn[i+1] + v[i];
    }
    int cnt = 0;
    int r = n;
    while(r > 0){
        cnt++;
        int k;
        int minn = 1e6;
        for(int i = 1; i <= r; i++){
            if(a[i] <= minn){
                minn = a[i];
                k = i;
            }
        }
        p[cnt] = k;
        r = k-1;
    }
    for(int i = 1; i <= cnt; i++){
        q[i] = p[cnt-i+1];
    }
    for(int i = 1; i <= cnt-1; i++){
        len[i] = dn[q[i]]-dn[q[i+1]];
    }
    len[cnt] = dn[q[cnt]]-dn[n];
    long long ans = 0;
    for(int i = 1; i <= cnt; i++){
        long long m = ceil(len[i]*1.0/d);
        ans += m*a[q[i]];
        long long c = m*d-len[i];
        len[i+1]-=c;
    }
    cout << ans << endl;
    return 0;
}
