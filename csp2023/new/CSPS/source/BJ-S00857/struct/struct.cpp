#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 105;
int nxt_aval_type = 4;
int nxt_aval_var = 0;
int nxt_addr = 0;

struct typeinfo {
    string type_name;
    int size;
    int allign;
};
typeinfo type[MAXN];

struct refinfo {
    string ref_name;
    unsigned long long rltv_addr;
    int to;
};

struct varinfo {
    string type;
    string name;
    unsigned long long addr;
};
varinfo var[MAXN];

vector <refinfo> attrof_tree [MAXN];

int find_type(string name) {
    for(int i = 0; i < MAXN; i++) {
        if(type[i].type_name == name) return i;
    }
    cout << "err not found type" << endl;
    return -1;
}

int find_var(string name) {
    for(int i = 0; i < MAXN; i++) {
        if(var[i].name == name) return i;
    }
    cout << "err not found var" << endl;
    return -1;
}

int find_attr(int type_id, string attr_name) {
    for(int i = 0; i < attrof_tree[type_id].size(); i++) {
        if(attrof_tree[type_id][i].ref_name == attr_name) {
            return i;
        }
    }
    cout << "err not found attr" << endl;
    return -1;
}

void define(string name, int attr_len) {
    int id = nxt_aval_type;
    nxt_aval_type ++;

    for(int i = 0; i < attr_len; i++) {
        string attr_name, attr_type;;
        cin >> attr_type >> attr_name;
        refinfo ref;
        ref.to = find_type(attr_type);
        ref.ref_name = attr_name;
        attrof_tree[id].push_back(ref);
    }

    type[id].type_name = name;

    int cur_idx = 0;
    for(int i = 0; i < attrof_tree[id].size(); i++) {
        int attr_id = attrof_tree[id][i].to;

        type[id].allign = max(type[id].allign, type[attr_id].allign);

        if(cur_idx % type[attr_id].allign != 0) {
            cur_idx += type[attr_id].allign - (cur_idx % type[attr_id].allign);
        }
        attrof_tree[id][i].rltv_addr = cur_idx;
        cur_idx += type[attr_id].size;
        
    }

    type[id].size = cur_idx;

    cout << type[id].size << " " << type[id].allign << endl;

    refinfo ref;
    ref.ref_name = "pp";
    ref.rltv_addr = 1e18;
    attrof_tree[id].push_back(ref);
}



void declare(string type_name, string var_name) {
    int var_id = nxt_aval_var;
    int type_id = find_type(type_name);
    nxt_aval_var ++;
    var[var_id].name = var_name;
    var[var_id].type = type_name;
    if(nxt_addr % type[type_id].allign != 0) {
        nxt_addr += type[type_id].allign - (nxt_addr % type[type_id].allign);
    }
    var[var_id].addr = nxt_addr;
    nxt_addr += type[type_id].size;

    cout << var[var_id].addr << endl;
}

void visit(string seq) {
    int last_idx = 0;
    int read_idx = 0;
    char tar_name[11];
    string varlist[100];
    int nxt_aval_varlist = 0;


    while(true) {
        if(seq[read_idx] == '.' || seq[read_idx] == '\0') {
            tar_name[read_idx - last_idx] = '\0';       
            varlist[nxt_aval_varlist] = tar_name;
            nxt_aval_varlist ++;
            if(seq[read_idx] == '\0') break;
            last_idx = read_idx + 1;
            read_idx ++;
        }
        else {
            tar_name[read_idx - last_idx] = seq[read_idx];
            read_idx ++;
        }
    }

    int var_id;
    unsigned long long cur_addr = 0;
    int cur_type_id;
    int cur_attr_id;

    var_id = find_var(varlist[0]);
    cur_addr = var[var_id].addr;
    for(int i = 1; i < nxt_aval_varlist; i++) {
        cur_type_id = find_type(var[var_id].type);
        cur_attr_id = find_attr(cur_type_id, varlist[i]);
        cur_addr += attrof_tree[cur_type_id][cur_attr_id].rltv_addr;
        cur_type_id = attrof_tree[cur_type_id][cur_attr_id].to;
    }
    cout << cur_addr << endl;
} 

void query(unsigned long long addr) {
    string out;
    int type_id;
    for(int i = 0; i < nxt_aval_var; i++) {
        if(var[i].addr <= addr && var[i + 1].addr > addr) {
            out = var[i].name;
            addr -= var[i].addr;
            type_id = find_type(var[i].type);
            for(int i = 0; i < attrof_tree[type_id].size(); i++) {
                if(addr >= attrof_tree[type_id][i].rltv_addr && addr < attrof_tree[type_id][i + 1].rltv_addr) {
                    if(addr >= attrof_tree[type_id][i].rltv_addr + type[attrof_tree[type_id][i].to].size) {
                        cout << "ERR" << endl;
                    }
                    else {
                        out += "." + attrof_tree[type_id][i].ref_name;
                        if(attrof_tree[type_id][i].to <= 3) {
                            cout << out << endl;
                        }
                        else {
                            type_id = attrof_tree[type_id][i].to;
                            addr -= attrof_tree[type_id][i].rltv_addr && addr;
                        }
                    }
                }
            }


            break;
        }
    }
}



int main() {
    freopen("struct1.in", "r", stdin);
    freopen("struct1.out", "w", stdout);
    type[0].type_name = "byte";  type[0].size = 1;   type[0].allign = 1;
    type[1].type_name = "short"; type[1].size = 2;   type[1].allign = 2;
    type[2].type_name = "int";   type[2].size = 4;   type[2].allign = 4;
    type[3].type_name = "long";  type[3].size = 8;   type[3].allign = 8;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            string a;
            int b;
            cin >> a >> b;
            define(a, b);
        }
            
        else if(op == 2){
            string a;
            string b;
            cin >> a >> b;
             declare(a, b);
        }
        else if(op == 3){
            string a;
            cin >> a;
            visit(a);
        }
        else if(op == 4) {
            int a;
            cin >> a;
            query(a);
        }
    }
    
    return 0;
}
