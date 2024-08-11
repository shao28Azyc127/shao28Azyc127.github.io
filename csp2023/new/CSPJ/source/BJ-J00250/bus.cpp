#include <bits/stdc++.h>
using namespace std;
int n,m,k,t = 0,p = 1;
int lst[10010][10010] = {},book[10010][10010] = {};
void dfs(int step){
    if(p == n && step % k == 0){
        cout << step << endl;
        t = 1;
        return ;
    }
    if(t == 1) return ;
    for(int i = 1;i <= n;i++){
        if(lst[p][i] == 1){
            swap(p,i);
            book[p][i] = 1;
            dfs(step + 1);
            book[p][i] = 0;
            swap(i,p);
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    int x,y,t;
    for(int i = 0;i < m;i++){
        cin >> x >> y;
        cin >> t;
        lst[x][y] = 1;
    }
    dfs(0);
    return 0;
}
