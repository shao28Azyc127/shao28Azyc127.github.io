#include <iostream>
using namespace std;

#define grossthing abl[a[1]][a[2]][a[3]][a[4]][a[5]]
#define grossfor(x) for(a[x] = 0; a[x] < 10; a[x]++)

int n, ans;
int a[7];
int abl[11][11][11][11][11];

void iniiiiiiit(int cur) {
    if(cur == 6) {
        grossthing = 0;
        return;
    }
    for(int i = 0; i < 10; i++) {
        a[cur] = i;
        iniiiiiiit(cur + 1);
    }
}

void turrrrrrrn(int x, int y, int num) {
    (a[x] += 1) %= 10;
    if(y != 0) (a[y] += 1) %= 10;
    grossthing++;
    if(num > 1) turrrrrrrn(x, y, num - 1);
}

int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
    iniiiiiiit(1);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++)
            cin >> a[j];
        for(int j = 1; j <= 5; j++)
            turrrrrrrn(j, 0, 10);
        for(int j = 1; j < 5; j++)
            turrrrrrrn(j, j + 1, 10);
    }
    grossfor(1) grossfor(2) grossfor(3) grossfor(4) grossfor(5) if(grossthing == n) ans++;
    cout << ans;
    return 0;
}
