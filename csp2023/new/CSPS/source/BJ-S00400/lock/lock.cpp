#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> r;

bool cha(char a, char b, char c, char d){
    int x = a - '0';
    int y = b - '0', x1 = c - '0', y1 = d - '0';
    for (int i = 0; i < 22; i++){
        if (x == x1 && y == y1) return true;
        x++;
        y++;
        x %= 10;
        y %= 10;
    }
    return false;

}

bool help(string& a, string& b){
    int x = -1, y = -1;
    for (int i = 0; i < 5; i++){
        if (a[i] != b[i] && x == -1) x = i;
        else if (a[i] != b[i]) y = i;
        else if (x != -1 && y != -1 && a[i] != b[i]) return false;
    }

    if (x != -1 && y != -1){
        if (y-x > 1) return false;
        if (!cha(a[x], a[y], b[x], b[y])) return false;
    }

    return true;
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int db;
    cin >> n;

    for (int i = 1; i <= n; i++){
        string s;
        for (int j = 0; j < 5; j++){
            cin >> db;
            s += db + '0';
        }
        r.push_back(s);
    }
    unordered_set<string> usa;
    for (auto x: r){
        usa.insert(x);
    }
    unordered_set<string> ans;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                for (int l = 0; l < 10; l++){
                    for (int v = 0; v < 10; v++){
                        bool flag = true;
                        string o;
                        o += v + '0';
                        o += l + '0';
                        o += k + '0';
                        o += j + '0';
                        o += i + '0';
                        for (int i = 0; i < n; i++)
                            if (!help(o, r[i])) { flag = 0; break; }
                        if (flag && usa.find(o) == usa.end()) {
                                ans.insert(o);
                         }
                    }
                }

    cout << ans.size() << endl;


    return 0;
}
