#include <cstdio>
#include <cmath>
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, v, a, sum = 0;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n - 1; i++){
        scanf("%d", &v);
        sum += v;
    }
    scanf("%d", &a);
    printf("%d", (int)ceil((double)sum / d) * a);
    return 0;
}//15
