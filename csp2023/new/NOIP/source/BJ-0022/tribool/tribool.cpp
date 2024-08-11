#include <bits/stdc++.h>
using namespace std;
#define FILENAME "tribool"
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

struct VALUE{
    int i;
    enum TYPE{ T,F,U } tp;
    VALUE operator!()const{
        if(i!=0) return {-i,tp};
        if(tp==T) return {0,F};
        if(tp==F) return {0,T};
        return {0,U};
    }
};
enum{ N=500005 };
vector<int> G[N];
VALUE V[N];
bool vis[N],inst[N];
int nxt[N]; bool w[N];

int dfs1(int u){ // return sz
    vis[u]=true;
    int ans{1};
    for(int v:G[u]) if(!vis[v]) ans+=dfs1(v);
    return ans;
}
int main(){
    int c,t; fin>>c>>t;
    while(t--){
        int n,m; fin>>n>>m;
        for(int i=1;i<=n;i++) V[i].i=i;
        while(m--){
            char v; fin>>v;
            if(v=='+'){
                int i,j; fin>>i>>j;
                V[i]=V[j];
            }else if(v=='-'){
                int i,j; fin>>i>>j;
                V[i]=!(V[j]);
            }else{
                int i; fin>>i;
                V[i].i=0;
                if(v=='T') V[i].tp=VALUE::T;
                else if(v=='F') V[i].tp=VALUE::F;
                else V[i].tp=VALUE::U;
            }
        }
        const int T=n+1, F=n+2, U=n+3;
        for(int i=1;i<=n;i++){
            int u;
            if(V[i].i==0){
                if(V[i].tp==VALUE::T) u=T;
                else if(V[i].tp==VALUE::F) u=F;
                else u=U;
            }else{
                if(V[i].i<0) u=nxt[i]=-V[i].i, w[i]=1;
                else         u=nxt[i]= V[i].i, w[i]=0;
            }
            G[u].emplace_back(i);
        }

        int ans=dfs1(U)-1;
        dfs1(T), dfs1(F);
        for(int u=1;u<=n;u++) if(!vis[u]){
            vector<int> stk;
            for(int v=u;;v=nxt[v]){
                if(inst[v]){
                    bool sum{0};
                    for(auto it=stk.rbegin();;++it){
                        int p=*it;
                        sum^=w[p];
                        if(p==v) break;
                    }
                    if(sum) ans+=dfs1(v);
                    break;
                }
                if(vis[v]) break;
                stk.emplace_back(v), inst[v]=true;
            }
            for(int i:stk) inst[i]=false, vis[i]=true;
        }
        fout<<ans<<'\n';
        for(int u=1;u<=U;u++) G[u].clear(), vis[u]=false;
    }
}