#include<iostream>
#include<string>
using namespace std;
int n;
long long cun_used = 0;
struct a{
    string name;
    string type;
    long long addr_start;
    long long addr_end;
}liang[105];
struct b{
    string name;
    string type;
    long long addr_start;
    long long addr_end;
}st[105];
struct save{
    string name;
    string type[105];
    string type_name[105];
    int type_num;
    int danwei;
    int cun;
}st_type[105];
int num_st = 0;
int num_liang = 0;
int num_st_used = 0;
int type_save(string x){
    if(x == "byte"){
        return 1;
    }else if(x == "short"){
        return 2;
    }else if(x == "int"){
        return 4;
    }else{
        return 8;
    }
}
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int op = 0;
        cin >> op;
        if(op == 1){
            /*~~~~~~~~~~~~~~~~~~~~~~~~~~op1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
            num_st++;
            cin >> st_type[num_st].name;
            cin >> st_type[num_st].type_num;
            for(int j = 1; j <= st_type[num_st].type_num; j++){
                cin >> st_type[num_st].type[j];
                cin >> st_type[num_st].type_name[j];
                int data = type_save(st_type[num_st].type[j]);
                st_type[num_st].danwei = 0;
                if(data > st_type[num_st].danwei){
                    st_type[num_st].danwei = data;
                }
            }
            st_type[num_st].cun = st_type[num_st].danwei * st_type[num_st].type_num;
            cout << st_type[num_st].cun << " " << st_type[num_st].danwei << endl;
        }else if(op == 2){
            /*~~~~~~~~~~~~~~~~~~~~~~~~~~op2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
            string s;
            cin >> s;
            if(s == "byte" || s == "short" || s == "int" || s == "long"){
                num_liang++;
                liang[num_liang].type = s;
                liang[num_liang].addr_start = cun_used;
                cin >> liang[num_liang].name;
                liang[num_liang].addr_end = cun_used + type_save(liang[num_liang].name) - 1;
                cun_used += type_save(liang[num_liang].name);
                cout << liang[num_liang].addr_start << endl;
            }else{
                for(int j = 1; j <= num_st; j++){
                    if(st_type[j].name == s){
                        num_st_used++;
                        cin >> st[num_st_used].name;
                        st[num_st_used].addr_start = cun_used;
                        st[num_st_used].addr_end = cun_used + st_type[j].cun - 1;
                        cun_used += st_type[j].cun;
                        cout << st[num_st_used].addr_start << endl;
                        break;
                    }
                }
            }           
        }else if(op == 3){
            /*~~~~~~~~~~~~~~~~~~~~~~~~~~op3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
            string s;
            cin >> s;
            bool judge = false;//true:struct false:basic
            char mingzi[12] = {'0'};
            int length = 0;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '.'){
                    judge = true;
                    break;
                }
            }
            if(judge){
                //struct
            for(int j = 0; j < s.size(); j++){
                if(s[j] != '.'){
                    length++;
                    
                }
            }
            }else{
                //basic
                for(int j = 1; j <= num_liang; j++){
                    if(s == liang[j].name){
                        cout << liang[j].addr_start << endl;
                        break;
                    }
                }
            }

        }else if(op == 4){
            /*~~~~~~~~~~~~~~~~~~~~~~~~~~op4~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
            long long addr;
            cin >> addr;
            bool flaggg = false;
            for(int j = 1; j <= num_st_used; j++){
                if(st[j].addr_start <= addr && addr <= st[j].addr_end){
                    //cout << st[j].name << endl;
                    //flaggg = true;
                    break;
                }
            }
            if(!flaggg){
                for(int j = 1; j <= num_liang; j++){
                    if(liang[j].addr_start <= addr && addr <= liang[j].addr_end){
                        cout << liang[j].name << endl;
                        flaggg = true;
                        break;
                    }
                }
            }
            if(!flaggg){
                cout << "ERR" << endl;
            }
        }
    }
    return 0;
}