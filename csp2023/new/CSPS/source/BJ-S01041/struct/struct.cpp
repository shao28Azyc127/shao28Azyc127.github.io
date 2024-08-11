#include <bits/stdc++.h>
using namespace std;
ifstream fin("struct.in");
ofstream fout("struct.out");

void tomax(auto& x,const auto& y){ if(x<y) x=y; }
void tomin(auto& x,const auto& y){ if(x>y) x=y; }
using ll=long long;
using ITEM=tuple<string,ll,const struct TYPE&>; // (member_name,offset,type)
struct CMP2{
    using is_transparent=void;
    bool operator()(const ITEM& tp1,const ITEM& tp2)const{
        return get<0>(tp1)<get<0>(tp2);
    }
    bool operator()(const ITEM& tp,const string& name)const{
        return get<0>(tp)<name;
    }
};
using ITEMS=set<ITEM,CMP2>;
struct TYPE{
    string name;
    ll sz;
    int align;
    ITEMS memb;
};
struct CMP{
    using is_transparent=void;
    bool operator()(const TYPE& tp1,const TYPE& tp2)const{
        return tp1.name<tp2.name;
    }
    bool operator()(const TYPE& tp,const string& name)const{
        return tp.name<name;
    }
};
set<TYPE,CMP> Type;
ll sz{0};
ITEMS Item;
void init(){
    static TYPE t1{"byte", 1,1,{}};
    static TYPE t2{"short",2,2,{}};
    static TYPE t4{"int",  4,4,{}};
    static TYPE t8{"long", 8,8,{}};
    Type.insert(t1);
    Type.insert(t2);
    Type.insert(t4);
    Type.insert(t8);
}
int main(){
    init();
    int T; fin>>T;
    while(T--){
        int op; fin>>op;
        if(op==1){
            string s; int k; fin>>s>>k;
            TYPE& tp=*new TYPE{move(s),0,1,{}};
            while(k--){
                string t,n; fin>>t>>n;
                const TYPE& memb=*Type.lower_bound(t);
                while(tp.sz%memb.align!=0) ++tp.sz;
                tomax(tp.align,memb.align);
                tp.memb.emplace(move(n),tp.sz,memb);
                tp.sz+=memb.sz;
            }
            while(tp.sz%tp.align!=0) ++tp.sz;
            fout<<tp.sz<<' '<<tp.align<<'\n';
            Type.insert(move(tp));
        }else if(op==2){
            string t,n; fin>>t>>n;
            const TYPE& memb=*Type.lower_bound(t);
            while(sz%memb.align!=0) ++sz;
            Item.emplace(move(n),sz,memb);
            fout<<sz<<'\n';
            sz+=memb.sz;
        }else if(op==3){
            ll ptr{0};
            string s; fin>>s, s.push_back('.');
            const ITEMS* st{&Item};
            for(size_t i=0;i<s.size();i++){
                const auto j=s.find('.',i);
                const string n=s.substr(i,j-i);
                const ITEM& itm=*st->lower_bound(n);
                ptr+=get<1>(itm);
                st=&get<2>(itm).memb;
                i=j;
            }
            fout<<ptr<<'\n';
        }else{
            ll ptr; fin>>ptr;
            const ITEMS* st{&Item};
            string s,n;
            while(n!="int"&&n!="short"&&n!="byte"&&n!="long"){
                for(const ITEM& itm:*st){
                    const ll L=get<1>(itm), R=L+get<2>(itm).sz;
                    if(ptr<L||ptr>=R) continue;
                    s+=get<0>(itm), s.push_back('.');
                    st=&get<2>(itm).memb;
                    n=get<2>(itm).name;
                    ptr-=L;
                    goto label;
                }
                goto label2;
                label: ;
            }
            if(ptr>=Type.lower_bound(n)->sz) goto label2;
            s.pop_back(), fout<<s<<'\n';
            continue;
            label2: fout<<"ERR\n";
        }
    }
    return 0;
}