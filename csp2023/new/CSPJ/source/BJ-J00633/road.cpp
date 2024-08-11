#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, d, v[100005], a[100005], sum=0;

    scanf("%d%d", &n, &d);
    for (int i = 1; i < n; i++){
        scanf("%d", &v[i]);
        sum += v[i];
    }
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    int ans = sum/d;
    if(sum % d != 0){
        ans++;
    }
    ans *= a[1];

    printf("%d", ans);

    return 0;
}
/**rp++**/