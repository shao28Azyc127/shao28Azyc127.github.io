#include <iostream>
#include <string>
using namespace std;

string s;
bool flag[8005][8005];
int n;
int cnt = 0;

void print(int l, int r) {
    cout << "found at " << l << " " << r << endl;
    for(int i = l; i <= r; i++) {
        cout << s[i];
    }
    cout << endl;
}

void printflag() {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(flag[i][j] == true) {
                cout << "flagged " << i << " " << j << endl;
            }
            else {
                //cout << "unflagged" << i << " " << j << endl;
            }
        }
    }
}

bool covered(int l, int r) {
    for(int i = l + 1; i < r; i += 2) {
        if(flag[l][i] && flag[i + 1][r]) {
            return true;
        } 
    }
    return false;
}

void check(int len) {
    for(int i = 0; i <= n - len; i++) {
        //cout << endl;
        //printflag();
        if(len == 2 && s[i] == s[i + 1]) {
            cnt ++;
            flag[i][i + 1] = true;
            //print(i, i + 1);
            continue;
        }
        if(covered(i, i + len - 1)) {
            cnt ++;
            flag[i][i + len - 1] = true;
            //cout << "by cover, ";
            //print(i, i + len - 1);
            continue;
        }
        if(s[i] == s[i + len - 1] && flag[i + 1][i + len - 2]) {
            cnt ++;
            flag[i][i + len - 1] = true;
            //cout << "by expand, ";
            //print(i, i + len - 1);
            continue;
        }
    }
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> s;
    for(int l = 2; l <= n; l += 2) {
        check(l);
    }
    cout << cnt << endl;
}