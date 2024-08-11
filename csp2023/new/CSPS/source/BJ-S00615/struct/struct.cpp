#include <bits/stdc++.h>
#define rfor(i,l,r) for(int i=l;i<=r;i++)
#define irfor(i,r,l) for(int i=r;i>=l;i--)
#define ls(p) p<<1
#define rs(p) p<<1|1
#define y0 qwrgshsjglarahfkagr
#define y1 soighsodighslighddd
#define mkp make_pair
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<string,string> pss;
inline ll read()
{
    ll x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}
inline void gmin(int &a,int b){if(b<a)a=b;}inline void gmax(int &a,int b){if(b>a)a=b;}
inline void gmin(ll &a,ll b){if(b<a)a=b;}inline void gmax(ll &a,ll b){if(b>a)a=b;}
inline int min(int a,int b){return a<b?a:b;}inline int max(int a,int b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}inline ll max(ll a,ll b){return a>b?a:b;}
const int N = 105,mod = 1e9+7;
struct stu{
    ll k,dql,len;
    vector<pss> v;
    vector<ll> o;
    map<string,int> fcmp;
    void solve();
}st[N];int cnt;
map<string,int> stump;
inline ll getdq(string s)
{
    if(s == "byte") return 1;
    if(s == "short") return 2;
    if(s == "int") return 4;
    if(s == "long") return 8;
    return st[stump[s]].dql;
}
inline ll getsize(string s)
{
    if(s == "byte") return 1;
    if(s == "short") return 2;
    if(s == "int") return 4;
    if(s == "long") return 8;
    return st[stump[s]].len;
}
void stu::solve()
{
    o.clear();fcmp.clear();dql = len = 0;
    rfor(i,0,k-1)
    {
        pss x = v[i];
        fcmp[x.second] = i;
        ll dq = getdq(x.first),nlen = getsize(x.first);
        while(len%dq) len++;
        o.push_back(len);
        len += nlen;gmax(dql,dq);
    }
    while(len%dql) len++;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,op;string s,s1,s2;
    cin >> n;
    stump["byte"] = 0;stump["short"] = 0;stump["int"] = 0;stump["long"] = 0;
    while(n--)
    {
        cin >> op;
        if(op == 1)
        {
            cnt++;
            cin >> s;
            stump[s] = cnt;
            cin >> st[cnt].k;
            rfor(i,1,st[cnt].k)
            {
                cin >> s1 >> s2;
                st[cnt].v.push_back(mkp(s1,s2));
            }
            st[cnt].solve();
            cout << st[cnt].len << ' ' << st[cnt].dql << '\n';
        }
        else if(op == 2)
        {
            cin >> s1 >> s2;
            st[0].k++;
            st[0].v.push_back(mkp(s1,s2));
            st[0].solve();
            cout << st[0].o[st[0].k-1] << '\n';
        }
        else if(op == 3)
        {
            cin >> s;s += '.';
            int nl = s.length();
            ll pos = 0,mvo = 0;
            string ts = "";
            rfor(i,0,nl-1)
            {
                if(s[i] == '.')
                {
                    int ncnt = st[pos].fcmp[ts];
                    mvo += st[pos].o[ncnt];
                    pos = stump[st[pos].v[ncnt].first];
                    ts = "";
                }
                else ts += s[i];
            }
            cout << mvo << '\n';
        }
        else
        {
            ll pos = 0,mvo;cin >> mvo;s = "";
            while(1)
            {
                if(mvo > st[pos].len || st[pos].k == 0)
                {
                    s = "ERR";
                    goto prt;
                }
                rfor(i,0,st[pos].k-1)
                {
                    if(i == st[pos].k-1)
                    {
                        if(mvo < st[pos].o[i]+getsize(st[pos].v[i].first))
                        {
                            if(s != "") s+=".";
                            s += st[pos].v[i].second;
                            mvo -= st[pos].o[i];
                            pos = stump[st[pos].v[i].first];
                            if(pos == 0) goto prt;
                            goto nxt;
                        }
                        else
                        {
                            s = "ERR";
                            goto prt;
                        }
                    }
                    else
                    {
                        if(mvo < st[pos].o[i+1])
                        {
                            if(mvo < st[pos].o[i]+getsize(st[pos].v[i].first))
                            {
                                if(s != "") s+=".";
                                s += st[pos].v[i].second;
                                mvo -= st[pos].o[i];
                                pos = stump[st[pos].v[i].first];
                                if(pos == 0) goto prt;
                                goto nxt;
                            }
                            else
                            {
                                s = "ERR";
                                goto prt;
                            }
                        }
                    }
                }
                nxt:;
            }
            prt:
            cout << s << '\n';
        }
    }
    return 0;
}
