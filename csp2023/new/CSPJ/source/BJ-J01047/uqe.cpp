#include <bits/stdc++.h>
using namespace std;

int m;

int is_int(string s) {
    int len = s.length();
    int ret = 0;
    for (int i = 0; i < len; i ++){
        if (s[i] >= '0' && s[i] <= '9'){
            ret = 10*ret + s[i] - '0';
        } else {
            return -1;
        }
    }
    return ret;
}

int getaa(string s){
    int len = s.length();
    int ret = 0;
    for (int i = 0; i < len; i ++){
        if (s[i] >= '0' && s[i] <= '9'){
            ret = 10*ret + s[i] - '0';
        } else {
            if (ret == 0)
                return 1;
            return ret;
        }
    }
}

string rep(string s, int a){
    string sa = to_string(a);
    int p;
    for (p = 0; p < s.length(); p ++){
        if (s[p] < '0' || s[p] > '9'){
            if (p == 0){
                return s;
            }

            break;
        }
    }
    for (; p < s.length(); p ++){
        sa += s[p];
    }
    return sa;
}

string m_sqrt(int x) {
    int out = 1;
    for (int i = 2; i * i <= x; i ++){
        while (x % (i*i) == 0){
            x /= (i*i);
            out *= i;
        }
    }
    if (x == 0){
        return to_string(0);
    } else if (x == 1){
        return to_string(out);
    } else if (out != 1){
        return (to_string(out) + "*" + "sqrt(" + to_string(x) + ")");
    } else {
        return ("sqrt(" + to_string(x) + ")");
    }
}

string divid(int a, int b, string del){
    int flag = is_int(del);
    string ans;
    if (flag != -1){
        int up = flag - b;
        int down = 2*a;
        for (int i = 2; i <= max(up, down); i ++){
            if (up % i == 0 && down % i == 0){
                up /= i;
                down /= i;
            }
        }
        if (down == 1){
            return to_string(up);
        } else {
            ans = (to_string(up) + "/" + to_string(down));
        }
        if (ans[0] == '0'){
            return "0";
        } else {
            return ans;
        }
    }
    flag = getaa(del);
    //cout << flag << endl;
    int up = -b;
    int down = 2*a;
    if (down == 1){
        if (up == 0){
            return rep(del, flag);
        } else {
            return (to_string(up) + "+" + rep(del, flag));
        }
    } else {
        if (up == 0){
            return (rep(del, flag) + "/" + to_string(down));
        } else {
            return (to_string(up) + "/" + to_string(down) + "+" + rep(del, flag) + "/" + to_string(down));
        }
    }

    //return (to_string(-b) + "/" + to_string(2*a) + "+" + del + "/" + to_string(2*a));
}

int main() {
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);

    int t;
    cin >> t >> m;

    while (t --){
        string ans = "";
        int a, b, c;
        cin >> a >> b >> c;
        if (a < 0){
            a = -a, b = -b, c = -c;
        }
        int delta = b*b - 4*a*c;
        //cout << delta << endl;
        if (delta < 0){
            cout << "NO" << endl;
            continue;
        }

        cout << divid(a,b,m_sqrt(delta));

    }

    return 0;
}
