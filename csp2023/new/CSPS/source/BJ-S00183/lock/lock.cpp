#include <bits/stdc++.h>
using namespace std;

int n, x[10][8], ans;

int fun(int v[]){
    int u[10];
    vector<int> o;
    for(int i = 1; i <= n; i++){
        o.clear();
        for(int j = 1; j <= 5; j++){
            u[j] = x[i][j] - v[j];
            if(u[j] < 0) u[j] += 10;
        }
        for(int j = 1; j <= 5; j++){
            if(u[j] != 0){
                o.push_back(j);
            }
        }
        if(o.size() != 1 && o.size() != 2) return 0;
        else if(o.size() == 2){
            if(o[1] - o[0] != 1 || u[o[1]] != u[o[0]]) return 0;
        }
    }
    return 1;
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 5; j++)
            cin >> x[i][j];
    for(int a = 0; a < 10; a++)
        for(int b = 0; b < 10; b++)
            for(int c = 0; c < 10; c++)
                for(int d = 0; d < 10; d++)
                    for(int e = 0; e < 10; e++){
                        int k[6] = {0, a, b, c, d, e};
                        ans += fun(k);
                    }
    cout << ans << endl;
    return 0;
}