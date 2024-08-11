#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

int n;

struct dattype;

struct member {
    string type;
    string name;
    long long pos;
};

struct dattype {
    string name;
    long long request;
    long long size;
    vector<member> mbs;
};
map<string, dattype> tps;

struct var {
    long long address;
    string name;
    dattype type;
};
map<string, var> vars;
long long used_length = 0;

void make_basic_type(string name, int length) {
    dattype ret;
    ret.name = name;
    ret.request = ret.size = length;
    tps[name] = ret;
}

bool in(long long x, long long a, long long b)
  { return a <= x && x <= b; }

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    make_basic_type("byte", 1);
    make_basic_type("short", 2);
    make_basic_type("int", 4);
    make_basic_type("long", 8);

    scanf("%d", &n);
    while (n--) {
        int op;
        scanf("%d", &op);
        switch (op) {
            case 1: {
                string s; cin >> s;
                int k; scanf("%d", &k);
                dattype new_type = {s, 1};
                long long pos = 0;
                while (k--) {
                    string ti, ni;
                    cin >> ti >> ni;
                    assert(tps.count(ti));
                    dattype t = tps[ti];
                    member new_mb = {t.name, ni, 0};
                    new_type.request = max(new_type.request, t.request);
                    assert(t.request != 0);
                    new_mb.pos = (pos + t.request - 1) / t.request * t.request;
                    pos = new_mb.pos + t.size;
                    new_type.mbs.push_back(new_mb);
                }
                new_type.size = (pos + new_type.request - 1) / new_type.request * new_type.request;
                printf("%lld %lld\n", new_type.size, new_type.request);
//                for (int i = 0; i < new_type.mbs.size(); i++)
//                    cout << new_type.mbs[i].name << "(" << new_type.mbs[i].pos << ", +" << tps[new_type.mbs[i].type].size << "); ";
//                cout << endl;
                tps[s] = new_type;
                break;
            };
            case 2: {
                string tt, nt;
                cin >> tt >> nt;
                var new_var = {used_length, nt, tps[tt]};
                vars[nt] = new_var;
                printf("%lld\n", new_var.address);
                used_length += new_var.type.size;
                break;
            };
            case 3: {
                string path;
                cin >> path;
                vector<string> items;
                path += '.';

                string item_now;
                for (int i = 0; i < path.size(); i++)
                    if (path[i] == '.') {
                        items.push_back(item_now);
                        item_now = "";
                    } else
                        item_now += path[i];

                var v = vars[items[0]];
                dattype tp = v.type;
                long long ans = v.address;
                for (int i = 1; i < items.size(); i++) {
                    vector<member> vec = tp.mbs;
                    bool found = false;
                    for (int j = 0; j < vec.size(); j++)
                        if (vec[j].name == items[i]) {
//                            printf("(vec[j].pos = %lld, ans = %lld) ", vec[j].pos, ans);
//                            cout << vec[j].name << ": " << ans + vec[j].pos << " ~ " << ans + vec[j].pos + tps[vec[j].type].size - 1;
//                            printf(" [%lld] ", vec[j].pos);
                            tp = tps[vec[j].type];
//                            printf(" [%lld] ", vec[j].pos);
                            ans += vec[j].pos;
//                            printf(" (vec[j].pos = %lld, ans => %lld)\n", vec[j].pos, ans);
                            found = true;
                            break;
                        }
                    assert(found);
                }
                printf("%lld\n", ans);
                break;
            };
            case 4: {
                long long searching;
                scanf("%lld", &searching);
                var v_now;
                long long address = -1;
                for (map<string, var>::iterator it = vars.begin(); it != vars.end(); it++)
                    if (in(searching, it->second.address, it->second.address + it->second.type.size - 1)) {
                        v_now = it->second;
                        address = it->second.address;
                        break;
                    }
                if (address == -1) {
                    puts("ERR");
//                    puts("failed at finding var");
                    break;
                }

                dattype tp = v_now.type;
                string ans = v_now.name;
                while (true) {
                    long long new_address = -1;
                    for (int i = 0; i < tp.mbs.size(); i++) {
//                        cout << tp.mbs[i].name << ": " << address + tp.mbs[i].pos << " ~ " << address + tp.mbs[i].pos + tps[tp.mbs[i].type].size - 1 << endl;
                        if (in(searching, address + tp.mbs[i].pos, address + tp.mbs[i].pos + tps[tp.mbs[i].type].size - 1)) {
                            new_address = tp.mbs[i].pos;
                            ans += '.' + tp.mbs[i].name;
                            tp = tps[tp.mbs[i].type];
                            break;
                        }
                    }
                    if (new_address == -1) {
                        puts("ERR");
//                        cout << "failed after: " << ans << endl;
                        break;
                    }
                    address += new_address;
                    if (tp.mbs.size() == 0) {
                        cout << ans << endl;
                        break;
                    }
                }
                break;
            };
        }
    }
    return 0;
}
