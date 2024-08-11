#include <bits/stdc++.h>
using namespace std;
#define FILENAME "run"
struct myin{
    static inline ifstream fin{FILENAME".in"};
    char buf[1<<20],*s,*p;
    myin(){ flush(); }
    void flush(){ *buf=0, fin.read(buf,sizeof(buf)), s=buf, p=s+fin.gcount(); }
    void prog(){ if(++s==p) flush(); }
    void skip(){ while(*s==' '||*s=='\r'||*s=='\n') prog(); }
    myin& operator>>(char& x){
        skip(), x=*s, prog();
        return *this;
    }
    myin& operator>>(auto& x){
        x=0;
        bool sgn{false};
        for(;!isdigit(*s);prog()) if(*s=='-') sgn=true;
        for(; isdigit(*s);prog()) (x*=10)+=*s^'0';
        if(sgn) x=-x;
        return *this;
    }
}fin;
struct myout{
    static inline ofstream fout{FILENAME".out"};
    char buf[1<<20],*s{buf};
    ~myout(){ flush(); }
    void flush(){ fout.write(buf,s-buf), s=buf; }
    void prog(){ if(++s==end(buf)) flush(); }
    myout& operator<<(char x){
        *s=x, prog();
        return *this;
    }
    myout& operator<<(auto x){
        if(x<0) x=-x, operator<<('-');
        char buf[20],*p{buf};
        do *(p++)=x%10^'0'; while(x/=10);
        while(p-->buf) *s=*p, prog();
        return *this;
    }
}fout;

template<typename T,typename P=T> void tomax(T& x,const P& y){ if(x<y) x=y; }
template<typename T,typename P=T> void tomin(T& x,const P& y){ if(x>y) x=y; }
using ll=long long;
#define cauto const auto
#define cint const int
#define cll const ll

enum{ N=100005 };

struct SEGT{
    using pSEGT=SEGT*;
    cint l,r;
    const pSEGT pl,pr;
    ll val,tag;
    SEGT(cint l,cint r):l(l),r(r),
      pl(leaf()?nullptr:new SEGT(l,mid())),
      pr(leaf()?nullptr:new SEGT(mid(),r)),
      val(0),tag(0){}
    bool leaf()const{ return l==r-1; }
    int mid()const{ return (l+r)>>1; }
    void update(cll v){ val+=v, tag+=v; }
    void pushdown(){ pl->update(tag), pr->update(tag), tag=0; }
    void modify(cint ql,cint qr,cll v){
        if(ql<=l&&r<=qr) return update(v);
        pushdown();
        if(ql<mid()) pl->modify(ql,qr,v);
        if(qr>mid()) pr->modify(ql,qr,v);
        val=max(pl->val,pr->val);
    }
    ll query(cint ql,cint qr){
        if(ql<=l&&r<=qr) return val;
        pushdown();
        if(qr<=mid()) return pl->query(ql,qr);
        if(ql>=mid()) return pr->query(ql,qr);
        return max(pl->query(ql,qr),pr->query(ql,qr));
    }
};
int main(){
    int c,t; fin>>c>>t;
    while(t--){
        int n,q,k,d; fin>>n>>q>>k>>d;
        vector<tuple<int,int,int>> Q; // [l,r) v
        vector<int> vec;
        while(q--){
            int x,y,v; fin>>x>>y>>v;
            Q.emplace_back(x-y,x,v);
            vec.push_back(x-y), vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        cint m=vec.size();
        cauto lsh=[&](int& i){ i=lower_bound(vec.begin(),vec.end(),i)-vec.begin(); };
        for(auto&[l,r,v]:Q) lsh(l), lsh(r);
        sort(Q.begin(),Q.end(),[](cauto& L,cauto& R){ return get<1>(L)<get<1>(R); });
        auto it=Q.cbegin();
        SEGT Segt(0,m);

        ll f{0};
        int lst{0};
        for(int i=1;i<m;i++){
            while(vec[i]-vec[lst]>k) ++lst;
            for(;it!=Q.cend()&&get<1>(*it)==i;++it) Segt.modify(0,get<0>(*it)+1,get<2>(*it));
            Segt.modify(0,i,-d*ll(vec[i]-vec[i-1]));
            Segt.modify(i,i+1,f);
            f=Segt.query(lst,i+1);
        }
        fout<<f<<'\n';
    }
}