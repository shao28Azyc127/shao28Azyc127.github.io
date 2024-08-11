#include<iostream>
using namespace std;
int n, x;
const int N = 1e5 + 5;
int d[N], p[N];
int find(int pos){
    for(int ret = pos+1; ret <= n; ret ++){
        if(p[ret] < p[pos]) return ret;
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.ans", "w", stdout);
    scanf("%d%d", &n, &x);
    for(int i = 1; i < n; i ++){
        scanf("%d", &d[i]);
        d[i] = d[i-1] + d[i]; //qianzhuihe
    }
    for(int i = 1; i <= n; i ++){
        scanf("%d", &p[i]);
    }
    long long ans = 0;
    ans += p[1] * (d[find(1)] / x);
    int i = find(1);
    while(i <= n){
        ans += p[i] * ((d[find(i)] - d[i]) / x);
        i = find(i);
    }
    cout << ans;
    return 0;

}
