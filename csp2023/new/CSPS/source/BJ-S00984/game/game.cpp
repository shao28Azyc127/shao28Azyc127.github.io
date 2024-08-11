#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#define ll long long
using namespace std;

const int N = 2e6 + 5;
int n;
ll ans, f[N];
string s;
struct Node {
    char c;
    bool use;
    int pos;
};

inline bool check1(int l, int r) {
    char st[N]; int top = 0;
    for (int i = l; i <= r; i++) {
        if (top && s[i] == st[top]) top--;
        else st[++top] = s[i];
    }
    if (!top) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((j - i + 1) % 2 == 0) {
                if (check1(i, j)) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
