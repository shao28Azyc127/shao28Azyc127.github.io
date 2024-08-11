#include <bits/stdc++.h>
using namespace std;

map <string, long long> vars;
map <string, string> types;
map <long long, string> memories;
long long now_max=0;

struct struct_{
    string name;
    map <string, long long> byte_;
    map <string, long long> short_;
    map <string, long long> int_;
    map <string, long long> long_;
    map <string, pair<long long, string>> structs;
    long long now_last;
    long long mx;
};

map <string, struct_> defs;

long long just(long long now, long long k){
    return now-1 + (k - (now-1+k) % k);
}

long long set_addr(string fa, long long addr){
    long long move=0;
    vars[fa] = addr;
    for (auto i:defs[types[fa]].byte_){
        vars[fa+'.'+i.first] = addr+i.second;
        types[fa+'.'+i.first] = "byte";
    }
    for (auto i:defs[types[fa]].short_){
        vars[fa+'.'+i.first] = addr+i.second;
        types[fa+'.'+i.first] = "short";
    }
    for (auto i:defs[types[fa]].int_){
        vars[fa+'.'+i.first] = addr+i.second;
        types[fa+'.'+i.first] = "int";
    }
    for (auto i:defs[types[fa]].long_){
        vars[fa+'.'+i.first] = addr+i.second;
        types[fa+'.'+i.first] = "long";
    }
    for (auto i:defs[types[fa]].structs){
        types[fa+'.'+i.first] = i.second.second;
        move = set_addr(fa+'.'+i.first, addr+i.second.first);
    }
    return vars[fa] + move;
}

int main(){
    long long n;
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--){
        short op;
        cin >> op;
        if (op == 1){
            string s;
            long long k;
            cin >> s >> k;
            struct_ member;
            member.now_last=0;
            member.mx = 0;
            while (k--){
                string type_, name;
                cin >> type_ >> name;
                if (type_ == "byte"){
                    member.byte_[name] = just(member.now_last, 1);
                    member.now_last = just(member.now_last, 1) + 1;
                    member.mx=max(member.mx, 1ll);
                }
                else if (type_ == "short"){
                    member.short_[name] = just(member.now_last, 2);
                    member.now_last = just(member.now_last, 2) + 2;
                    member.mx=max(member.mx, 2ll);
                }
                else if (type_ == "int"){
                    member.int_[name] = just(member.now_last, 4);
                    member.now_last = just(member.now_last, 4) + 4;
                    member.mx=max(member.mx, 4ll);
                }
                else if (type_ == "long"){
                    member.long_[name] = just(member.now_last, 8);
                    member.now_last = just(member.now_last, 8) + 8;
                    member.mx=max(member.mx, 8ll);
                }
                else{
                    member.structs[name] = {just(member.now_last, defs[type_].mx), type_};
                    member.now_last = just(member.now_last, defs[type_].mx) + defs[type_].now_last;
                    member.mx=max(member.mx, defs[type_].mx);
                }
            }
            member.now_last = just(member.now_last, member.mx);
            defs[s] = member;
            cout << member.now_last << " " << member.mx << endl;
        }
        else if (op == 2){
            string t, n;
            cin >> t >> n;
            types[n] = t;
            if (t == "byte"){
                vars[n] = just(now_max, 1);
                now_max = just(now_max, 1) + 1;
            }
            else if (t == "short"){
                vars[n] = just(now_max, 2);
                now_max = just(now_max, 2) + 2;
            }
            else if (t == "int"){
                vars[n] = just(now_max, 4);
                now_max = just(now_max, 4) + 4;
            }
            else if (t == "long"){
                vars[n] = just(now_max, 8);
                now_max = just(now_max, 8) + 8;
            }
            else{
                set_addr(n, just(now_max, defs[t].mx));
                now_max = just(now_max, defs[t].mx) + defs[t].now_last;
            }
            cout << vars[n] << endl;
        }
        else if (op == 3){
            string s;
            cin >> s;
            cout << vars[s] << endl;
        }
        else{
            long long addr;
            cin >> addr;
            string tmp;
            for (auto i:vars){
                long long move=0;
                if (types[i.first] == "byte"){
                    move=1;
                }
                else if (types[i.first] == "short"){
                    move=2;
                }
                else if (types[i.first] == "int"){
                    move=4;
                }
                else if (types[i.first] == "long"){
                    move=8;
                }
                else{
                    continue;
                }
                if (i.second > addr){
                    cout << "ERR" << endl;
                    goto end;
                }
                if (i.second+move > addr){
                    cout << i.first << endl;
                    goto end;
                }
            }
            cout << "ERR" << endl;
        }
        end:;
    }
    return 0;
}