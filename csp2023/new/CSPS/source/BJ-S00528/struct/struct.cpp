#include<iostream>
#include<map>
#define ll long long
using namespace std;
ll n, op, k, now;
string s, name, add[10005];
map <string, int> mp;
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i <= 10000; ++i) add[i] = ".";
    cin >> n;
    while(n--){
        cin >> op;
        if(op == 3){
            cin >> s;
            cout << mp[s] << endl;
        } else if(op == 4){
            cin >> k;
            if(add[k] == ".") cout << "ERR" << endl;
            else cout << add[k] << endl;
        } else {
            cin >> s >> name;
            if(s == "byte"){
                mp[name] = now;
                add[now] = name;
                now++;
            } else if(s == "short"){
                if(now % 2) now = now / 2 * 2 + 2;
                mp[name] = now;
                add[now] = add[now + 1] = name;
                now += 2;
            } else if(s == "int"){
                if(now % 4) now = now / 4 * 4 + 4;
                mp[name] = now;
                for(int i = now; i <= now + 3; ++i) add[i] = name;
                now += 4;
            } else {
                if(now % 8) now = now / 8 * 8 + 8;
                mp[name] = now;
                for(int i = now; i <= now + 7; ++i) add[i] = name;
                now += 8;
            }
            cout << mp[name] << endl;
        }
    }
    return 0;
}
