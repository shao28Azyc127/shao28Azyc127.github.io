// rui_er is kawaii!!!
#include <bits/stdc++.h>
using namespace std;

#ifndef RUIER
ifstream fin("game.in");
ofstream fout("game.out");
#define cin fin
#define cout fout
#endif

const int N = 2e6 + 5;

template<int mod>
struct Modint {
    unsigned int x;
    Modint() = default;
    Modint(int x) : x(x) {}
    friend istream& operator>>(istream& in, Modint& a) {in >> a.x; return in;}
    friend ostream& operator<<(ostream& out, Modint a) {out << a.x; return out;}
    friend Modint operator+(Modint a, Modint b) {return Modint((a.x + b.x) % mod);}
    friend Modint operator-(Modint a, Modint b) {return Modint((a.x - b.x + mod) % mod);}
    friend Modint operator*(Modint a, Modint b) {return Modint((unsigned long long)1 * a.x * b.x % mod);}
    friend Modint& operator+=(Modint& a, Modint b) {return a = a + b;}
    friend Modint& operator-=(Modint& a, Modint b) {return a = a - b;}
    friend Modint& operator*=(Modint& a, Modint b) {return a = a * b;}
};

const Modint<998244353> base1 = 23333;
const Modint<1004535809> base2 = 1212121;

int n;
string s;
stack<char> stk_chr;
stack<Modint<998244353>> stk_hsh1;
stack<Modint<1004535809>> stk_hsh2;
unordered_map<long long, int> cnt;
long long ans;

inline long long MyHash(Modint<998244353> hsh1, Modint<1004535809> hsh2) {
    return (long long)1 * hsh1.x * 1004535809 + hsh2.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    s = " " + s;
    stk_chr.push(' ');
    stk_hsh1.push(0);
    stk_hsh2.push(0);
    ++cnt[MyHash(stk_hsh1.top(), stk_hsh2.top())];
    for(int i = 1; i <= n; ++i) {
        if(s[i] == stk_chr.top()) {
            stk_chr.pop();
            stk_hsh1.pop();
            stk_hsh2.pop();
        }
        else {
            stk_chr.push(s[i]);
            stk_hsh1.push(stk_hsh1.top() * base1 + s[i]);
            stk_hsh2.push(stk_hsh2.top() * base2 + s[i]);
        }
        ans += cnt[MyHash(stk_hsh1.top(), stk_hsh2.top())];
        ++cnt[MyHash(stk_hsh1.top(), stk_hsh2.top())];
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}