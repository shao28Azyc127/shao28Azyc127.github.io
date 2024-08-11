#include<bits/stdc++.h>
using namespace std;
long long n, d, a[100005], p[100005], w[100005], now = 1, ans, l;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for(int i = 2; i <= n; i++){
        scanf("%lld", &a[i]); a[i] += a[i-1];
    }queue<long long> q;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &w[i]);
        while(!q.empty() && w[q.front()] > w[i]) p[q.front()] = i, q.pop();
        q.push(i);
    }while(!q.empty()) p[q.front()] = n, q.pop();
    while(now < n){
        long long s = a[p[now]] - a[now] - l;
        ans += ((s - 1) / d + 1) * w[now];
        l = ((s - 1) / d + 1) * d - s;
        now = p[now];
    }printf("%lld", ans);
    return 0;
}
