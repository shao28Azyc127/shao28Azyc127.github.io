#include<bits/stdc++.h>
using namespace std;
struct node{
    int num[6];
};
int n, ans;
int ths[10];
node a[100010];
int turnf(int x, int y) {
    if(x<y) return y-x;
    return y+10-x;
}
bool solve() {
    for(int i=1; i<=n; ++i) {
        int dif = 0;
        for(int j=1; j<=5; ++j) {
            if(ths[j]!=a[i].num[j]) {
                if(dif==0) dif = j;
                else if(dif!=j-1) return false;
                else {
                    if(turnf(ths[j], a[i].num[j])!=turnf(ths[dif], a[i].num[dif])) return false;
                }
            }
        }
        if(dif==0) return false;
    }
    return true;
}
void dfs(int x) {
    if(x==6) {
        if(solve()) ++ans;
        return ;
    }
    for(int i=0; i<=9; ++i) {
        ths[x] = i;
        dfs(x+1);
    }
}
int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=5; ++j) cin >> a[i].num[j];
    }
    dfs(1);
    cout << ans;
    return 0;
}
