# include <cstdio>
# include <iostream>
using namespace std;

bool flag[100000];
int a[6];

bool chk(int x){
    if (flag[x])
        return true;
    int b[6] = {};
    for (int i = 5; i >= 1; i--){
        b[i] = x % 10;
        x /= 10;
    }
    int cnt = 0;
    int diff = 0;
    for (int i = 1; i <= 5; i++){
        if (a[i] != b[i]){
            if (cnt && ((a[i] - b[i] + 10) % 10 != diff || (a[i - 1] - b[i - 1] + 10) % 10 != diff))
                return true;
            cnt++;
            diff = (a[i] - b[i] + 10) % 10;
        }
    }
    if (!cnt || cnt > 2)
        return true;
    return false;
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    while (n--){
        for (int i = 1; i <= 5; i++)
            cin >> a[i];
        for (int i = 0; i < 100000; i++)
            flag[i] |= chk(i);
    }
    int ans = 0;
    for (int i = 0; i < 100000; i++)
        ans += (!flag[i]);
    cout << ans << endl;
    return 0;
}