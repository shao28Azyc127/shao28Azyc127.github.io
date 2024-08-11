#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 15;
const int M = 1e6 + 5;
int n;
int a[N][N];
int cnt[M];
void insert_(int x1, int x2, int x3, int x4, int x5){
    int ans = x1 * 10000 + x2 * 1000 + x3 * 100 + x4 * 10 + x5;
    cnt[ans] ++;
}
void save(int x1, int x2, int x3, int x4, int x5){
    for(int i = 1; i <= 9; i ++){
        insert_(x1, x2, x3, x4, (x5 + i) % 10);
        insert_(x1, x2, x3, (x4 + i) % 10, x5);
        insert_(x1, x2, (x3 + i) % 10, x4, x5);
        insert_(x1, (x2 + i) % 10, x3, x4, x5);
        insert_((x1 + i) % 10, x2, x3, x4, x5);
        insert_((x1 + i) % 10, (x2 + i) % 10, x3, x4, x5);
        insert_(x1, (x2 + i) % 10, (x3 + i) % 10, x4, x5);
        insert_(x1, x2, (x3 + i) % 10, (x4 + i) % 10, x5);
        insert_(x1, x2, x3, (x4 + i) % 10, (x5 + i) % 10);
    }
}
int main()
{
    int ans = 0;
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 5; j ++){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        cout << 81;
        return 0;
    }
    for(int i = 1; i <= n; i ++){
        save(a[i][1], a[i][2], a[i][3], a[i][4], a[i][5]);
    }
    for(int i = 0; i <= 99999; i ++){
        if(cnt[i] == n){
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
