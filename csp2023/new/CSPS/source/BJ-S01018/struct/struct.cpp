#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define p_b push_back
#define m_p make_pair
#define p1 first
#define p2 second
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
inline ll read(){
    ll x=0;short t=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')t=-1;
        ch=getchar();
    }while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*t;
}int id;
ll p;
struct node {
    vector<pair<string,pair<string,int> > >mp;
    map<string,pair<string,int> >mp2;
    ll sum,l,r;
    string op,s;
    int fa;
}d[maxn];
struct nd {
    vector<pair<string,string> >vec;
    vector<int>qwq;
    int ww;
};
map<string,nd>mp;
map<string,int>mp2;
map<pair<ll,ll>,int>mp_memory;
map<string,int>mp3;
ll cl(ll a,ll b){
    return (a+b-1)/b;
}
int get(string &op){
    if(mp2.count(op))return mp2[op];
    int res=0;
    int x=0,s=0;
    int mx=0;
    for(auto it:mp[op].vec){
        mp[op].ww=max(mp[op].ww,mp[it.p1].ww);
        if(!x)mp[op].qwq.p_b(0);
        else mp[op].qwq.p_b(cl(mp[op].qwq.back()+s,mp[it.p1].ww)*mp[it.p1].ww);
        x++;
        mx=max(mx,mp[op].ww);
        s=get(it.p1);
    }mp2[op]=cl(mp[op].qwq.back()+s,mx)*mx;
    return mp2[op];
}
int build(string &op,string &s){
    ++id;
    d[id].op=op,d[id].s=s;
    int now=id;
    if(op=="byte"||op=="short"||op=="int"||op=="long")return id;
    for(auto it:mp[op].vec){
        int g=build(it.p1,it.p2);
        d[g].fa=now;
        d[now].mp2[it.p2].p1=it.p1;
        d[now].mp2[it.p2].p2=g;
        d[now].mp.p_b(m_p(it.p2,m_p(it.p1,g)));
    }return now;
}void build2(int id,ll l,ll r){
    d[id].l=l,d[id].r=r;
    //cout<<"test "<<id<<' '<<l<<' '<<r<<'\n';
    if(d[id].op=="byte"||d[id].op=="short"||d[id].op=="int"||d[id].op=="long"){
        mp_memory[m_p(l+mp2[d[id].op]-1,l)]=id;
        return;
    }int j=0;
    int L=l;
    int F=0;
    for(auto it:d[id].mp){
        //build2(it.p2.p2,L+mp[d[id].op].qwq[j],((j!=d[id].mp.size()-1)?(L+mp[d[id].op].qwq[j+1]-1):r));
        if(!j)build2(it.p2.p2,L,L+get(it.p2.p1)-1),F=L+get(it.p2.p1);
        else {
            int x=cl(F,mp[d[it.p2.p2].op].ww)*mp[d[it.p2.p2].op].ww;
            build2(it.p2.p2,x,x+get(it.p2.p1)-1),F=x+get(it.p2.p1);
        }
        j++;
    }
}ll dfs(string s,string t,int id){
    //cout<<"test "<<s<<' '<<t<<' '<<id<<'\n';
    string now="";
    if(!t.size())return d[id].l;
    int f=-1;
    up(i,0,t.length()-1){
        if(t[i]=='.'){f=i;break;}
        now+=t[i];
    }
    string now2="";
    if(f!=-1){up(i,f+1,t.length()-1)now2+=t[i];}
    //cout<<"test "<<now<<' '<<now2<<'\n';
    return dfs(now,now2,d[id].mp2[now].p2);
}void slv_4(ll x){
    auto it=mp_memory.lower_bound(m_p(x,0));
    if(it==mp_memory.end()){cout<<"ERR\n";return;}
    int f=(*it).p2;
    if((*it).p1.p2>x){cout<<"ERR\n";return;}
    vector<int>g;
    while(f){
        g.p_b(f);
        f=d[f].fa;
    }reverse(g.begin(),g.end());
    up(i,0,g.size()-1){
        cout<<d[g[i]].s;
        if(i!=g.size()-1)cout<<'.';
        else cout<<'\n';
    }
}
void slv(){
    mp2["byte"]=1;
    mp2["short"]=2;
    mp2["int"]=4;
    mp2["long"]=8;
    mp["byte"].vec.resize(1);
    mp["short"].vec.resize(1);
    mp["int"].vec.resize(1);
    mp["long"].vec.resize(1);
    mp["byte"].ww=1,mp["short"].ww=2,mp["int"].ww=4,mp["long"].ww=8;
    int q;cin>>q;
    while(q--){
        int op;cin>>op;
        if(op==1){
            string s;int k;
            cin>>s>>k;
            while(k--){
                string a,b;
                cin>>a>>b;
                mp[s].vec.p_b(m_p(a,b));
            }int res=get(s);
            cout<<res<<' '<<mp[s].ww<<'\n';
        }else if(op==2){
            string s,t;
            cin>>s>>t;
            int x=build(s,t);
            cout<<p<<'\n';
            build2(x,p,p+mp2[s]-1);
            p+=mp2[s];
            mp3[t]=x;
        }else if(op==3){
            string s;
            cin>>s;
            string now="";
            int f=-1;
            up(i,0,s.length()-1){
                if(s[i]=='.'){f=i;break;}
                now+=s[i];
            }if(f==-1)cout<<d[mp3[s]].l<<'\n';
            else {
                string kk="";
                up(i,f+1,s.length()-1)kk+=s[i];
                //cout<<"qwq "<<now<<' '<<kk<<'\n';
                cout<<dfs(now,kk,mp3[now])<<'\n';
            }
        }else {
            slv_4(read());
        }
    }
}int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    slv();
    fclose(stdin);
    fclose(stdout);
    return 0;
}