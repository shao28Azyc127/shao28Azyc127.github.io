#include<iostream>
#include<map>
using namespace std;
int sz1,sz2;
struct tp
{
    int sum;
    long long stp[101];
    pair<string,string> id[101];
    long long p,tot;
} jgt[101];
map<string,long long> Ps,TOTs,eman,ADDs;
map<string,string> TYPs;
long long nxttimes(long long x,long long y)
{
    if(x % y == 0) return x;
    return (x/y+1)*y;
}
long long getsize_p(string t)
{
    if(t == "byte") return 1;
    if(t == "short") return 2;
    if(t == "int") return 4;
    if(t == "long") return 8;
    return Ps[t];
}
long long getsize_t(string t)
{
    if(t == "byte") return 1;
    if(t == "short") return 2;
    if(t == "int") return 4;
    if(t == "long") return 8;
    return TOTs[t];
}
long long nxt;
struct item
{
    pair<string,string> id;
    long long add;
} ys[101];
string ans;
void query(string type,long long k)
{
    if(type == "byte" || type == "short" || type == "int" || type == "long")
    {
        if(getsize_t(type) <= k) ans = "ERR";
        return;
    }
    int rtp = eman[type];
    for(int i = 1;i <= jgt[rtp].sum;i++)
    {
        if(i == jgt[rtp].sum || k-jgt[rtp].stp[i+1] < 0)
        {
            ans += ".";
            ans += jgt[rtp].id[i].second;
            query(jgt[rtp].id[i].first,k-jgt[rtp].stp[i]);
            break;
        }
    }
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,op;
    long long k;
    string name,type,nm;
    cin >> n;
    while(n--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> name >> k;
            jgt[++sz1].sum = k;
            jgt[sz1].tot = 0;
            eman[name] = sz1;
            for(int i = 1;i <= k;i++)
            {
                cin >> type >> nm;
                jgt[sz1].p = max(jgt[sz1].p,getsize_p(type));
                jgt[sz1].id[i] = make_pair(type,nm);
                jgt[sz1].stp[i] = nxttimes(jgt[sz1].tot,getsize_p(type));
                jgt[sz1].tot = jgt[sz1].stp[i] + getsize_t(type);
            }
            jgt[sz1].tot = nxttimes(jgt[sz1].tot,jgt[sz1].p);
            Ps[name] = jgt[sz1].p;
            TOTs[name] = jgt[sz1].tot;
            cout << jgt[sz1].tot << " " << jgt[sz1].p << endl;
        }
        if(op == 2)
        {
            cin >> type >> name;
            nxt = nxttimes(nxt,getsize_p(type));
            cout << nxt << endl;
            ys[++sz2] = (item){make_pair(type,name),nxt};
            ADDs[name] = nxt;
            TYPs[name] = type;
            nxt += getsize_t(type);
        }
        if(op == 3)
        {
            long long tmp,otmp,rtp;
            cin >> name;
            for(tmp = 0;tmp <= name.size();tmp++) if(name[tmp] == '.') break;
            long long addr = ADDs[name.substr(0,tmp)];
            string tp = TYPs[name.substr(0,tmp)];
            tmp++; otmp = tmp;
            for(;tmp <= name.size();tmp++)
            {
                if(name[tmp] == '.' || tmp == name.size())
                {
                    string now = name.substr(otmp,tmp-otmp);
                    rtp = eman[tp];
                    for(int j = 1;j <= jgt[rtp].sum;j++)
                    {
                        if(jgt[rtp].id[j].second == now)
                        {
                            addr += jgt[rtp].stp[j];
                            tp = jgt[rtp].id[j].first;
                            break;
                        }
                    }
                    otmp = tmp+1;
                }
            }
            cout << addr << endl;
        }
        if(op == 4)
        {
            cin >> k;
            if(k >= nxt)
            {
                cout << "ERR" << endl;
                continue;
            }
            int tmp;
            for(tmp = 1;tmp <= sz2;tmp++) if(ys[tmp].add > k) break;
            tmp--;
            ans = ys[tmp].id.second;
            k -= ys[tmp].add;
            query(ys[tmp].id.first,k);
            cout << ans << endl;
        }
    }
    return 0;
}
