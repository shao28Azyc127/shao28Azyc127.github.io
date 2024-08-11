#include<iostream>
using namespace std;
bool f[8005][8005];
int n, ans;
string s;
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = n - 2; i >= 0; --i)
        for(int j = i + 1; j < n; j += 2){
            if(j == i + 1){
                if(s[i] == s[j]) f[i][j] = 1, ans++;
            } else if(int(s[i] == s[i + 1] && f[i + 2][j]) + int(s[j - 1] == s[j] && f[i][j - 2]) + int(s[i] == s[j] && f[i + 1][j - 1]) > 0) f[i][j] = 1, ans++;
        }
    cout << ans << endl;
    return 0;
}
