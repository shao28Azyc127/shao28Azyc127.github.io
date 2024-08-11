#include <bits/stdc++.h>
using namespace std;
int list1[100][100];
int dfs(int n, int k, int now_at, int now_time){
    if (now_at==n){
        if (now_time/k == 0) return now_time;
        return -1;
    }int minn=-1;
    for (int i=0; i<n; ++i)
        if (list1[now_at][i] != 0){
            int this_;
            if (now_time >= list1[now_at][i]) this_=dfs(n, k, i, now_time+1);
            else this_=dfs(n, k, i, list1[now_at][i]+1);
            if (this_!=-1 && (minn==-1 || this_<minn)) minn=this_;
        }
    return minn;
}int main(){
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i=0; i<m; ++i){
        int u, v, a;
        scanf("%d%d%d", &u, &v, &a);
        list1[u][v]=a;
    }printf("%d", dfs(n, k, 1, 0));
    return 0;
}
