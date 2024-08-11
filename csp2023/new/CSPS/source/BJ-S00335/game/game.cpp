#include <iostream>
#include <string>
using namespace std;

string f(string s) {
    if (s == "")
        return "";
    string ret;
    ret += s[0];
    for (int i = 1; i < s.size(); i++)
        if (s[i] != ret.back())
            ret += s[i];
        else
            ret.pop_back();
    return ret;
}

bool g(string s) {
    string a = s, b;
    while (a != b) {
        b = a;
        a = f(a);
    }
    return (a == "");
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);

    string s;
    getline(cin, s); // get the num
    getline(cin, s);
    int cnt = 0;
    for (int l = 0; l < s.size(); l++)
        for (int len = 1; len <= s.size() - l; len++)
            cnt += g(s.substr(l, len));
    printf("%d\n", cnt);
    return 0;
}
