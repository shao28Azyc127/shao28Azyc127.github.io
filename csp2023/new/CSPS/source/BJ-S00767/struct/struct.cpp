#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0, w = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') w *= -1; ch = getchar();}
    while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * w;
}
struct _Type{
    string name;
    bool isBasic;
    string types[103];
    string names[103];
    int type_cnt;
    int max_addr;//standard addr
    int object_cnt;
}_byte, _short, _int, _long;
struct _Object{
    string name;
    long long begin_addr;
    _Type type;
};
long long current_begin_addr;
vector<_Object> addrs;
map<string, _Object> object_map;
map<string, _Type> father_map;
void deep_quest(long long delta_addr, long long max_addr, _Type t){
    for(int i=0;i<t.type_cnt;i++){
        if(father_map.at(t.types[i]).object_cnt * max_addr < delta_addr){
            delta_addr -= father_map.at(t.types[i]).object_cnt * max_addr;
        }
        else{
            cout<<"."<<t.names[i];
            if(father_map.at(t.types[i]).isBasic) return;
            else deep_quest(delta_addr, max_addr, father_map.at(t.types[i]));
        }
    }
}
void quest(long long addr, int l, int r){
    int mid = (l + r) / 2;
    if(addrs.at(mid).begin_addr <= addr && addrs.at(mid+1).begin_addr > addr){
        cout<<addrs.at(mid).name;
        deep_quest(addr - (addrs.at(mid).begin_addr),
                   addrs.at(mid).type.max_addr,
                    addrs.at(mid).type);
        return;
    }
    if(addrs.at(mid).begin_addr > addr) quest(addr, l, mid);
    if(addrs.at(mid+1).begin_addr <= addr) quest(addr, mid, r);
}
void init(){
    _byte.name = "byte";
    _byte.isBasic = true;
    _byte.max_addr = 1;
    _byte.object_cnt = 1;
    father_map.insert(pair<string, _Type>("byte", _byte));
    //father_map.at("byte")
    _short.name = "short";
    _short.isBasic = true;
    _short.max_addr = 2;
    _short.object_cnt = 1;
    father_map.insert(pair<string, _Type>("short", _short));
    _int.name = "int";
    _int.isBasic = true;
    _int.max_addr = 4;
    _int.object_cnt = 1;
    father_map.insert(pair<string, _Type>("int", _int));
    _long.name = "long";
    _long.isBasic = true;
    _long.max_addr = 8;
    _long.object_cnt = 1;
    father_map.insert(pair<string, _Type>("long", _long));
}
int n;
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    init();
    n = read();
    for(int i=0;i<n;i++){
        int op = read();
        if(op == 1){
            _Type newType;
            newType.isBasic = false;
            newType.max_addr = 0;
            newType.object_cnt = 0;
            cin>>newType.name;
            int included = read();
            newType.type_cnt = included;
            for(int j=0;j<included;j++){
                cin>>newType.types[j]>>newType.names[j];
                newType.max_addr = max(newType.max_addr, father_map.at(newType.types[j]).max_addr);
            }
            for(int j=0;j<included;j++){
                newType.object_cnt += father_map.at(newType.types[j]).object_cnt;
            }
            father_map.insert(pair<string, _Type>(newType.name, newType));
        }
        if(op == 2){
            _Object obj;
            obj.begin_addr = current_begin_addr;
            string t;
            cin>>t;
            obj.type = father_map.at(t);
            cin>>obj.name;
            addrs.push_back(obj);
            object_map.insert(pair<string, _Object>(obj.name, obj));
            current_begin_addr += obj.type.object_cnt * obj.type.max_addr;
        }
        if(op == 3){
            string q;
            cin>>q;
            bool got_object = false;
            long long max_addr = 0;
            _Object obj;
            long long addr = 0;
            string _name = "";
            for(int j=0;j<q.size();j++){
                if(q[j] == '.'){
                    if(!got_object){
                        obj = object_map.at(_name);
                        got_object = true;
                        _name = "";
                        addr = obj.begin_addr;
                        max_addr = obj.type.max_addr;
                        continue;
                    }
                    int found = 0;
                    int obj_cnt = 0;
                    for(int k=0;k<obj.type.type_cnt;k++){
                        if(obj.type.names[k] == _name){
                            found = k;
                            break;
                        }
                        obj_cnt += father_map.at(obj.type.types[k]).object_cnt;
                    }
                    addr += obj_cnt * max_addr;
                    _Object newObj;
                    newObj.type = father_map.at(obj.type.types[found]);
                    _name = "";
                    continue;
                }
                _name += q[j];
            }
            if(!got_object){
                addr = obj.begin_addr;
            }
            else{
                int found = 0;
                int obj_cnt = 0;
                for(int k=0;k<obj.type.type_cnt;k++){
                    if(obj.type.names[k] == _name){
                        found = k;
                    }
                    obj_cnt += father_map.at(obj.type.types[k]).object_cnt;
                }
                addr += obj_cnt * max_addr;
            }
            cout<<addr<<endl;
        }
        if(op == 4){
            long long addr;
            cin>>addr;
            quest(addr, 0, addrs.size() - 1);
            cout<<endl;
        }
    }
    return 0;
}
