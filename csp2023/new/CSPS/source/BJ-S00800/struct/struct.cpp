#include <bits/stdc++.h>
typedef long long LL;
const int MAXN = 105;
std::map<std::string, std::map<std::string, LL>> size, delta;
std::map<std::string, LL> M, S, L, NAME;
int n, tot;
LL addr[MAXN];
std::string kind[MAXN], name[MAXN], Q;

void divide(const std::string& s, std::string& t1, std::string& t2) {
    t1.clear(), t2.clear();
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '.') {
            for(int j = i + 1; j < s.size(); ++j)
                t2.push_back(s[j]);
            break;
        }
        t1.push_back(s[i]);
    }
}

LL DFS(const std::string& t, const std::string& s) {
    if(s.empty())
        return 0;
    std::string t1, t2;
    divide(s, t1, t2);
    return DFS(t1, t2) + delta[t][t1];
}

void DFS2(const std::string& tp, LL ad) {
    std::map<std::string, LL> T = delta[tp];
    if(T.empty()) {
        if(ad >= S[tp])
            Q = "ERR";
        return ;
    }
    Q += '.';
    std::string ntp;
    LL mx = 0;
    for(auto& p : T)
        if(p.second <= ad && p.second > mx)
            mx = p.second, ntp = p.first;
    Q += ntp;
    DFS2(ntp, ad - mx);
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    L.insert({"byte", 1}), L.insert({"short", 2});
    L.insert({"int", 4}), L.insert({"long", 8});
    S = L;
    std::cin >> n;
    while(n--) {
        int opt;
        std::cin >> opt;
        if(opt == 1) {
            std::string KIND;
            std::cin >> KIND;
            int k;
            std::cin >> k;
            LL lim = 0;
            LL curd = 0, curs = 0;
            for(int i = 1; i <= k; ++i) {
                std::string s, t;
                std::cin >> s >> t;
                LL b = L[s];
                lim = std::max(lim, b);
                curd += curs, curd = (curd + b - 1)/b*b;
                curs = size[KIND][t] = S[s];
                delta[KIND][t] = curd;
            }
            curd += curs, curd = (curd + lim - 1)/lim*lim;
            L.insert({KIND, lim});
            S.insert({KIND, curd});
            std::cout << curd << ' ' << lim << '\n';
        }
        else if(opt == 2) {
            ++tot;
            std::cin >> kind[tot] >> name[tot];
            NAME[name[tot]] = tot;
            LL b = L[kind[tot]];
            if(tot == 1)
                addr[tot] = 0;
            else
                addr[tot] = ((addr[tot - 1] + S[kind[tot - 1]] + b - 1)/b)*b;
            std::cout << addr[tot] << '\n';
        }
        else if(opt == 3) {
            std::string nm;
            std::cin >> nm;
            std::string t1, t2, tp;
            divide(nm, t1, t2);
            tp = kind[NAME[t1]];
            std::cout << addr[NAME[t1]] + DFS(tp, t2) << '\n';
        }
        else {
            LL ad;
            std::cin >> ad;
            LL cur = tot;
            while(cur > 0 && addr[cur] > ad)
                --cur;
            ad -= addr[cur];
            Q = name[cur];
            DFS2(kind[cur], ad);
            std::cout << Q << '\n';
        }
    }
    return 0;
}