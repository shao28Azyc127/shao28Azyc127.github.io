#include <bits/stdc++.h>
#define pb push_back
using namespace std;
string stname, typ, name;
int snum, duiq[101], sz[101], tot;
vector<int> saddr[101];// addresses of members of each struct
vector<string> s_addr_name[101];// name of each address
vector<string> memname[101];//member name
vector<int> addr;
vector<string> addr_name;
unordered_map<string, int> na_to_n;
unordered_map<int, string> n_to_na;
unordered_map<string, int> st;//the start address of a member


int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n, op, k;
    scanf("%d", &n);
    while (n--){
        scanf("%d", &op);
        if (op == 1){
            cin >> stname >> k; snum++;
            na_to_n[stname] = snum;
            n_to_na[snum] = stname;
            int dq = 0, nowad = 0;
            for (int i=1; i<=k; i++){
                cin >> typ >> name;
                memname[snum].pb(name);
                if (typ[0] == 'b'){
                    saddr[snum].pb(nowad), s_addr_name[snum].pb(name); nowad++;
                    dq = max(dq, 1);
                }
                else if (typ[0] == 's'){
                    while (nowad % 2) nowad++;
                    for (int i=1; i<=2; i++) saddr[snum].pb(nowad), s_addr_name[snum].pb(name), nowad++;
                    dq = max(dq, 2);
                }
                else if (typ[0] == 'i'){
                    while (nowad % 4) nowad++;
                    for (int i=1; i<=4; i++) saddr[snum].pb(nowad), s_addr_name[snum].pb(name), nowad++;
                    dq = max(dq, 4);
                }
                else{
                    while (nowad % 8) nowad++;
                    for (int i=1; i<=8; i++) saddr[snum].pb(nowad), s_addr_name[snum].pb(name), nowad++;
                    dq = max(dq, 8);
                }
                
            }
            while (nowad % dq) nowad++;
            printf("%d %d\n", nowad, dq);
            duiq[snum] = dq; sz[snum] = nowad;
        }
        if (op == 2){
            cin >> stname >> name;
            if (stname == "byte"){
                printf("%d\n", tot); st[name] = tot;
                addr.pb(tot), tot++;
                addr_name.pb(name);
            }
            else if (stname == "short"){
                while (tot % 2) tot++;
                printf("%d\n", tot); st[name] = tot;
                for (int i=1; i<=2; i++){
                    addr.pb(tot), tot++;
                    addr_name.pb(name);
                }
            }
            else if (stname == "int"){
                while (tot % 4) tot++;
                printf("%d\n", tot); st[name] = tot;
                for (int i=1; i<=4; i++){
                    addr.pb(tot), tot++;
                    addr_name.pb(name);
                }
            }
            else if (stname == "long"){
                while (tot % 8) tot++;
                printf("%d\n", tot); st[name] = tot;
                for (int i=1; i<=8; i++){
                    addr.pb(tot), tot++;
                    addr_name.pb(name);
                }
            }
            else{
                int p = na_to_n[stname];
                while (tot % duiq[p]) tot++;
                printf("%d\n", tot);
                for (int i=0; i<(int)saddr[p].size(); i++){
                    addr.pb(tot + saddr[p][i]);
                    addr_name.pb(name + "." + s_addr_name[p][i]);
                    if (!i || s_addr_name[p][i] != s_addr_name[p][i - 1]) st[name + "." + s_addr_name[p][i]] = tot + saddr[p][i];
                }
                tot += sz[p] - 1;
            }
        }
        if (op == 3){
            cin >> name;
            printf("%d\n", st[name]);
        }
        if (op == 4){
            cin >> k;
            bool flg = 0;
            for (int i=0; i<(int)addr.size(); i++) if (addr[i] == k){
                cout << addr_name[i] << endl;
                flg = 1;
                break;
            }
            if (!flg) printf("ERR\n");
            // if (find(addr.begin(), addr.end(), k) != addr.end()){
            //     int p = *find(addr.begin(), addr.end(), k);
            //     cout << addr_name[p] << endl;
            // }
            // else cout << "ERR\n";
        }
    }
    return 0;
}
