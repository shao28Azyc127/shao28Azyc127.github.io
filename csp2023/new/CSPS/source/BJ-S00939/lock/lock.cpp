#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

void expand(string input, unordered_set<string>& s) {
    string original = input;
    for (int i = 0; i < 5; ++i) {
        for (char c = '0'; c <= '9'; ++c) {
            if (input[i] != c) {
                input[i] = c;
                s.insert(input);
                input[i] = original[i];
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j <= 9; ++j) {
            input[i] = (input[i] - '0' + j) % 10 + '0';
            input[i + 1] = (input[i + 1] - '0' + j) % 10 + '0';
            s.insert(input);
            input[i] = original[i];
            input[i + 1] = original[i + 1];
        }
    }
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<string> s[8];
    int n;
    cin >> n;
    vector<string> ks;
    for (int i = 0; i < n; ++i) {
        string k;
        for (int j = 0; j < 5; ++j) {
            int v;
            cin >> v;
            k += '0' + v;
        }
        ks.push_back(k);
        expand(k, s[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i].find(ks[j]) != s[i].end()) {
                s[i].erase(ks[j]);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        unordered_set<string> temp;
        for (const auto& t : s[0]) {
            if (s[i].find(t) != s[i].end()) {
                temp.insert(t);
            }
        }
        s[0] = temp;
    }
    cout << s[0].size() << endl;
    return 0;
}
