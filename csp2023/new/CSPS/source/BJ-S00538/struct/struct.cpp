#include <bits/stdc++.h>
using namespace std;
long long n, op, k, ma, ans, tmp;
string name, lei, name2;
map<string, long long> zhan, dui;
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 1) {
            ma = -1;
            cin >> name >> k;
            ans = 0;
            tmp = k;
            for (int i = 1; i <= k; i++) {
                cin >> lei >> name2;
                if (lei == "byte") ma = max(ma, 1LL);
                else if (lei == "short") ma = max(ma, 2LL);
                else if (lei == "int") ma = max(ma, 4LL);
                else if (lei == "long") ma = max(ma, 8LL);
                else {
                    ans += zhan[lei];
                    ma = max(ma, dui[lei]);
                    tmp--;
                }
            }
            cout << tmp * ma + ans<< " " << ma << endl;
            zhan[name] = tmp * ma + ans;
            dui[name] = ma;
        }
    }
    return 0;
}
