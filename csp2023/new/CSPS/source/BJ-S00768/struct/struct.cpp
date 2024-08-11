#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#define ll long long
#define _mp make_pair
#define _pb push_back
#define _1 first
#define _2 second
#define MAX_N 104

using namespace std;

inline void drf(ll& adr, ll prn) { adr = (adr + prn - 1) / prn * prn; }

struct node
{
    ll prn, sz;
    string name;
    map<string, pair<node*, ll> > mp;
    map<ll, pair<node*, string> > st;
} p[MAX_N];

int tot;
map<string/*str*/, node*/*tpe*/> stt; // struct str <=> tpe
map<string/*str*/, pair<node*/*tpe*/, ll/*adr*/> > epo; // str has type tpe, saved in adr
map<ll/*adr*/, pair<node*/*tpe*/, string/*str*/> > url; // adr exists a tpe
ll adrs;

void init()
{
    tot++, p[tot].name = "byte", p[tot].sz = p[tot].prn = 1, stt["byte"] = p + tot;
    tot++, p[tot].name = "short", p[tot].sz = p[tot].prn = 2, stt["short"] = p + tot;
    tot++, p[tot].name = "int", p[tot].sz = p[tot].prn = 4, stt["int"] = p + tot;
    tot++, p[tot].name = "long", p[tot].sz = p[tot].prn = 8, stt["long"] = p + tot;
}

void newstruct()
{
    tot++;
    cin >> p[tot].name;
    int k;
    cin >> k;
    struct node* t[MAX_N];
    static string n[MAX_N], tmp;
    for(int i = 1; i <= k; i++)
    {
        cin >> tmp;
        t[i] = stt[tmp];
        cin >> n[i];
        p[tot].prn = max(p[tot].prn, t[i]->prn);
    }
    ll sw = 0;
    ll ladrs = sw;
    for(int i = 1; i <= k; i++)
    {
        drf(sw, t[i]->prn);
        p[tot].mp[n[i]] = _mp(t[i], sw);
        sw += t[i]->sz;
    }
    drf(sw, p[tot].prn);
    for(auto i: p[tot].mp)
        p[tot].st[i._2._2] = _mp(i._2._1, i._1);
    p[tot].sz = sw - ladrs;
    stt[p[tot].name] = p + tot;
    cout << p[tot].sz << ' ' << p[tot].prn << endl;
}

void newval()
{
    node* t;
    static string n, tmp;
    cin >> tmp;
    t = stt[tmp];
    cin >> n;
    drf(adrs, t->prn);
    epo[n] = _mp(t, adrs);
    url[adrs] = _mp(t, n);
    cout << adrs << endl;
    adrs += t->sz;
}

void queryadr()
{
    static string s, tmp;
    cin >> tmp;
    bool flag = 0;
    node* t;
    ll adr;
    tmp._pb('.');
    for(auto i: tmp)
        if(i != '.')
            s._pb(i);
        else
        {
            if(!flag)
            {
                pair<node*, ll> tmp2 = epo[s];
                flag = 1;
                t = tmp2._1;
                adr = tmp2._2;
            }
            else
            {
                pair<node*, ll> tmp2 = t->mp[s];
                t = tmp2._1;
                adr += tmp2._2;
            }
            s.clear();
        }
    cout << adr << endl;
}

void checkadr()
{
    ll adr, now;
    node* t;
    cin >> adr;
    if(url.empty())
    {
        cout << "ERR" << endl;
        return;
    }
    map<ll, pair<node*, string> > :: iterator iu = --url.upper_bound(adr);
    static string ans;
    now = iu->_1, t = iu->_2._1, ans = iu->_2._2;
    while(!t->st.empty())
    {
        map<ll, pair<node*, string> > :: iterator iu = --t->st.upper_bound(adr - now);
        now += iu->_1, t = iu->_2._1, ans._pb('.'), ans += iu->_2._2;
    }
    //printf("now = %lld adr = %lld\n", now, adr);
    ll sr = adr - now;
    if(t->sz > sr)
        cout << ans << endl;
    else
        cout << "ERR" << endl;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios :: sync_with_stdio(false), cin.tie(0);
    init();
    int T;
    cin >> T;
    while(T--)
    {
        int op;
        cin >> op;
        if(op == 1)
            newstruct();
        else if(op == 2)
            newval();
        else if(op == 3)
            queryadr();
        else if(op == 4)
            checkadr();
    }
    return 0;
}
