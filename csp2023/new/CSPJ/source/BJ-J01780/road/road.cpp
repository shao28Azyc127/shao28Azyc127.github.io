#include <iostream>
using namespace std;
const int MAXN = 100005;

struct tStation{
    int order;
    int price;
    int dis;
}r[MAXN];
int n, d, minium = 1e7;
int dp[MAXN];

int fuel(int k, int l){
    int cnt = 0, ful = 0;
    for (int i = l; i > k; i--){
        cnt+=r[i].dis;
    }
    while(ful * d < cnt){
        ful++;
    }
    return ful * r[k].price;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i <= n-1; i++){
        cin >> r[i].dis;
    }
    r[n].dis = 0;
    for (int i = 1; i <= n; i++){
        cin >> r[i].price;
    }
    for (int i = 1; i <= n; i++){
        r[i].order = i;
    }
    minium = n-1;
    for (int i = n-2; i >= 1; i--){
        if(r[i].price <= minium){
            minium = i;
        }
        dp[i] = min(fuel(i, n), fuel(minium, n) + fuel(i, minium));
    }
    cout << dp[1];
    return 0;
}
