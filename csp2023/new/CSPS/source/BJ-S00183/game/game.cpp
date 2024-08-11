#include <bits/stdc++.h>
using namespace std;

int n, pr[2000010], ne[2000010], le[2000010][30];
long long ans;
string a;

int check(int l, int r){
    for(int i = 0; i < 26; i++)
        if(le[r][i] - le[l - 1][i] & 1)
            return 0;
    string b = a.substr(l - 1, r - l + 1);
    while(b.size() > 1){
        int flag = 1;
        for(int i = 0; i < (int)b.size() - 1; i++){
            if(b[i] == b[i + 1]){
                b.erase(i, 2);
                flag = 0;
            }
        }
        if(flag) break;
    }
    return b.empty();
}

void fun(){
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if(j - i & 1)
                ans += check(i, j);
}

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++){
            le[i][j] = le[i - 1][j];
        }
        le[i][a[i - 1] - 'a']++;
    }
    fun();
    cout << ans << endl;
    return 0;
}
