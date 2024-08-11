#include<bits/stdc++.h>
using namespace std;
int getsize(string type){
    if(type == "byte") return 1;
    if(type == "short") return 2;
    if(type == "int") return 4;
    if(type == "long") return 8;
    return -1;
}
int n;
struct Struct{
    string type;
    string name;
};
struct Ask{
    int op, k;
    string type, name;
    Struct st[101];
    long long addr;
}a[101];
long long addrnow = 0;
map<string, long long> name_to_addr;
map<long long, string> addr_to_name;
void Solve(){
    for(int i = 1; i <= n; i++){
        if(a[i].op == 2){
            cout << addrnow << endl;
            name_to_addr[a[i].name] = addrnow;
            addr_to_name[addrnow] = a[i].name;
            addrnow += getsize(a[i].type);
        }else if(a[i].op == 3){
            cout << name_to_addr[a[i].name] << endl;
        }else{
            string s = addr_to_name[a[i].addr];
            if(s.length() == 0){
                cout << "ERR" << endl;
            }
            cout << s << endl;
        }
    }
    return;
}
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int one = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].op;
        if(a[i].op == 1){
            cin >> a[i].name >> a[i].k;
            for(int j = 1; j <= a[i].k; j++){
                cin >> a[i].st[j].type >> a[i].st[j].name;
            }
            one++;
        }else if(a[i].op == 2){
            cin >> a[i].type >> a[i].name;
        }else if(a[i].op == 3){
            cin >> a[i].name;
        }else if(a[i].op == 4){
            cin >> a[i].addr;
        }
    }
    if(one == 0){
        Solve();
        return 0;
    }
    return 0;
}