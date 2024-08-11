#include <bits/stdc++.h>
using namespace std;
int v_list[100], a_list[100], lst[100];
int money(int n, int d, int now_at, int now_have){
    if (now_at==n-1) return 0;
    if (lst[now_at] != 0) return lst[now_at];
    int minn=-1, sum=0;
    for (int i=now_at+1; i<n; ++i){
        sum+=v_list[i-1];
        int money_=(sum-now_have)/d*a_list[now_at];
        if ((sum-now_have)*a_list[now_at]%d!=0){
            money_+=a_list[now_at];
            now_have+=(sum-now_have)*a_list[now_at]%d;
        }
        money_+=money(n, d, i, now_have);
        if (minn==-1 || money_<minn) minn=money_;
    }lst[now_at]=minn;
    return minn;
}int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, min_n=-1;
    scanf("%d%d", &n, &d);
    for (int i=0; i<n-1; ++i) scanf("%d", &v_list[i]);
    for (int i=0; i<n; ++i) scanf("%d", &a_list[i]);
    printf("%d", money(n, d, 0, 0));
    return 0;
}
