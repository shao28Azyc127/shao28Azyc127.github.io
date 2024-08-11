#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
void read(T &a)
{
    char ch;
    bool flag = a = 0;
    for(; ch<'0'||ch>'9'; ch=getchar()) if(ch=='-') flag = true;
    for(; ch>='0'&&ch<='9'; a=a*10+ch-'0',ch=getchar());
    if(flag) a*=-1;
}

struct CCFstruct
{
    ll addrDelta;
    ll size1;
    unordered_map<string, pair<ll, string> > members;
    unordered_map<ll, string> storaged;

};

ll nowaddr = 0;
unordered_map<string, CCFstruct> structs;
unordered_map<string, pair<ll, pair<string, string> > > vars;
unordered_map<ll, string> storaged;

string dfs(CCFstruct s, ll addr)
{
    for(ll i=addr;i>=0;i--) {
        if(s.members[s.storaged[i]].first == i) {
            if(s.members[s.storaged[i]].second == "byte" || "short" || "int" || "long") {
                return "." + s.storaged[i];
            }
            else {
                string res = dfs(structs[s.members[s.storaged[i]].second], addr-i);
                return res == "ERR" ? "ERR" : res;
            }
        }
    }
    return "ERR";
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    structs["byte"] = {1, 1, unordered_map<string, pair<ll, string> >(), unordered_map<ll, string>()};
    structs["short"] = {2, 2, unordered_map<string, pair<ll, string> >(), unordered_map<ll, string>()};
    structs["int"] = {4, 4, unordered_map<string, pair<ll, string> >(), unordered_map<ll, string>()};
    structs["long"] = {8, 8, unordered_map<string, pair<ll, string> >(), unordered_map<ll, string>()};
    int T;
    read(T);
    while(T--)
    {
        int op;
        read(op);
        if(op == 1)
        {
            ll now = 0;
            string s;
            ll k;
            cin>>s;
            structs[s] = {0, 0, unordered_map<string, pair<ll, string> >(), unordered_map<ll, string>()};
            read(k);
            for(int i=1; i<=k; i++)
            {
                string t;
                string n;
                cin>>t>>n;
                structs[s].members[n].second = t;
                structs[s].addrDelta = max(structs[s].addrDelta, structs[t].addrDelta);
                if(now%structs[t].addrDelta)
                {
                    now = now / structs[t].addrDelta * structs[t].addrDelta + structs[t].addrDelta;
                }
                structs[s].members[n].first = now;
                structs[s].storaged[now] = n;
                structs[s].size1 = now + structs[t].size1;
                now = structs[s].size1;
            }
            printf("%lld %lld\n", structs[s].size1, structs[s].addrDelta);
        }
        else if(op == 2)
        {
            string t, n;
            cin>>t>>n;
            ll addrGot;
            addrGot = nowaddr + (structs[t].addrDelta - nowaddr % structs[t].addrDelta) * ((nowaddr % structs[t].addrDelta) ? 1 : 0);
            nowaddr = nowaddr + structs[t].size1 + (structs[t].addrDelta - nowaddr % structs[t].addrDelta) * ((nowaddr % structs[t].addrDelta) ? 1 : 0);
            vars[n].first = addrGot;
            vars[n].second.first = t;
            vars[n].second.second = n;
            storaged[addrGot] = t;
            printf("%lld\n", addrGot);
        }
        else if(op == 3)
        {
            string n, now = "", nowfa = "";
            cin>>n;
            ll l = n.length();
            ll result = 0;
            for(int i=0; i<l; i++)
            {
                if(n[i] == '.')
                {
                    if(nowfa == "")
                    {
                        result = vars[now].first;
                        nowfa = vars[now].second.first;
                    }
                    else
                    {
                        result += structs[nowfa].members[now].first;
                        nowfa = structs[nowfa].members[now].second;
                    }

                    now = "";
                }
                else now += n[i];
            }
            result += structs[nowfa].members[now].first;
            nowfa = structs[nowfa].members[now].second;
            printf("%lld\n", result);
        }
        else
        {
            ll addr;
            read(addr);
            puts("ERR");
        }
    }
    return 0;
}

