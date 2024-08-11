#include <bits/stdc++.h>
using namespace std;
int n, m, k;
struct zone{
    vector<int> next;
    vector<int> open;
} a[10005];
int f(int pos, int times){
    int r = 100000;
    if(pos == n){
        if(times % k == 0){
            return times;
        }
        else{
            return 100000;
        }
    }
    for(int i = 0;i <= a[pos].next.size()-1;i++){
        if(a[pos].open[i] > times){
            continue;
        }
        r = min(r,f(a[pos].next[i],times+1));
    }
    return r;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    printf("%d%d%d",&n,&m,&k);
    int mmax = 0;
    for(int i = 1;i <= m;i++){
        int x, y, z;
        printf("%d%d%d",&x,&y,&z);
        mmax = max(mmax,z);
        a[x].next.push_back(y);
        a[x].open.push_back(z);
    }
    int ans = 10000;
    for(int i = 0;i <= mmax;i += k){
        ans = min(ans,f(1,i));
    }
    cout << ans;
    return 0;
}
