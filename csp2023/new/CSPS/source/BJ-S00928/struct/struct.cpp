#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#define PIL pair<long long,int>
#define x first
#define y second

using namespace std;

typedef long long ll;

const int N=110;

int n,idx,cnt;
ll sz[N],siz[N];
vector<PIL> s[N];
map<string,int> g,f,h[N];
map<string,ll> pos[N],pr;
vector<pair<ll,string> > buc;

ll nxt(ll x,ll y)
{
    return x==-1? 0:x/y*y+y;
}

void insert()
{
    int k;
    string str;
    cin>>str>>k;
    g[str]=++idx;
    ll lst=-1;
    for(int i=1;i<=k;i++)
    {
        int a;
        string s2;
        cin>>s2>>str;
        a=g[s2];
        sz[idx]=max(sz[idx],sz[a]);
        siz[idx]+=siz[a];
        ll now=nxt(lst,sz[a]);
        s[idx].push_back({now,a});
        lst=now+siz[a]-1;
        pos[idx][str]=now;
        h[idx][str]=a;
    }
}

void rel()
{
    string s1,s2;
    cin>>s1>>s2;
    int t=g[s1];
    f[s2]=t;
    int lst=buc[buc.size()-1].x+siz[f[buc[buc.size()-1].y]];
    int now=nxt(lst,sz[t]);
    buc.push_back({now,s2});
    pr[s2]=now;
}

void qr()
{
    string s1;
    cin>>s1;
    cout<<pr[s1]<<'\n';
}

void qp()
{
    ll p;
    cin>>p;
    auto it=upper_bound(buc.begin(),buc.end(),(pair<ll,string>){p,"0"});
    it--;
    if((*it).x+siz[f[(*it).y]]>p)
    {
        cout<<(*it).y<<'\n';
    }
    else
    {
        cout<<"ERR"<<'\n';
    }
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    f["!"]=0;
    buc.push_back({-1,"!"});
    siz[1]=sz[1]=1,siz[2]=sz[2]=2,siz[3]=sz[3]=4,siz[4]=sz[4]=8;
    g["byte"]=1,g["short"]=2,g["int"]=3,g["long"]=4;
    idx=4;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        if(op==1) insert();
        else if(op==2) rel();
        else if(op==3) qr();
        else qp();
    }

    return 0;
}

