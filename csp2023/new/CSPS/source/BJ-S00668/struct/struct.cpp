#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
struct var{
    string var_type;
    string var_name;
    int var_saddr;
    int var_eaddr;
} varlist[maxn];

int main (){
    int n;
    int op;
    string st, sn;
    int add_al_start, var_cnt;
    int add_toaccess;
    bool hit;
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >>n;//op num;
    while (n--){
        cin >> op;
        if (op==1){

        }
        if (op==2){
            cin >> st >> sn;
            varlist[var_cnt++].var_type=st;
            varlist[var_cnt].var_name=sn;
            varlist[var_cnt].var_saddr=add_al_start;
            cout << add_al_start<<endl;
            if (st=="byte")
                add_al_start +=1;
            else if (st=="short")
                add_al_start +=2;
            else if (st=="int")
                add_al_start +=4;
            else if (st=="long")
                add_al_start +=8;
            varlist[var_cnt].var_eaddr=add_al_start;
        }
        if (op==3){
            cin >> sn;
            for (int i=0; i< var_cnt; i++){
                if (varlist[i].var_name == sn){
                    cout << varlist[i].var_saddr<<endl;
                }
            }
        }
        if (op==4){
            cin >> add_toaccess;
            for (int i=0; i< var_cnt; i++){
                if (varlist[i].var_saddr <= add_toaccess && varlist[i].var_eaddr >add_toaccess){
                    cout << varlist[i].var_name<<endl;
                    hit = true;
                    break;
                }
            }
            if (!hit) cout << "ERR"<<endl;
        }
    }
    return 0;
}