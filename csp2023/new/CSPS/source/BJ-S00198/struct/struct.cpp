#include <stdio.h>
#include <assert.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int n;
ll mem_base;
char BUF[4096];

struct Member{
    string type;
    string name;
    ll addr;
    Member(){}
};

struct Struct{
    vector<Member> members;
    ll duiqi;
    ll sz;
    Struct(){}
    Struct(ll duiqi,ll sz):duiqi(duiqi),sz(sz){}
    inline void add(const Member &m){
        members.push_back(m);
    }
};

const Struct BYTE(1,1);
const Struct SHORT(2,2);
const Struct INT(4,4);
const Struct LONG(8,8);
Struct Global;

map<string,Struct> sts;

inline string gs(){
    scanf("%s",BUF);
    return BUF;
}

vector<string> split(const string &s){
    vector<int> idxs;
    for (int i = 0;i < (int)s.size();i ++)
        if (s[i] == '.')
            idxs.push_back(i);
    vector<string> ret;
    int prev = 0;
    for (auto it : idxs){
        ret.push_back(s.substr(prev,it - prev));
        prev = it + 1;
    }
    ret.push_back(s.substr(prev));
    return ret;
}

inline ll duiqi(ll x,ll d){
    return ((x + d - 1) / d) * d;
}

inline bool isSimple(Struct s){
    return s.members.size() == 0;
}

int main(){
    #ifndef kevin
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    #endif
    sts["byte"] = BYTE;
    sts["short"] = SHORT;
    sts["int"] = INT;
    sts["long"] = LONG;
    scanf("%d",&n);
    while (n --){
        int op;
        scanf("%d",&op);
        if (op == 1){
            string name = gs();
            int k;
            scanf("%d",&k);
            Struct &st = sts[name];
            ll max_duiqi = 0;
            ll base_addr = 0;
            while (k --){
                string key,value;
                key = gs();
                value = gs();
                Member tmp;
                tmp.type = key;
                tmp.name = value;
                tmp.addr = duiqi(base_addr,sts[tmp.type].duiqi);
                base_addr = tmp.addr + sts[tmp.type].sz;
                st.add(tmp);
                max_duiqi = max(max_duiqi,sts[key].duiqi);                
            }
            st.duiqi = max_duiqi;
            ll sz = duiqi(base_addr,max_duiqi);
            st.sz = sz;
            printf("%lld %lld\n",sz,max_duiqi);
            // printf("MEMBERS OF %s:\n",name.c_str());
            for (auto it : st.members)
                it.addr = it.addr;
        }
        if (op == 2){
            string type = gs(),name = gs();
            Member tmp;
            tmp.type = type;
            tmp.name = name;
            tmp.addr = duiqi(mem_base,sts[type].duiqi);
            mem_base = tmp.addr + sts[type].sz;
            Global.add(tmp);
            printf("%lld\n",tmp.addr);
        }
        if (op == 3){
            string tmp = gs();
            vector<string> spl = split(tmp);
            Struct st = Global;
            ll ans = 0;
            for (auto it : spl){
                // printf("LOOKING FOR member %s\n",it.c_str());
                for (auto mem : st.members){
                    if (mem.name == it){
                        // printf("%s %s ADDR %lld\n",mem.type.c_str(),mem.name.c_str(),mem.addr);
                        ans += mem.addr;
                        st = sts[mem.type];
                        break;
                    }
                }
            }
            printf("%lld\n",ans);
        }
        if (op == 4){
            ll addr;
            scanf("%lld",&addr);
            Struct cur = Global;
            string path;
            while (1){
                for (auto it : cur.members){
                    ll l = it.addr;
                    ll r = it.addr + sts[it.type].sz - 1;
                    if (l <= addr && addr <= r){
                        // printf("ENTERING %s\n",it.name.c_str());
                        path += it.name + '.';
                        addr -= it.addr;
                        // printf("ADDR CHANGING to %lld\n",addr);
                        cur = sts[it.type];
                        if (isSimple(cur)){
                            printf("%s\n",path.substr(0,path.size() - 1).c_str());
                            goto pass;
                        }
                        goto ok;
                    }
                }
                printf("ERR\n");
                break;
                ok:;
            }
            pass:;
        }
    }
    return 0;
}