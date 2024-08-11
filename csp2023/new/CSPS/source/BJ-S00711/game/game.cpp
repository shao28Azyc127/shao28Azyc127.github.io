#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 2e6 + 5;
const int INF = 0x3f3f3f3f;

int n;
string str;
/*
struct Node {
    int cnt;
    char c;
};

vector <Node> nodes;

int prefix[MAXN][30];
*/
bool dp[8001][8001];

int main() {
		ios::sync_with_stdio(false);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> str;
    str = ' ' + str;
    long long ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (str[i + 1] == str[i]) {
            dp[i][i + 1] = true;
            ans++;
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (str[l] == str[r]) {
                dp[l][r] = dp[l + 1][r - 1];
            }
            if (dp[l][r] == true) {
                ans++;
                //cout << "1L: " << l << " R: " << r << endl;
                continue;
            }
            for (int k = l + 1; k <= r - 1; k++) {
                if (dp[l][k] && dp[k + 1][r]) {
                    dp[l][r] = true;
                    //cout << "2L: " << l << " R: " << r << endl;
                    break;
                }
            }
            if (dp[l][r] == true) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 26; j++) {
            prefix[i][j] = prefix[i - 1][j] + ((str[i] - 'a') == j);
        }
    }



    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        while (str[i + 1] == str[i]) {
            cnt++;
            i++;
        }
        nodes.push_back((Node) {cnt, str[i]});
    }

    for (int i = 0; i < nodes.size(); i++) {
        //cout << nodes[i].c << nodes[i].cnt << " ";

    }
    */

    return 0;
}