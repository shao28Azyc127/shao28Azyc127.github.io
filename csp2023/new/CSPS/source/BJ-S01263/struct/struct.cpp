#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define mkpr make_pair
struct S
{
    ull dq;
    ull sz;
    map<string,pair<ull,string>> r;
    map<ull,pair<string,string>> r0;
    S(ull sz=0,ull dq=0):dq(dq),sz(sz){}
};

struct V
{
    string tp,name;
    ull st;
};

map<string,S> mp;
map<string,V> v0;
map<ull,V> v1;
ull lst=0;

void Build()
{
    string nm;
    ull k,dq=0;
    cin>>nm>>k;
    S s;
    ull lst=0;
    while (k--)
    {
        string tp,name;
        cin>>tp>>name;
        ull tmp=mp[tp].dq;
        dq=max(dq,tmp);
        ull st=(lst+tmp-1)/tmp*tmp;
        lst=st+mp[tp].sz;
        //cerr<<nm<<','<<name<<": "<<st<<'\n';
        s.r[name]=mkpr(st,tp);
        s.r0[st]=mkpr(tp,name);
    }
    s.dq=dq;
    s.sz=(lst+dq-1)/dq*dq;
    mp[nm]=s;
    cout<<s.sz<<" "<<dq<<'\n';
    //cerr<<nm<<", "<<s.dq<<','<<s.sz<<'\n';
}
void New()
{
    string t,n;
    cin>>t>>n;
    V v;
    ull dq=mp[t].dq;
    v.st=(lst+dq-1)/dq*dq;
    v.tp=t;
    v.name=n;
    lst=v.st+mp[t].sz;
    v0[n]=v;
    v1[v.st]=v;
    cout<<v.st<<'\n';
}
void Search()
{
    vector<string> n;
    string tmp,tmp0;
    cin>>tmp;
    for (char s:tmp)
    {
        if (s=='.') n.emplace_back(tmp0),tmp0.clear();
        else tmp0+=s;
    }
    n.emplace_back(tmp0);

    ull st=v0[n[0]].st;
    S*tp=&mp[v0[n[0]].tp];
    rep (i,1,n.size()-1) 
    {
        st+=tp->r[n[i]].first,tp=&mp[ tp->r[n[i]].second ];
    }
    cout<<st<<'\n';
}
void On()
{
    ull addr;
    cin>>addr;
    auto i=v1.upper_bound(addr);
    if (i==v1.begin())
    {
        cout<<"ERR\n";
        return;
    }
    --i;
    S*tp=&mp[i->second.tp];
    string tpn=i->second.tp;
    ull st=i->second.st;
    string res=i->second.name;
    /*for (auto&p:mp)
    {
        cerr<<p.first<<": "<<p.second.sz<<','<<p.second.dq<<'\n';
    }*/
    while (true)
    {
        if (tpn=="byte"||tpn=="short"||tpn=="int"||tpn=="long")
        {
            cout<<(addr>=st&&addr<st+tp->sz?res:"ERR")<<'\n';
            //cerr<<res<<","<<addr<<": "<<st<<','<<tp->sz<<'\n';
            return;
        }
        auto i=tp->r0.upper_bound(addr-st);
        if (i==tp->r0.begin())
        {
            cout<<"ERR\n";
            return;
        }
        
        --i;
        st+=i->first;
        res+='.';
        res+=i->second.second;
        tp=&mp[i->second.first];
        tpn=i->second.first;
    }
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    mp.emplace("byte",S(1,1));
    mp.emplace("short",S(2,2));
    mp.emplace("int",S(4,4));
    mp.emplace("long",S(8,8));
    rep (i,1,n)
    {
        int op;
        cin>>op;
        if (op==1) Build();
        if (op==2) New();
        if (op==3) Search();
        if (op==4) On();
    }
    return 0;
}