#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool book[805][805];
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    int ans = 0;
    for(int i=1; i<n; ++i) {
        if(s[i]==s[i-1]) book[i-1][i] = true, ++ans;
    }
    for(int len=4; len<=n; len+=2) {
        for(int i=0; i<n-len+10; ++i) {
            int j = i+len-1;
            if(i>=n || j>=n) continue;
            for(int k=i+1; k<j; k+=2) {
                if(book[i][k] && book[k+1][j]) {
                        book[i][j] = true;
                        break;
                }
            }
            if(s[i]==s[j] && book[i+1][j-1]) book[i][j] = true;
            if(book[i][j]) ++ans;
        }
    }
    cout << ans;
    return 0;
}
