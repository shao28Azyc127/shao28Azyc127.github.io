#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

// TODO: long long
// type=1,2,4,8

inline long long ceild(long long x, long long y)
{
    if(y == 0)  return 0;
    return (x + y - 1) / y, 1ll * y;
}

struct S;
map <string, S> types;

struct S
{
    long long duiqi, siz;
    // a - name, d - abs address
    vector <string> a, t;
    vector <long long> dl, dr;
    string name;

    void add(string name, string type)
    {
        a.push_back(name);
        t.push_back(type);
        dl.push_back(0);
        dr.push_back(0);
        duiqi = max(duiqi, types[type].duiqi);
    }
    void calc()
    {
        dr[0] = types[t[0]].siz;
        for(int i = 1; i < a.size(); i++)
        {
            dl[i] = ceild(dl[i - 1] + types[t[i - 1]].siz, types[t[i - 1]].duiqi);
            dr[i] = dl[i] + types[t[i]].siz;
        }
        siz = ceild(dr[a.size() - 1], duiqi);
    }
    string get_name(long long addr)
    {
        if(name == "")  return "";
        for(int i = 0; i < a.size(); i++)
        {
            if(addr >= dl[i] && addr < dr[i])
            {
                string ret = types[t[i]].get_name(addr - dl[i]);
                if(ret == "ERR")  return "ERR";
                else if(ret == "")  return name;
                else  return name + "." + ret;
            }
            if(addr >= dr[i])  break;
        }
        return "ERR";
    }
    long long get_addr(string name, long long addr_base)
    {
        if(name == "")  return addr_base;

        int cur = name.find(".");
        string now_name = name.substr(0, cur);
        string next_name = name.substr(cur + 1, name.length());

        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] == now_name)
            {
                return types[t[i]].get_addr(next_name, addr_base + dl[i]);
            }
        }
    }
};
S mem[205];

int n, op, k, cur;
long long x, y, d[205];
string s, t, eee;

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    types["byte"].siz = types["byte"].duiqi = 1;
    types["short"].siz = types["short"].duiqi = 2;
    types["int"].siz = types["int"].duiqi = 4;
    types["long"].siz = types["long"].duiqi = 8;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &op);
        if(op == 1)
        {
            cin >> s;
            scanf("%d", &k);
            for(int j = 1; j <= k; j++)
            {
                cin >> t >> eee;
                types[s].add(eee, t);
            }
            types[s].calc();
            printf("%lld %lld\n", types[s].siz, types[s].duiqi);
        }
        else if(op == 2)
        {
            cin >> t >> s;
            cur++;
            d[cur] = ceild(d[cur - 1] + mem[cur - 1].siz, types[t].duiqi);
            mem[cur] = types[t];
            mem[cur].name = s;
            printf("%lld\n", d[cur]);
        }
        else if(op == 3)
        {
            cin >> s;
            s += ".";
            int cur = s.find(".");
            string now_name = s.substr(0, cur);
            string next_name = s.substr(cur + 1, s.length());
            for(int i = 1; i <= cur; i++)
            {
                if(mem[i].name == now_name)
                {
                    cout << mem[i].get_addr(next_name, d[i]) << endl;
                    break;
                }
            }
        }
        else if(op == 4)
        {
            scanf("%lld", &x);
            bool flag = false;
            for(int i = 1; i <= cur; i++)
            {
                if(x >= d[i] && x < d[i] + mem[i].siz)
                {
                    cout << mem[i].get_name(x - d[i]) << endl;
                    flag = true;
                    break;
                }
                if(x >= d[i] + mem[i].siz)  break;
            }
            if(!flag)  cout << "ERR" << endl;
        }
    }
    return 0;
}
