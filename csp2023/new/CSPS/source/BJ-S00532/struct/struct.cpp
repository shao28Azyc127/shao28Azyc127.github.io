#include<bits/stdc++.h>
using namespace std;

const int N = 103, M = 1e6+3;
typedef vector<pair<string, string>> vps;
typedef vector<long long> vl;

struct Struct
{
    //string name;
    int sz;//memory space
    int d;
    vps v;
};

unordered_map<string, Struct> m;//type to struct
unordered_map<string, pair<string, long long>> mp;//name to type & memory

vps me;
vl pm;

void inline init()
{
    Struct s;
    s.sz = 1;
    s.d = 1;
    m["byte"] = s;
    s.sz = 2;
    s.d = 2;
    m["short"] = s;
    s.sz = 4;
    s.d = 4;
    m["int"] = s;
    s.sz = 8;
    s.d = 8;
    m["long"] = s;
}

void inline build_an_str()
{
    Struct s;
    s.d = 1;
    string name, type, name2;
    int k;
    cin >> name >> k;
    for(int i = 1; i <= k; i++)
    {
        cin >> type >> name2;
        s.v.push_back(make_pair(type, name2));
        s.d = max(s.d, m[type].d);
    }
    s.sz = s.d * s.v.size();
    m[name] = s;
    cout << s.sz << " " << s.d << endl;
}

void inline insert_an_str()
{
    string type, name;
    cin >> type >> name;
    me.push_back(make_pair(type, name));
    if(pm.empty())
    {
        cout << 0 << endl;
        mp[name] = make_pair(type, 0);
        pm.push_back(m[type].sz);
    }
    else
    {
        cout << pm.back() << endl;
        mp[name] = make_pair(type, pm.back());
        pm.push_back(pm.back() + m[type].sz);
    }
}

long long find_in_str(string type, string s)
{
    string tmp;
    bool flag = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '.')
        {
            tmp = s.substr(i+1, s.size());
            s = s.substr(0, i);
            flag = true;
            break;
        }
    }
    Struct tp = m[type];
    for(int i = 0; i < tp.v.size(); i++)
    {
        if(tp.v[i].second == s)
        {
            if(flag)
                return tp.d * i + find_in_str(tp.v[i].first, tmp);
            else
                return tp.d * i;
        }
    }
    return -1e14;
}

long long find_me(string s)
{
    string tmp;
    bool flag = false;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '.')
        {
            tmp = s.substr(i+1, s.size());
            s = s.substr(0, i);
            flag = true;
            break;
        }
    }
    //cout << s << " " << tmp << endl;
    if(flag)
        return mp[s].second + find_in_str(mp[s].first, tmp);
    else
        return mp[s].second;
}

string locate_in_str(string type, long long l)
{
    Struct tp = m[type];
    if(l >= tp.sz)
        return "ERR";
    string ans = "";
    if(tp.v.size() == 0)
        return ans;
    int p = l / tp.d;
    ans = locate_in_str(tp.v[p].first, l - p * tp.d);
    if(ans == "ERR")
        return "ERR";
    return "." + tp.v[p].second + ans;
}

string locate_me(long long l)
{
    int p = lower_bound(pm.begin(), pm.end(), l) - pm.begin();
    string ans;
    if(p == 0)
        ans = locate_in_str(me[p].first, l);
    else
        ans = locate_in_str(me[p].first, l - pm[p-1]);
    if(ans == "ERR")
        return "ERR";
    return me[p].second + ans;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    init();
    int n;
    string s;
    long long l;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
            build_an_str();
        else if(type == 2)
            insert_an_str();
        else if(type == 3)
        {
            cin >> s;
            cout << find_me(s) << endl;
        }
        else if(type == 4)
        {
            cin >> l;
            cout << locate_me(l) << endl;
        }
    }
    return 0;
}
