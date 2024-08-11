#include<bits/stdc++.h>
using namespace std;
int n;
char s[2000006];
long long ans;
bool book[2000006];
int mp[2000006];
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n;) {
        char c = getchar();
        if(c >= 'a' && c <= 'z') s[i++] = c;
        mp[i] = i - 1;
    }
    mp[0] = -1;
    //cout<<11111<<endl;
    //int ct = 0;
    while(1) {
        //if(++ct>=3) break;
        bool cg = 1;
        for(int i = n, j = n; i; i = j) {
            //cout<<i<<" "<<j<<endl;
            int cnt = 0;
            while(s[i] == s[j] || mp[j] ^ j - 1) {
                if(s[i] == s[j]) ++cnt;
                j = mp[j];
                //cout<<j<<endl;
            }
            if(s[i] == s[j + 1]) mp[i] = j, cg = 0;
            //else mp[i] = j + 1;
            //cout<<i<<" "<<j<<endl;
            ans += cnt * (cnt - 1) / 2;
        }
        if(cg) break;
    }
    int cnt = 0;
    for(int i = n; i; i = mp[i]) if(mp[i] ^ i - 1) ++cnt; else break;
    ans += cnt * (cnt - 1) / 2;
    printf("%lld", ans);
    return 0;
}