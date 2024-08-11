#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int NR = 1e3 + 5;

map<string, int> nametostruct;
vector<pair<string, string>> structtocreate[NR];
int lenofstruct[NR];
int structnum = 0;
map<string, long long> nametoaddr;
map<long long, string> addrtoname;
long long addr_end;

void create(string type, string name, int setlen = 0)
{
    nametoaddr[name] = addr_end;
    addrtoname[addr_end] = name;
    if (setlen != 0)
        addr_end += setlen;
    else if (type == "bype")
        addr_end += 1;
    else if (type == "short")
        addr_end += 2;
    else if (type == "int")
        addr_end += 4;
    else if (type == "long")
        addr_end += 8;
    else
    {
        int t = addr_end;
        auto it = nametostruct.find(type);
        if (it == nametostruct.end())
            return;
        for (auto p = structtocreate[it->second].begin();p != structtocreate[it->second].end();p ++)
            create(p->first, name + "." + p->second, lenofstruct[it->second]);
        t = addr_end - t;
    }
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    int n;
    int op;
    string s, s1, s2;
    int ttt;
    long long taddr;

    cin >> n;
    while (n --)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> s >> ttt;
            nametostruct[s] = structnum;
            structnum ++;
            for (int i = 1;i <= ttt;i ++)
            {
                cin >> s1 >> s2;
                structtocreate[structnum - 1].push_back({s1, s2});
                if (s1 == "byte")
                    lenofstruct[structnum - 1] = max(lenofstruct[structnum - 1], 1);
                else if (s1 == "short")
                    lenofstruct[structnum - 1] = max(lenofstruct[structnum - 1], 2);
                else if (s1 == "int")
                    lenofstruct[structnum - 1] = max(lenofstruct[structnum - 1], 4);
                else if (s1 == "long")
                    lenofstruct[structnum - 1] = max(lenofstruct[structnum - 1], 8);
                else
                    lenofstruct[structnum - 1] = max(lenofstruct[structnum - 1], lenofstruct[nametostruct[s1]]);
            }
            cout << ttt * lenofstruct[structnum - 1] << ' ' << lenofstruct[structnum - 1] << '\n';
        }
        else if (op == 2)
        {
            cin >> s1 >> s2;
            cout << addr_end << '\n';
            create(s1, s2);
        }
        else if (op == 3)
        {
            cin >> s;
            cout << nametoaddr[s] << '\n';
        }
        else if (op == 4)
        {
            cin >> taddr;
            auto it = addrtoname.find(taddr);
            if (it == addrtoname.end())
                cout << "ERR\n";
            else
                cout << it->second << '\n';
        }
    }
    return 0;
}
