#include <iostream>
using namespace std;
int n, cnt, ans;
void dfs1(int x){
    if (x == 0) return;
    cnt++;
    if (x % 3 == 0) x -= x / 3;
    else if (x % 3 == 1) x -= (x + 2) / 3;
    else if (x % 3 == 2) x -= (x + 1) / 3;
    dfs1(x);
}
void dfs2(int x){
    if (x == 0) return;
    ans++;
    if (x % 3 == 0) x -= x / 3;
    else if (x % 3 == 1) return;
    else if (x % 3 == 2) x -= (x + 1) / 3;
    dfs2(x);
}
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    dfs1(n);
    dfs2(n);
    cout << cnt << " " << ans;
    return 0;
}