#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long  long ll;
ll a[N], b[N], c[N], n, head[N], cnt, x[N], ans;
struct edge{
    int to, nxt;
};
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d", &u, &v);
    }
    for(int i = 1; i <= n; i++){
        x[i] = i-1;
        if(b[i] + i * c[i] < 1) x[i] += a[i];
        else{
            if(c[i] >= 0){
                ll l = i, r = i + a[i] / b[i] + 1;
                while(l < r){
                    ll mid = (l + r) / 2;
                    if(b[i]*(mid-i+1) + c[i]*((mid+i)*(mid-i+1)/2) < a[i]) l = mid + 1;
                    else r = mid;
                    //cout<<l<<" "<<r<<endl;
                }
                x[i] = r;
                //if(i == 2) cout<<r<<endl;
            }
            else{
                ll f;
                if(b[i] % (-c[i]) == 0) f = b[i] / (-c[i]) - 1;
                else f = b[i] / (-c[i]);
                if(b[i]*(f-i+1) + c[i]*((f+i)*(f-i+1)/2) <= a[i]){
                    ll l = i, r = f;
                    while(l < r){
                        ll mid = (l + r) / 2;
                        if(b[i]*(mid-i+1) + c[i]*((mid+i)*(mid-i+1)/2) < a[i]) l = mid + 1;
                        else r = mid;
                        //cout<<l<<" "<<r<<endl;
                    }
                    x[i] = r;
                }
                else{
                    a[i] -= b[i]*(f-i+1) + c[i]*((f+i)*(f-i+1)/2), x[i] += f-i+1;
                    x[i] += a[i];
                }
            }
        }
        ans = max(ans, x[i]);
    }
    printf("%lld", ans);
    return 0;
}
