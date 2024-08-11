#include <bits/stdc++.h>
#define ll long long
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;
int n, cnt = 0;
string s;
char c[200005];
int dp[200005];
struct node {
    int n, id;
};
stack<node> st;
vector<char> vt;
int main() {
    freopen("game1t.in", "r", stdin);
    //freopen("game.out", "w", stdout);
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        c[i] = getchar();
        /*if (i == 0) {
            st.push(node{c[i], i});
            dp[0] = dp[1] = 0;
        } else {
            dp[i] = dp[i - 1];
            if (c[i] == st.top()) {
                dp[i]++;
            }
        }*/
        bool flag = true;

        if (i == 0) {
            vt.push_back(c[i]);
        } else {
            if (c[i] == vt[vt.size() - 1]) {
                vt.pop_back();
                vt.push_back(c[i] - 'a' + 'A');
                cnt++;
            } else {
                vt.push_back(c[i]);
            }
        }
    }
    for (int i = 0; i < vt.size(); ++i) {
        printf("%c", vt[i]);
    }
    printf("\n");

    printf("%d", cnt);
    return 0;
}
