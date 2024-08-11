#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string, int> id;
map<string, int> name;
int len[4] = {1, 2, 4, 8};
struct Node{
    int type;
    string name;
    int s, f;
}a[105];
bool flag[1005];
int R = -1, l = 0;
void addStr(){

}
void addNode(){
    l++;
    string s;
    cin >> s;
    a[l].type = name[s];
    cin >> a[l].name;
    id[a[l].name] = l;
    if (R == -1) a[l].s = 0;
    else a[l].s = (R / len[a[l].type] + 1) * len[a[l].type];
    R = a[l].f = a[l].s + len[a[l].type] - 1;
    for (int i = a[l].s; i <= a[l].f; i++)
        flag[i] = true;
}
signed main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    name["byte"] = 0;
    name["short"] = 1;
    name["int"] = 2;
    name["long"] = 3;
    while (n--){ // A D
        int op;
        cin >> op;
        if (op == 1){
            addStr();
        }
        else if (op == 2) addNode();
        else if (op == 3){
            string s;
            cin >> s;
            cout << a[id[s]].s << endl;
        }
        else{
            int addr;
            cin >> addr;
            if (addr > R) puts("ERR");
            else{
                if (flag[addr]){
                    for (int i = 1; i <= l; i++){
                        if (a[i].s <= addr && addr <= a[i].f){
                            cout << a[i].s << endl;
                            break;
                        }
                    }
                }
                else puts("ERR");
            }
        }
    }
    return 0;
}
