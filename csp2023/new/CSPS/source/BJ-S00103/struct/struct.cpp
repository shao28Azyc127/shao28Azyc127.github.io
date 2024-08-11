// CPU: Intel(R) Core(TM) i5-7500 CPU @ 3.40GHz # too slow...
// Memory: 8GB
#include <bits/stdc++.h>

#define getchar getchar_unlocked
#define putchar putchar_unlocked

using namespace std;

template<typename T = int>
T read() {
    T x = 0, f = 1;
    char ch = 0;
    while (!isdigit(ch)) {
        ch = getchar();
        if (ch == '-') f = -1;
    }
    do {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    while (isdigit(ch));
    return x * f;
}

struct Struct;

struct Object{
    string name;
    Struct* typ;
    int64_t delta;
    Object() {}
    Object(string name, Struct* typ)
        : name(name), typ(typ) {}
};

map<string, Struct> d;

struct Struct{
    int pac;
    int64_t siz;
    bool basic;
    vector<Object> obj;
    Struct() {}
    Struct(int pac, bool basic = false, vector<Object> obj = {})
        : pac(pac), basic(basic), obj(obj) {
        if (basic) siz = pac;
    }
    //                        Type    Name
    Struct(const vector<pair<string, string> >& t) {
        basic = false, pac = 1, siz = 0;
        for (const auto& x : t) {
            obj.emplace_back(x.second, &d[x.first]);
            if (siz % obj.back().typ->pac) siz += obj.back().typ->pac - siz % obj.back().typ->pac;
            obj.back().delta = siz;
            siz += obj.back().typ->siz;
            pac = max(pac, obj.back().typ->pac);
        }
        if (siz % pac) siz += pac - siz % pac;
    }
};

vector<Object> obj;
vector<pair<string, string> > tmp;
int n;

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    d["byte"] = Struct(1, true);
    d["short"] = Struct(2, true);
    d["int"] = Struct(4, true);
    d["long"] = Struct(8, true);
    n = read();
    while(n--) {
        int op = read();
        if (op == 1) {
            string name;
            cin >> name;
            int k = read();
            tmp.clear();
            for (int i = 1; i <= k; i++) {
                string typ, name;
                cin >> typ >> name;
                tmp.emplace_back(typ, name);
            }
            d[name] = Struct(tmp);
            printf("%ld %d\n", d[name].siz, d[name].pac);
        }
        else if (op == 2) {
            string typ, name;
            cin >> typ >> name;
            int64_t addr = obj.empty() ? 0 : obj.back().delta + obj.back().typ->siz;
            if (addr % d[typ].pac) addr += d[typ].pac - addr % d[typ].pac;
            obj.emplace_back(name, &d[typ]);
            obj.back().delta = addr;
            printf("%ld\n", addr);
        }
        else if (op == 3) {
            string s;
            cin >> s;
            s.push_back('.');
            int last = 0;
            int64_t addr = 0;
            Struct* cur = nullptr;
            for (size_t i = 0; i < s.length(); i++) {
                if (s[i] == '.') {
                    string name = s.substr(last, i - last);
                    vector<Object>* to = &obj;
                    if (last != 0) to = &(cur->obj);
                    for (auto& o : *to) {
                        if (o.name == name) {
                            addr += o.delta;
                            cur = o.typ;
                            break;
                        }
                    }
                    last = i + 1;
                }
            }
            printf("%ld\n", addr);
        }
        else {
            int64_t target = read<int64_t>(), addr = 0;
            Struct* cur = nullptr;
            bool fg = true;
            string ans;
            for (auto& o : obj) {
                cur = o.typ;
                if (o.delta + o.typ->siz > target) {
                    addr = o.delta;
                    ans += o.name + ".";
                    fg = false;
                    break;
                }
            }
            if (fg) {
                puts("ERR");
                continue;
            }
            while(!cur->basic) {
                // cout << ans << " " << addr << endl;
                // if (addr % cur->pac) addr += cur->pac - addr % cur->pac;
                for (auto& o : cur->obj) {
                    cur = o.typ;
                    if (addr + o.delta + o.typ->siz > target) {
                        addr += o.delta;
                        ans += o.name + ".";
                        break;
                    }
                }
            }
            // cout << ans << " " << addr << endl;
            if (addr + cur->siz > target && addr <= target) {
                ans.pop_back();
                printf("%s\n", ans.c_str());
            }
            else puts("ERR");
        }
    }
    fflush(stdout);
    return 0;
}