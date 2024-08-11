#include <cstring>
#include <iostream>
#include <map>
using namespace std;
int n, sum, k[200005];
map<string, int> mp;
string s;
bool check(string j) {
    if(!j.size()) return true;
    int flag = 0;
    string nn = "";
    for(int i = 0; i < j.size(); i++) {
        if(j[i] == j[i + 1]) flag = i + 1, i++;
        else nn += j[i];
    }
    if(!flag) return false;
    return check(nn);
}
void extand(int st1, int st2, int num) {
    int len = 0;
    while(!k[st1 - len] && !k[st2 + len] && s[st1 - len] == s[st2 + len] && st1 - len >= 0 && st2 + len < n) {
        k[st1 - len] = k[st2 + len] = num;
    }
}
int work() {
    int s1 = 0, llen = 1, last = 0, s2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == s[i + 1]) {
            extand(i, i + 1, ++s1);
        }
    }
    for(int i = 0; i < n - 1; i++) {
        if(k[i] != k[i + 1]) last = i + 1;
        if(k[i] && k[i + 1] && k[i] != k[i + 1]) {
            llen++, s2 += i - last + 1;
        } else if(k[i] && !k[i + 1]) {
            s2 += llen * (llen - 1) / 2, llen = 1;
        }
    }
    return s2;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    if(n <= 800) {
        for(int len = 2; len <= n; len += 2) {
            for(int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                string hh = s.substr(i - 1, len);
                if(mp[hh] == 0) {
                    mp[hh] = (check(hh) == true ? 1 : 2), sum += (mp[hh] == 1);
                }
            }
        }
        printf("%d", sum);
    } else {
        cout << work();
    }
    return 0;
}
