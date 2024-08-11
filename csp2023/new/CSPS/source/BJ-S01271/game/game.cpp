#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const ll MaxN = 2e6 + 5;
ll n, ans = 0;
string q, k;

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> q;
    for (int i = 0; i < n;i ++){
        for (int j = i; j < n;j ++){
            int g = 0;
            for (int h = i; h <= j; h ++){
                k[g++] = q[h];
            }
            for (int h = 0; h <= g - 1; h ++){
                if (k[h] == k[h + 1]){
                    for (int v = h;v < g - 2;v ++){
                        k[v] = k[v + 2];
                    }
                    g -= 2;
                }
            }
            if (g <= 0)ans ++;
        }
    }
    cout << ans / 2;
    return 0;
}
