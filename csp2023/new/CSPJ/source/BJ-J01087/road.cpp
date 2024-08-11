#include <bits/stdc++.h>

using namespace std;

int n , d;
int c[100010] , v[100010] , vis[100010];

int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    cin >> n >> d;
    for (int i = 1 ; i < n ; i ++){
        cin >> v[i];
    }
    for (int i = 1 ; i <= n ; i ++){
        cin >> c[i];
    }
    int sum = 0 , l = 0;
    for (int i = 1 ; i < n ; i ++){
        if (l < v[i]){
            int a = v[i] - l;
            int b = a / d;
            if (a % d != 0) b ++;
            sum += b * c[i];
        }else {
            l -= v[i];
        }
        if (i == n - 1 || c[i] < c[i + 1]){
            int a = v[i] + v[i + 1];
            int b = a / d;
            if (a % d != 0) b ++;
            l += b * d - v[i];
        }
    }

    cout << sum << endl;

    return 0;
}
