#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll it;
int n,op;
map<string,int>mx,siz;
struct st
{
    string name;
    int mx,siz;//¶ÔÆësiz,×Üsiz
    map<string,pair<ll,ll> >member;
    set<pair<string,string> >stt;
};
vector<st>v;
set<pair<string,string> >se;
map<string,pair<ll,ll> >mp;
inline bool in(string ss)
{
    return ss=="byte"||ss=="short"||ss=="int"||ss=="long";
}
inline void dec_st()
{
    string s;
    int k;
    cin>>s>>k;
    st tmp;
    tmp.mx=tmp.siz=0;
    tmp.member.clear();
    tmp.name=s;
    int itr=0;
    for(int i=1;i<=k;i++)
    {
        string typ,nam;
        cin>>typ>>nam;
        while(itr%mx[typ])itr++;
        tmp.member[nam]=make_pair(itr,itr+siz[typ]);
        tmp.stt.insert(make_pair(nam,typ));
        itr+=siz[typ];
        tmp.mx=max(tmp.mx,mx[typ]);
    }
    tmp.siz=((itr-1)/tmp.mx+1)*tmp.mx;
    mx[s]=tmp.mx,siz[s]=tmp.siz;
    v.push_back(tmp);
    cout<<tmp.siz<<' '<<tmp.mx<<'\n';
}
inline void add_ele()
{
    string typ,nam;
    cin>>typ>>nam;
    while(it%mx[typ])it++;
    cout<<it<<'\n';
    mp[nam]=make_pair(it,it+siz[typ]);
    it+=siz[typ];
    se.insert(make_pair(nam,typ));
}
inline void get_adr()
{
    string s;
    cin>>s;
    cout<<mp[s].first<<'\n';
}
inline string find_in_st(st x,ll pos)
{
    string ed="$";
    for(auto e:x.member)
    {
        if(e.second.first<=pos&&e.second.second>=pos)
        {
            ed=e.first;
            break;
        }
    }
    if(ed=="$")return "$";
    pair<string,string>p;
    for(auto t:x.stt)
    {
        if(t.first==ed)
        {
            p=t;
            break;
        }
    }
    if(in(p.second))
    {
        return p.first;
    }
    pos-=x.member[p.first].first;
    st tmp;
    for(auto t:v)
    {
        if(t.name==p.first)
        {
            tmp=t;
            break;
        }
    }
    string ttp=find_in_st(tmp,pos);
    return ttp=="$"?"$":"."+ed+ttp;
}
inline void find_adr()
{
    ll pos;
    cin>>pos;
    if(pos>it)
    {
        cout<<"ERR\n";
        return;
    }
    string ed="ERR";
    for(auto x:mp)
    {
        if(x.second.first<=pos&&x.second.second>=pos)
        {
            ed=x.first;
            break;
        }
    }
    if(ed=="ERR")
    {
        cout<<"ERR\n";
        return;
    }
    pair<string,string>p;
    for(auto x:se)
    {
        if(x.first==ed)
        {
            p=x;
            break;
        }
    }
    if(in(p.second))
    {
        cout<<p.first<<'\n';
        return;
    }
    pos-=mp[p.first].first;
    st tmp;
    for(auto x:v)
    {
        if(x.name==p.first)
        {
            tmp=x;
            break;
        }
    }
    string str=find_in_st(tmp,pos);
    str=="$"?cout<<"ERR\n":cout<<ed<<str;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    siz["byte"]=mx["byte"]=1,siz["short"]=mx["short"]=2,siz["int"]=mx["int"]=4,siz["long"]=mx["long"]=8;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op;
        if(op==1)
        {
            dec_st();
        }
        if(op==2)
        {
            add_ele();
        }
        if(op==3)
        {
            get_adr();
        }
        if(op==4)
        {
            find_adr();
        }
    }
    return 0;
}

