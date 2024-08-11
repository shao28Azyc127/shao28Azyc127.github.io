#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node{
    ll s,maxn;
    vector<ll> v;
};
map<string,node> m;
struct edge{
    string n,l;
};
vector<edge> v;
struct thing{
    string t;
    ll b;
};
map<string,thing> a;
vector<string> po;
ll now=0,ret;
void dfs(string c,vector<string> b,ll x)
{
    if(x>=b.size())
    {
        ret=now;
        return;
    }
    for(ll i=0;i<m[c].v.size();i++)
    {
        ll y=m[c].v[i];
        string n=v[y].n;
        string l=v[y].l;
        if(n==b[x])
        {
            dfs(l,b,x+1);
            break;
        }
        else
        {
            now+=m[c].maxn;
        }
    }
    return;
}
ll check(vector<string> b)
{
    string s=b[0];
    string c=a[s].t;
    now=a[s].b;
    dfs(c,b,1);
    return ret;
}
void f(string s,ll x)
{
    node y=m[s];
    for(ll i=0;i<y.v.size();i++)
    {
        edge o=v[y.v[i]];
//        cout<<s<<" "<<now<<" "<<m[s].maxn<<" "<<endl;
        if(now<=x and now+m[s].maxn>x)
        {
            cout<<"."<<o.n;
            f(o.l,x);
            break;
        }
        now+=m[s].maxn;
    }
    return;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ll t,sum=0;
    cin>>t;
    m["short"].s=2;
    m["short"].maxn=2;
    m["int"].s=4;
    m["int"].maxn=4;
    m["long"].s=8;
    m["long"].maxn=8;
    m["byte"].s=1;
    m["byte"].maxn=1;
    while(t--)
    {
        ll op;
        cin>>op;
        if(op==1)
        {
            string s;
            ll k;
            cin>>s>>k;
            ll maxn=-1;
            for(ll i=1;i<=k;i++)
            {
                string c,na;
                cin>>c>>na;
                maxn=max(maxn,m[c].s);
                v.push_back({na,c});
                m[s].v.push_back(v.size()-1);
            }
            m[s].s=maxn*k;
            m[s].maxn=maxn;
            cout<<m[s].s<<" "<<m[s].maxn<<endl;
        }
        else if(op==2)
        {
            string c,s;
            cin>>c>>s;
            a[s].t=c;
            a[s].b=sum;
            po.push_back(s);
//            buid(s,c);
            sum+=m[a[s].t].s;
            cout<<a[s].b<<endl;
        }
        else if(op==3)
        {
            vector<string> b;
            string s;
            cin>>s;
            string ss="";
            for(ll i=0;i<s.size();i++)
            {
                if(s[i]=='.')
                {
                    b.push_back(ss);
                    ss="";
                }
                else
                {
                    ss+=s[i];
                }
            }
            b.push_back(ss);
            ss="";
            cout<<check(b)<<endl;
        }
        else
        {
            bool flag=false;
            ll x;
            cin>>x;
            for(ll i=0;i<po.size()-1;i++)
            {
                string s=po[i];
                if(a[s].b<=x and a[po[i+1]].b>x)
                {
                    cout<<s;
                    now=a[s].b;
                    f(a[s].t,x);
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                cout<<po[po.size()-1];
                now=a[po[po.size()-1]].b;
                f(a[po[po.size()-1]].t,x);
            }
            cout<<endl;
        }
    }
    return 0;
}
