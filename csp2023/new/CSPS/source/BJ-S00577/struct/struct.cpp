#include<iostream>
#include<unordered_map>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 105
typedef long long ll;
struct tarnode{
    string name;
    ll tab,sz,cnt;
    vector<string> tarname,tartype;
};
unordered_map<string,tarnode> mp;
struct opnode{
    string type,name;
    ll l,r;
};
vector<opnode> ops;
int q;
ll addr;
void init(){
    tarnode bt,sh,it,lg;
    bt={"byte",1,1,1};
    sh={"short",2,2,1};
    it={"int",4,4,1};
    lg={"long",8,8,1};
    mp["byte"]=bt;
    mp["short"]=sh;
    mp["int"]=it;
    mp["long"]=lg;
}
void work1(){
    tarnode now;
    cin>>now.name>>now.cnt;
    now.tab=0;
    for(int i=1;i<=now.cnt;i++){
        string opname,optype;
        cin>>optype>>opname;
        now.tab=max(now.tab,mp[optype].sz);
        now.tarname.push_back(opname);
        now.tartype.push_back(optype);
    }
    now.sz=now.cnt*now.tab;
    mp[now.name]=now;
    cout<<now.sz<<" "<<now.tab<<endl;
}
void work2(){
    opnode now;
    cin>>now.type>>now.name;
    now.l=addr;
    now.r=addr+mp[now.type].sz-1;
    addr=now.r+1;
    ops.push_back(now);
    cout<<now.l<<endl;
}
void work3(){
    string tmp;
    cin>>tmp;
    int scn=0;
    string nowname="";
    for(;tmp[scn]&&tmp[scn]!='.';scn++){
        nowname+=tmp[scn];
    }
    string nowtype;
    ll tab,idx=0;
    for(auto v:ops){
        if(v.name==nowname){
            idx=v.l;
            nowtype=v.type;
            break;
        }
    }
    if(tmp[scn]==0){
        cout<<idx<<endl;
        return;
    }
    for(++scn;tmp[scn];scn++){
        nowname="";
        for(;tmp[scn]&&tmp[scn]!='.';scn++){
            nowname+=tmp[scn];
        }
        tab=mp[nowtype].tab;
        tarnode now=mp[nowtype];
        for(int i=0;i<now.tarname.size();i++){
            if(now.tarname[i]==nowname){
                nowtype=now.tartype[i];
                break;
            }
            else{
                idx+=tab;
            }
        }
        if(tmp[scn]==0) break;
    }
    cout<<idx<<endl;
}
void work4(){
    ll goal;
    cin>>goal;
    ll idx=-1;
    string nowtype,nowname;
    vector<string> ans;
    ans.clear();
    for(auto v:ops) if(v.l<=goal&&v.r>=goal){
        idx=v.l;
        nowtype=v.type;
        nowname=v.name;
        ans.push_back(nowname);
        break;
    }
    if(idx==-1){
        cout<<"ERR"<<endl;
        return;
    }
    while(1){
        tarnode now=mp[nowtype];
        if(now.tartype.empty()){
            if(idx+now.tab-1<goal){
                cout<<"ERR"<<endl;
                break;
            }
            else{
                cout<<ans[0];
                for(int i=1;i<ans.size();i++) cout<<"."<<ans[i];
                cout<<endl;
                break;
            }
        }
        bool vis=0;
        for(int i=0;i<now.tartype.size();i++){
            if(idx+now.tab>goal){
                vis=1;
                nowtype=now.tartype[i];
                nowname=now.tarname[i];
                ans.push_back(nowname);
                break;
            }
            else idx+=now.tab;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    init();
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1) work1();
        else if(op==2) work2();
        else if(op==3) work3();
        else if(op==4) work4();
    }
    return 0;
}