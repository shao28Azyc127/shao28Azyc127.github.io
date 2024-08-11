#include<bits/stdc++.h>
#include<map>
using namespace std;
#define int long long
const int N = 1e2 + 10;
int t, cntstr, cntmem;
struct Struct {
    int k, tab, size;
    string s, t[N], n[N];
}str[N]; 
map<string, int> lowerstr, lowermem;
struct Memory {
    string t, n;
    int l, r = -1, plc[N];
}mem[N];
int _find(Struct s, string n) {
    for(int i = 1; i <= s.k; i++)
        if(s.n[i] == n) return i;
    return -1;
}
bool operator<(Memory m, int l) {
    return m.l < l;
}
bool base(string s) {
    return s == "tybe" || s == "short" || s == "int" || s == "long";
}
int getplc(string s) {
    int i = 0, ans, tmp;
    string now, n = "";
    Struct type;
    for(; s[i] != '.' && i < s.length(); i++) n += s[i];
    i++;
    now = n, ans = mem[lowermem[n]].l;
    n = "";
    for(; s[i] != '.' && i < s.length(); i++) n += s[i];
    i++;
    type = str[lowerstr[mem[lowermem[now]].t]];
    tmp = _find(type, n);
    ans += type.tab * (tmp - 1);
    now = n;
    while(i < s.length()) {
        string n = "";
        for(; s[i] != '.' && i < s.length(); i++) n += s[i];
        i++;
        type = str[lowerstr[type.t[tmp]]];
        tmp = _find(type, n);
        ans += type.tab * (tmp - 1);
        now = n;
    }
    return ans;
}
signed main() {
    freopen("struct.in", "r", stdin);
    freopen("sturct.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    str[++cntstr] = (Struct){0, 1, 1, "byte"};
    lowerstr["byte"] = cntstr;
    str[++cntstr] = (Struct){0, 2, 2, "short"};
    lowerstr["short"] = cntstr;
    str[++cntstr] = (Struct){0, 4, 4, "int"};
    lowerstr["int"] = cntstr;
    str[++cntstr] = (Struct){0, 8, 8, "long"};
    lowerstr["long"] = cntstr;
    cin>>t;
    while(t--) {
        int op;
        cin>>op;
        if(op == 1) {
            cntstr++;
            cin>>str[cntstr].s>>str[cntstr].k;
            lowerstr[str[cntstr].s] = cntstr;
            for(int i = 1; i <= str[cntstr].k; i++) {
                cin>>str[cntstr].t[i]>>str[cntstr].n[i];
                str[cntstr].tab = max(str[cntstr].tab, str[lowerstr[str[cntstr].t[i]]].size);
            }
            str[cntstr].size = str[cntstr].tab * str[cntstr].k;
            cout<<str[cntstr].size<<" "<<str[cntstr].tab<<endl;
        } else if(op == 2) {
            cntmem++;
            cin>>mem[cntmem].t>>mem[cntmem].n;
            lowermem[mem[cntmem].n] = cntmem;
            mem[cntmem].l = mem[cntmem - 1].r + 1;
            mem[cntmem].r = mem[cntmem].l + str[lowerstr[mem[cntmem].t]].size - 1;
            auto type = str[lowerstr[mem[cntmem].t]];
            cout<<mem[cntmem].l<<endl;
        } else if(op == 3) {
            string s;
            cin>>s;
            cout<<getplc(s)<<endl;
        } else {
            int p;
            cin>>p;
            int pp = p, f = p, i = 1;
            string ans = "";
            for(; i <= cntmem; i++) {
                if(mem[i].l > p) break;
                else f -= (mem[i].r - mem[i].l + 1);
            }
            i--;
            p = f + (mem[i].r - mem[i].l + 1);
            ans += mem[i].n;
            auto type = str[lowerstr[mem[i].t]];
            f = p, i = 1;
            int sum = 0;
            for(; i <= type.k; i++) {
                int tmp = str[lowerstr[type.t[i]]].size;
                sum += tmp;
                if(sum > p) break;
                else f -= tmp;
            }
            ans += "." + type.n[i];
            while(1) {
                type = str[lowerstr[type.t[i]]];
                if(base(type.s)) {
                    int plc = getplc(ans);
                    if(pp >= plc && pp < plc + type.size) cout<<ans<<endl;
                    else cout<<"ERR";
                    break;
                }
                f = p, i = 1;
                int sum = 0;
                for(; i <= type.k; i++) {
                    int tmp = str[lowerstr[type.t[i]]].size;
                    sum += tmp;
                    cout<<type.t[i]<<" "<<tmp<<" "<<sum<<" "<<f<<endl;
                    if(sum > p) break;
                    else f -= tmp;
                }
                ans += "." + type.n[i];
            }
        }
    }
    return 0;
}