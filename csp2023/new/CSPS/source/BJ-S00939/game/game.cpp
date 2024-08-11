#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

string str;
const int M = 1000100;

namespace solution1 {

    int p[M];

    void mlc(const string& str) {
        string s = "$";
        for (int i = 0; i < str.length(); ++i) {
            s += str[i];
            s += '$';
        }
        int n = s.length();
        int right = -1;
        int center = -1;
        for (int i = 0; i < n; ++i) {
            p[i] = 1;
            if (right > i) {
                p[i] = min(right - i, p[2 * center - i]);
            }
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) {
                ++p[i];
            }
            if (i + p[i] > right) {
                right = i + p[i];
                center = i;
            }
        }
        long long ans = 0;
        for (int i = 0; i < s.size(); i += 2) {
            ans += p[i]  / 2;
        }
        cout << ans << endl;
    }
}
bool ok[M];
namespace solution2 {
    int children[M][26];
    int suffix[M];
    int lengths[M];
    int node_count = 2;
    long long ans[M][2];
    int getSuffixCanExpand(int node, int next) {
        while (next - lengths[node] - 1 < 0 || str[next - lengths[node] - 1] != str[next])
            node = suffix[node];
        return node;
    }
    int nodes[M];
    void build() {
        suffix[0] = 1;
        lengths[1] = -1;
        int last = 0;
        long long answer = 0;
        for (int char_pos = 0; char_pos < str.length(); ++char_pos) {
            int c = str[char_pos] - 'a';
            int parent = getSuffixCanExpand(last, char_pos);
            if (children[parent][c] == 0) {
                int node = node_count++;
                suffix[node] = children[getSuffixCanExpand(suffix[parent], char_pos)][c];
                lengths[node] = lengths[parent] + 2;
                children[parent][c] = node;
            }

            last = children[parent][c];
            nodes[char_pos] = last;
            /*int node = last;
            int suffix_node = suffix[node];
            int delta = lengths[node] - lengths[suffix_node];
            if (suffix_node > 1 && char_pos - delta >= 0) {
                ans[char_pos][0] += ans[char_pos - delta][delta % 2];
                ans[char_pos][1] += ans[char_pos - delta][(delta + 1) % 2];
            }
            if (char_pos >= 1) {
                ans[char_pos][1] += ans[char_pos - 1][0] + 1;
            } else {
                ans[char_pos][1] += 1;
            }
            // cout << char_pos << " : " << ans[char_pos][0] << " " << ans[char_pos][1] << endl;
            answer += ans[char_pos][0];*/
        }
        long long ans = 0;
        for (int i = 0; i < str.length(); ++i) {
            memset(ok, 0, sizeof(bool) * (i + 10));
            bool* temp = ok + 1;
            int node = nodes[i];
            temp[i] = true;
            for (int j = i; j >= 0; --j) {
                if (temp[j]) {
                    if (i != j) ans ++;
                    for (int node = nodes[j]; node > 1; node = suffix[node]) {
                            if (lengths[node] % 2 == 0) {
                                temp[j - lengths[node]] = true;
                            }
                    }
                }
            }
            if (temp[-1]) ++ans;

        }
        cout << ans << endl;
    }

}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> str;
    solution2::build();
    return 0;
}
