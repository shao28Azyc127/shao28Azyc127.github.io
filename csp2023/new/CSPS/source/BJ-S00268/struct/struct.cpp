#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<tuple>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long ll;
const ll mod = 1000000021;
struct hs {
    size_t operator()(const string &s) const
    {
        ll ans = 0;
        for(auto x: s) ans = (ans*29+(x-'a'))%mod;
        return ans;
    }
};
struct st {
    ll sz, align;
    vector<int> tp;
    vector<ll> start;
    unordered_map<string,int,hs> num;
    vector<string> names;
} s[115];
unordered_map<string,int,hs> mp;
vector<tuple<ll,int>> mem;
unordered_map<string,int,hs> var;
vector<string> names;
ll ed = 0;
int cnt;
inline ll ali(ll x, ll y)
{
    ll ret = x/y*y;
    if(ret < x) ret += y;
    return ret;
}
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, op, k;
    ll addr;
    cnt = 4;
    s[1].sz = s[1].align = 1; s[2].sz = s[2].align = 2; s[3].sz = s[3].align = 4; s[4].sz = s[4].align = 8;
    mp["byte"] = 1; mp["short"] = 2; mp["int"] = 3; mp["long"] = 4;
    cin >> n;
    while(n--)
    {
        cin >> op;
        if(op == 1)
        {
            string str;
            cin >> str >> k;
            ++cnt;
            mp[str] = cnt;
            ll mx = 0, tot = 0;
            for(int i = 0; i < k; i++)
            {
                string typ, name;
                cin >> typ >> name;
                s[cnt].num[name] = i;
                int tp = mp[typ];
                s[cnt].tp.emplace_back(tp);
                s[cnt].names.emplace_back(name);
                mx = max(mx, s[tp].align);

                ll bg = ali(tot, s[tp].align);
                tot = bg+s[tp].sz;
                s[cnt].start.emplace_back(bg);
            }
            // for(int i = 0; i < k; i++)
            // {
            //     int tp = s[cnt].tp[i];
            //     int ssz = (s[tp].sz/mx+(s[tp].sz%mx?1:0))*mx;
            //     s[cnt].start.emplace_back(tot);
            //     tot += ssz;
            // }
            s[cnt].align = mx;
            s[cnt].sz = ali(tot, mx);
            cout << s[cnt].sz << " " << s[cnt].align << '\n';
        }
        else if(op == 2)
        {
            string typ, name;
            cin >> typ >> name;
            var[name] = mem.size();
            names.emplace_back(name);
            int tp = mp[typ];
            ll al = s[tp].align;
            ll stt = ed/al*al;
            if(stt < ed) stt += al;
            mem.emplace_back(stt, tp);
            ed = stt+s[tp].sz;
            cout << stt << '\n';
        }
        else if(op == 3)
        {
            string ff, name;
            int cur = -1;
            ll bg = -1;
            ll ans = 0;
            cin >> ff;
            auto acc = [&]() {
                if(cur == -1)
                {
                    cur = get<1>(mem[var[name]]); // leixing bianhao
                    bg = get<0>(mem[var[name]]);
                }
                else {
                    st &tp = s[cur];
                    int nxt = tp.num[name]; // i
                    bg = tp.start[nxt];
                    cur = tp.tp[nxt];
                }
                ans += bg;
                name.clear();
            };
            for(int i = 0; i < (int)ff.length(); i++)
            {
                if(ff[i] == '.')
                {
                    acc();
                }
                else name += ff[i];
            }
            acc();
            cout << ans << '\n';
        }
        else if(op == 4)
        {
            cin >> addr;
            if(mem.empty()) { cout << "ERR\n"; continue; }
            int id = upper_bound(mem.begin(), mem.end(), make_tuple(addr, 0), [&](tuple<ll,int> a, tuple<ll,int> b){return get<0>(a)<get<0>(b);})-mem.begin()-1;
            int cur = get<1>(mem[id]);ll bg = get<0>(mem[id]); // leixing bianhao, qishi weizhi
            if(bg+s[cur].sz-1 < addr) { cout << "ERR\n"; continue; }
            vector<string> res;
            res.emplace_back(names[id]);
            addr -= bg;
            while(cur > 4)
            {
                id = upper_bound(s[cur].start.begin(), s[cur].start.end(), addr)-s[cur].start.begin()-1; // i
                bg = s[cur].start[id];
                res.emplace_back(s[cur].names[id]);
                cur = s[cur].tp[id];
                if(bg+s[cur].sz-1 < addr) { cout << "ERR\n"; goto nxt; }
                addr -= bg;
            }
            for(int i = 0; i < (int)res.size(); i++)
            {
                if(i) cout << '.';
                cout << res[i];
            }
            cout << '\n';
            nxt:;
        }
    }
    return 0;
}