#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n;
string s[101], tot;

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    while(T--) {
        string a, b;
        int op;
        cin >> op;
        if(op == 2) {
            cin >> a >> s[++tot];
        } 
        if(op == 3) {
            cin >> a;int num = -1
            for(int i = 1; i <= tot; i++){
                if(a == s[i]) {
                    num = i;
                    break;
                }
            }
            cout << (num - 1) * 8 << endl;
        }
        if(op == 4) {
            int num;
            cin >> num;
            num /= 8;
            cout << s[num] << endl;
        }
    }
    return 0;
}
