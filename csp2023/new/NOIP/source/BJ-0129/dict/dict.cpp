#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int N = 3005;
int n, m;
string s;
int ct[31];
char a[N];
char b[N];
int ok[N];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        for(int j = 0; j < 26; j++) ct[j] = 0;
        for(int j = 0; j < m; j++) ct[s[j] - 'a']++;
        for(int j = 0; j < 26; j++) {
            if(ct[j] != 0) {
                a[i] = 'a' + j;
                break;
            }
        }
        for(int j = 25; j >= 0; j--) {
            if(ct[j] != 0) {
                b[i] = 'a' + j;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        ok[i] = 1;
        for(int j = 1; j <= n; j++) {
            if(j == i) continue;
            if(a[i] >= b[j]) {
                ok[i] = 0;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ok[i];
    }
    cout << endl;
    return 0;
}
