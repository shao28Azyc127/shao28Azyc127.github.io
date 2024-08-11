#include<bits/stdc++.h>

using namespace std;

int main(){

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, a[100010], v[100010], len, ans, sheng = 0;
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> v[i];
        len += v[i];
    }for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    printf("%d", len / d + 1 * a[1]);

	return 0;
}

