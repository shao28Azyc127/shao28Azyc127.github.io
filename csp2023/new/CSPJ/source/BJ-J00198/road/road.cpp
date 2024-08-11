#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int v[100001], a[100001], cost[100001][2], rem[100001];
int find_next(int idx){
    int cur = a[idx];
    idx++;
    while(a[idx] >= cur) idx++;
    return idx;
}
int sumx(int x, int y){
    int sum = 0;
    for(int i = x; i < y; i++){
        sum += v[i];
    }
    return sum;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%d%d", &n, &d);
    int sum = 0;
    for(int i = 1; i < n; i++){
        scanf("%d", &v[i]);
        sum += v[i];
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int dist = 0;
    for(int i = 1, last = 0; i < n; last = i, i = find_next(i)){
        int to_next = sumx(i, find_next(i));
        int oil_num = ceil(1.0 * (to_next - rem[last]) / d);
        cost[i][0] = oil_num * a[i];
        cost[i][1] = round(ceil(1.0 * (sum - dist - rem[last]) / d)) * a[i];
        rem[i] = oil_num * d - to_next + rem[last];
        dist += to_next;
    }
    int minn = 1e9, k = 1, tot = 0;
    while(cost[k][0]){
        minn = min(minn, tot + cost[k][1]);
        tot += cost[k][0];
        k = find_next(k);
    }
    printf("%d\n", minn);
    return 0;
}