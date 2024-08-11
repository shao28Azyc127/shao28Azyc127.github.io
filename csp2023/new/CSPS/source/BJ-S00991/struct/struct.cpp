#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

#define ll long long
ll CSP_next_address(ll cur_address,int restricts){
    if(cur_address%restricts==0)return cur_address;
    return cur_address + restricts - cur_address % restricts;
}
struct CSP_struct{
    int restricts;
    ll size;
    bool base,null;
    map<string,pair<ll,CSP_struct*>> members;
    vector<string> order;
    CSP_struct(int size){
        this->restricts = size;
        this->size = size;
        this->base = true;
        this->null = false;
    }
    CSP_struct(map<string, CSP_struct*> mp, const vector<string> order){
        //cout<<"building non-builtin struct"<<endl;
        this->restricts = this->size = this->base = 0;
        ll addr=0;
        for(string name:order){
            //cout<<"adding item "<<name<<endl;
            CSP_struct* typ=mp[name];
            //cout<<"aloc address"<<endl;
            addr = CSP_next_address(addr, typ->restricts);
            //cout<<"update restricts"<<endl;
            this->restricts = max(this->restricts, typ->restricts);
            //cout<<"add to members"<<endl;
            members[name]={addr,typ};
            //cout<<"aloc "<<addr<<" for "<<name<<endl;
            //cout<<"using space"<<endl;
            addr += typ->size;
            //this->order.push_back(name);
        }
        //cout<<"restricting & copying size"<<endl;
        addr = CSP_next_address(addr, this->restricts);
        this->size = addr;
        this->null = false;
        this->order=order;
    }
    CSP_struct(){ this->null = true; }
};
map<string, CSP_struct*> CSP_struct_global;
map<string, pair<ll, CSP_struct*>>CSP_var_global;
CSP_struct CSP_INT(4), CSP_LONG(8), CSP_BYTE(1), CSP_SHORT(2);
vector<CSP_struct*> pointers;

void init(){
    // 定义基本类型
    CSP_struct_global["int"] = &CSP_INT;
    CSP_struct_global["long"] = &CSP_LONG;
    CSP_struct_global["byte"] = &CSP_BYTE;
    CSP_struct_global["short"] = &CSP_SHORT;
}
int n,lineno;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    init();
    ll addr=0;
    for(int i=1;i<=n;i++){
        int op; cin>>op;
        lineno++;
        //cerr<<"op#"<<op<<endl;
        if(op==1){ // 定义结构体
            //cerr<<"crt locals"<<endl;
            map<string, CSP_struct*> members;
            //cerr<<"working"<<endl;
            vector<string> order;
            //cerr<<"reading extra"<<endl;
            string name; int k; cin>>name>>k;
            //cerr<<"init succ"<<endl;
            for(int j=1;j<=k;j++){
                string mname,mtyp;
                cin>>mtyp>>mname;
                //cerr<<mtyp<<' '<<mname<<endl;
                members[mname]=CSP_struct_global[mtyp];
                order.push_back(mname);
            }
            //cerr<<k<<' '<<members.size()<<' '<<order.size()<<endl;
            //cerr<<"read succ"<<endl;
            CSP_struct_global[name] = new CSP_struct(members,order);
            pointers.push_back(CSP_struct_global[name]);
           // cerr<<"create succ" <<endl;
            cout<<CSP_struct_global[name]->size<<' '<<CSP_struct_global[name]->restricts<<endl;
        }else if(op==2){ // 定义变量
            string name,typ;
            cin>>typ>>name;
            //cout<<"d"<<CSP_struct_global[typ]->restricts<<endl;
            addr=CSP_next_address(addr, CSP_struct_global[typ]->restricts);
            cout<<addr<<endl;
            CSP_var_global[name] = {addr, CSP_struct_global[typ]};
            addr+=CSP_struct_global[typ]->size;
            //cout<<addr<<endl;
        }else if(op==3){ // 路径查询
            string path,tmp; cin>>path;
            ll addr;
            CSP_struct* cur_struct=nullptr;
            for(int i=0;i<path.size();i++){
                if(path[i]=='.'){
                    if(cur_struct==nullptr)cur_struct = CSP_var_global[tmp].second, addr = CSP_var_global[tmp].first;
                    else addr += cur_struct->members[tmp].first, cur_struct = cur_struct->members[tmp].second;
                    tmp = "";
                }else tmp+=path[i];
            }
            if(cur_struct==nullptr)addr = CSP_var_global[tmp].first;
            else addr += cur_struct->members[tmp].first;
            cout<<addr<<endl;
        }else if(op==4){ // 地址查询
            //cout<<"succ"<<endl;
            ll taddr,caddr=0; cin>>taddr;
            string path;
            CSP_struct* stru;
            //cout<<"succ"<<endl;
            for(auto it:CSP_var_global)if(it.second.first<=taddr&&it.second.first>=caddr)caddr=it.second.first,stru=it.second.second,path=it.first;
            //cout<<"caddr="<<caddr<<endl;
            while(true){
                int find=0;
                //for(string x:stru->order)cout<<x<<' ';
                //cout<<endl;
                for(string name:stru->order){
                    //cout<<"finding "<<name<<" in "<<stru->restricts<<" "<<stru->size<<endl;
                    pair<ll,CSP_struct*> ch = stru->members[name];
                    //cout<<"succ1"<<endl;
                    //CSP_struct s=(*ch.second);
                    //cout<<"succ1.5"<<endl;
                    //cout<<"d "<<(ch.second->size)<<endl;
                    //cout<<"succ2"<<endl;
                    //<<ch.first<<' '<<caddr<<' '<<ch.second->size<<endl;
                    if(ch.first+caddr<=taddr&&(ch.first+caddr+(ch.second->size))>taddr){
                        path = path + "." + name;
                        if(ch.second->base){
                            cout<<path<<endl;
                            find=2;
                            break;
                        }
                        caddr+=ch.first;
                        stru=ch.second;
                        find=1;
                        break;
                    }
                    //cout<<"succ3"<<endl;
                }
                
                if(find==0){
                    //cout<<caddr<<endl;
                    cout<<"ERR"<<endl;
                }
                if(find!=1)break;
            }
        }
    }
    for(auto pointer:pointers)delete pointer;
    
}