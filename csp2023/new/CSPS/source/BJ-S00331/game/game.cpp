#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;
int n;
string s;
int st[8000001], top = 0;
LL ans = 0;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    s = '.' + s;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(st[top] == s[j]) {
                top--;
                if(top == 0) ans++;
            } else {
                st[++top] = s[j];
            }
        }
        top = 0;
    }
    cout << ans << endl;
    return 0;
}
