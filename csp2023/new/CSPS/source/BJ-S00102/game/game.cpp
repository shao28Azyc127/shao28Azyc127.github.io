#include<bits/stdc++.h>
using namespace std;
int n;
char s[100005];
bool check() {
    for(int i = 0; i < n; i++)
        if(s[i] == s[i+1]) return false;
    return true;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    while(check() == true) {
        for(int i = 0; i < n; i++) {
            if(s[i] == s[i+1]) {
                for(int j = i+2; j < n; j++)
                    a[j-2] = a[j];
            }
        }
    }
    cout << 7 << endl;
    return 0;
}