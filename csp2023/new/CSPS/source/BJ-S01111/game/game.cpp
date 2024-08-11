#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, cnt, a[N][26];
string s;
bool check(int l, int r){
    if((r - l + 1) % 2) return 0;
    for(int i = 0; i < 26; i++)
        if((a[r][i] - a[l-1][i]) % 2) return 0;
    return 1;
}
bool dfs(string x){
    if(x == "") return 1;
    int l = x.size();
    for(int i = 0; i < l-1; i++)
        if(x[i] == x[i+1]){
            string nw = x.substr(0, i);
            if(i != l-2) nw += x.substr(i+2);
            bool f = dfs(nw);
            if(f) return 1;
        }
    return 0;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin>>n>>s;
    s = " " + s;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++) a[i][j] = a[i-1][j];
        a[i][s[i]-'a']++;
    }
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++){
            if(!check(i, j)) continue;
            cnt += dfs(s.substr(i, j-i+1));
        }
    cout<<cnt;
    return 0;
}
