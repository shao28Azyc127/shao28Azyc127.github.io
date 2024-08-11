#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string s;
map<string,ll> ids;
struct Stu
{
    string typ,nam;
}tmp;
vector<Stu> stu[110];
vector<ll> o[110];
ll siz[110],jp[110],cids=0;
inline ll getsiz(string s)
{
    if(s=="byte") return 1;
    else if(s=="short") return 2;
    else if(s=="int") return 4;
    else if(s=="long") return 8;
    else return siz[ids[s]];
}
inline ll getjp(string s)
{
    if(s=="byte") return 1;
    else if(s=="short") return 2;
    else if(s=="int") return 4;
    else if(s=="long") return 8;
    else return jp[ids[s]];
}
map<string,ll> ide;
struct Ele
{
    string typ,nam;
    ll l,r;
}tnp;
ll cide=0;
Ele ele[110];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%lld",&n);
    ele[0].r=-1;
    while(n--)
    {
        ll op; string s; scanf("%lld",&op);
        if(op==1)
        {
            cin>>s; ll k,ts=0; scanf("%lld",&k);
            string nm=s;
            ids[s]=++cids;
            for(ll i=1;i<=k;i++)
            {
                cin>>s; tmp.typ=s; ts=max(ts,getjp(s));
                cin>>s; tmp.nam=s;
                stu[cids].push_back(tmp);
                if(i==1) o[cids].push_back(0);
                else
                {
                    ll x=o[cids][i-2]+getsiz(stu[cids][i-2].typ);
                    if(x%getjp(tmp.typ)!=0)
                        x=(x/getjp(tmp.typ)+1)*getjp(tmp.typ);
                    o[cids].push_back(x);
                }
            }
            jp[cids]=ts;
            ll x=o[cids][k-1]+getsiz(stu[cids][k-1].typ);
            if(x%getjp(nm)!=0)
                x=(x/getjp(nm)+1)*getjp(nm);
            siz[cids]=x;
            printf("%lld %lld\n",siz[cids],ts);
        }
        else if(op==2)
        {
            cin>>tnp.typ>>tnp.nam;
            ide[tnp.nam]=++cide; ele[cide]=tnp;
            ll x;
            if(cide==1) x=0;
            else
            {
                x=ele[cide-1].l+getsiz(ele[cide-1].typ);
                if(x%getjp(tnp.typ)!=0)
                    x=(x/getjp(tnp.typ)+1)*getjp(tnp.typ);
            }
            ele[cide].l=x;
            ele[cide].r=ele[cide].l+getsiz(ele[cide].typ)-1;
            printf("%lld\n",ele[cide].l);
        }
        else if(op==3)
        {
            cin>>s; string ts=""; ll i;
            for(i=0;i<s.size();i++)
            {
                if(s[i]!='.')
                {
                    ts=ts+s[i];
                    continue;
                }
                i++; break;
            }
            if(i==s.size())
            {
                printf("%lld\n",ele[ide[s]].l);
                continue;
            }
            ll loc=ele[ide[ts]].l; ll nid=ids[ele[ide[ts]].typ];
       //     cout<<ts<<endl; printf("nid=%lld\n",nid);
            ts="";
            for(;i<s.size();i++)
            {
                if(s[i]!='.')
                {
                    ts=ts+s[i];
                    continue;
                }
         //       cout<<ts<<endl;
                for(ll j=0;j<stu[nid].size();j++)
                {
                    if(ts!=stu[nid][j].nam)
                        continue;
                    else
                    {
                        loc+=o[nid][j];
                        nid=ids[stu[nid][j].typ];
                        ts=""; break;
                    }
                }
            }
          //  cout<<ts<<endl;
            for(ll j=0;j<stu[nid].size();j++)
            {
                if(ts!=stu[nid][j].nam)
                    continue;
                else
                {
                    loc+=o[nid][j];
                    printf("%lld\n",loc);
                    break;
                }
            }
        }
        else
        {
            ll k; scanf("%lld",&k); string res="";
            for(ll i=1;i<=cide;i++)
            {
                if(k>ele[i].r) continue;
                res=res+ele[i].nam; break;
            }
            if(res=="")
            {
                printf("ERR\n");
                continue;
            }
            string ts=res; ll x=ele[ide[ts]].l,nid=ids[ele[ide[ts]].typ];
            bool flag=false;
            while(1)
            {
                for(ll j=0;j<stu[nid].size();j++)
                {
                    if(j!=stu[nid].size()-1&&x+o[nid][j+1]<=k)
                        continue;
                    else
                    {
                        x=x+o[nid][j];
                        if(x+getsiz(stu[nid][j].typ)-1<k)
                        {
                            res="ERR";
                            flag=true; break;
                        }
                        res=res+"."; res=res+stu[nid][j].nam;
                        nid=ids[stu[nid][j].typ];
                        if(nid==0) flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
