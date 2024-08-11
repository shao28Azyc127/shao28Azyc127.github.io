#include<bits/stdc++.h>
using namespace std;
//map<string, int> typ;
//map<string, int> mon;
/*
string gn;
int sgn = 0;
struct typ_node{
    map<int, int> type_name_to_id;
    a_typ w[205];
    int tot = 0;
    struct a_typ{
        int tot = 0, siz = 0, cd = 0;
        map<int, int> sub_name_id;
        int sub_id_type[205];
        string sub_id_name[205];
        //int
        void add(string s, int k){
          //  vector<string> q1;
            vector<int> q;
            for(int i = 1; i <= k; i++){
                string s;
                string nam;
                cin >> s >> nam;
                int typ = type_name_to_id[s];
                int sub_id = ++tot;
                sub_id_name[sub_id] = nam;
                sub_id_type[sub.id] = typ;
                sub_name_id[nam] = sub_id;
                q.push_back(sub_id);
                cd = max(cd, w[typ].siz);
            }
        }
        int ask_empty(int pos){
            int np = 0;
            for(int i = 0; i < ch.size(); i++){
                int v = ch[i];
                int tp = np + (w[v].siz + cd - 1) / cd;
                if(np * cd + w[v].siz - 1 >= pos){
                    if(pos < np * w[id].cd){
                        return 0;
                    } else {
                        return w[v].ask_empty(pos - np * cd);
                    }
                }
                np = tp;
            }
        }
        int fd(){
            string cnt = read();
            if(cnt )
        }
    };
    int ask_id(string s){
        return reg[s];
    }
    int add_id(string s, int k){
        reg[s] = ++tot;
        int u = tot;
        w[s].add(s, k);
        return tot;
    }
} all_typ;
map<string, int> subname_subid;
int subid_typ[205];
int subid_pos[205];
int tot = 0;*/
int siz[5];
map<string, int> typ_nam_id;
map<string, int> sub_nam_id;
int subid_typid[205];
string subid_nam[205];
int p[205];
int tot = 0;
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int pos = 0;
    typ_nam_id["byte"] = 1;
    typ_nam_id["short"] = 2;
    typ_nam_id["int"] = 4;
    typ_nam_id["long"] = 8;
    for(int i = 1; i <= n; i++){
        int op;
        cin >> op;
        if(op == 2){
            string typ_nam, sub_nam;
            cin >> typ_nam >> sub_nam;
            int typ_id = typ_nam_id[typ_nam];
            int sub_id = ++tot;
            sub_nam_id[sub_nam] = tot;
            int st = (pos + typ_id - 1) / typ_id * typ_id;
            p[sub_id] = st + typ_id - 1;
            subid_typid[sub_id] = typ_id;
            subid_nam[sub_id] = sub_nam;
        } else if(op == 3){
            string a;
            cin >> a;
            int sub_id = sub_nam_id[a];
            cout << p[sub_id] << '\n';
        } else {
            int ask;
            cin >> ask;
            int flag = 1;
            for(int i = 1; i <= tot; i++){
                int st = p[i];
                int ed = p[i] + subid_typid[i];
                if(ed > ask){
                        flag = 0;
                    if(st <= ask){
                        cout << subid_nam[i] << '\n';
                    } else {
                        cout << "ERR" << '\n';
                    }
                    break;
                }
            }
            if(flag) cout << "ERR\n";
        }
        /*
        if(op == 1){
            string s;
            int k;
            cin >> s >> k;
            all_typ.add_id(s, k);
        } else if(op == 2){
            string typ, nam;
            cin >> typ >> nam;
            subname_subid[nam] = ++tot;
            int subid = tot;
            int typid = all_typ.type_name_to_id[typ];
            subid_typ[subid] = typid;
            int cd = all_typ.w[typid].cd;
            int tst = (pos + cd - 1) / cd * cd;
            pos[sub_id] = tst;
        } else if(op == 3){
            cin >> gn;
            sgn = 0;
            string cnt = "";
            for(; sgn < getin.size(); sgn++){
                if(gn[sgn] == '.'){
                    sgn++;
                    break;
                } else {
                    cnt += gn[sgn];
                }
            }
            int typ
            all_typ.
        }*/
    }
    return 0;
}
