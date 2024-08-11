#include<iostream>
#include<algorithm>
#include<map>
typedef long long ll;
using namespace std;

struct Data{
    string type;
    ll addr;
    ll size;
    bool operator<(const Data& other) const {
        return addr < other.addr;
    }
};

struct Type{
    int num;
    int sm;
    int size;
    string sname[105];
    int addr[105];
};

bool operator<(const pair<string, Data> a, const pair<string, Data> b){
    return a.second < b.second;
}

ll n, p;
map<string, Data> data;
map<string, Type> type;

ll getSize(string tp){
    if(tp == "byte") return 1;
    if(tp == "short") return 2;
    if(tp == "int") return 4;
    if(tp == "long") return 8;
    return type[tp].size;
    return 0;
}



int main(){

    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    
    cin >> n;
    ll n2 = n;
    while(n2--){
        ll op;
        cin >> op;
        if(op == 1){
            Type tp;
            string name;
            ll op, k;
            cin >> name >> k;
            tp.num = k;
            ll size = 0, ans = 0; //¥Û–°£¨∂‘∆Î
            for(ll i = 1; i <= k; i++){
                string t, n;
                cin >> t >> n;
                tp.sname[i] = n;
                // cout << '\t' << i << ' ' << n << endl;
                ll sz = getSize(t);
                ans = max(ans, sz);
                ll tmp = size / sz * sz;
                tp.addr[i] = (tmp == size) ? size : tmp + sz;
                size = (tmp == size) ? size + sz : tmp + (sz << 1);
            }
            tp.size = size;
            tp.sm = ans;
            type[name] = tp;
            cout << size << ' ' << ans << endl;
        }
        else if(op == 2){
            string t, n;
            cin >> t >> n;
            ll sz = getSize(t);
            ll tmp = p / sz * sz;
            ll addr = (tmp == p) ? p : tmp + sz;
            data[n] = {t, addr, sz};
            cout << addr << endl;
            p = addr + sz;
        }
        else if(op == 3){
            string s;
            Type tp;
            cin >> s;
            int pre = 0, ans = 0;
            bool flag = true;
            for(int i = 0; s[i] != '\0'; i++){
                if(s[i] == '.'){
                    if(flag){
                        tp = type[s.substr(0, i - 1)];
                        ans = data[s.substr(0, i - 1)].addr;
                        flag = 0;
                    }
                    else{
                        // cout << "!";
                        string nm = s.substr(pre, i - pre);
                        // cout << nm << endl;
                        for(int i = 1; i <= tp.num; i++){
                            if(tp.sname[i] == nm){
                                //TODO
                                //cout << tp.addr[i] << endl;
                                ans += tp.addr[i];
                                break;
                            }
                        }
                        tp = type[nm];
                    }
                    pre = i + 1;
                }
            }
            if(flag){
                cout << data[s].addr << endl;
                continue;
            }
            string nm = s.substr(pre, s.size() - pre);
            for(int i = 1; i <= tp.num; i++){
                if(tp.sname[i] == nm){
                    //TODO
                    ans += tp.addr[i];
                    break;
                }
            }
            cout << ans << endl;
        }
        else if(op == 4){
            ll ad;
            cin >> ad;
            if(ad >= p){
                cout << "ERR\n";
                continue;
            }
            map<string, Data>::iterator it = upper_bound(data.begin(), data.end(), pair<string, Data>("", {"", ad, 0}));
            it--;
            Data tmp = it->second;
            if(tmp.addr + tmp.size <= ad){
                cout << "ERR\n";
                continue;
            }
            cout << tmp.addr << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}