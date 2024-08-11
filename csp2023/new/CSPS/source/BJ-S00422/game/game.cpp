#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s, s1;
void sch(int x) {
    bool flag;
    for (int i = 0; i < x - 1; i++) {
        if (s1[i] == s1[i + 1]) {
            s1.erase(i, 2);
            //cout<<"1";
            sch(x - 2);
        }
    }
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            s1 = s.substr(i, j - i + 1);
            //cout<<s1<<" ";
            sch(j - i + 1);
            //cout<<s1<<" "<<"a"<<endl;
            if (s1.empty()) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
