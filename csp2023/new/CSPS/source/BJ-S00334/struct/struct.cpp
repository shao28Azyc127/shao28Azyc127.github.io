#include <bits/stdc++.h>
using namespace std;

struct node
{
    int tab;
    vector<pair<string, string>> sub;
};

map<string, node> tps;
map<string, int> pos;
vector<string> mem;
int cur;

int gettab(string type)
{
    if(type == "byte")
    {
        return 1;
    }
    if(type == "short")
    {
        return 2;
    }
    if(type == "int")
    {
        return 4;
    }
    if(type == "long")
    {
        return 8;
    }
    return tps[type].tab;
}

int size(string type)
{
    if(type == "byte" || type == "short" || type == "int" || type == "long")
    {
        return gettab(type);
    }
    else
    {
        int res = 0;
        for(pair<string, string> i : tps[type].sub)
        {
            if(res != 0)
            {
                res = (res + gettab(i.first) - 1) / gettab(i.first) * gettab(i.first);
            }
            res += size(i.first);
        }
        res = (res + gettab(type) - 1) / gettab(type) * gettab(type);
        return res;
    }
}

void make(string type, string var)
{
    if(type == "byte" || type == "short" || type == "int" || type == "long")
    {
        pos[var] = cur;
        int add = gettab(type);
        cur += add;
        for(int i = 1;i <= add;i++)
        {
            mem.push_back(var);
        }
    }
    else
    {
        bool chk = false;
        for(pair<string, string> i : tps[type].sub)
        {
            if(chk)
            {
                cur = (cur + gettab(i.first) - 1) / gettab(i.first) * gettab(i.first);
                mem.resize(cur, "ERR");
            }
            chk = true;
            make(i.first, var + "." + i.second);
        }
        cur = (cur + gettab(type) - 1) / gettab(type) * gettab(type);
        mem.resize(cur, "ERR");
    }
}

int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	int n;
	scanf("%d", &n);
    while(n--)
    {
        int op;
        scanf("%d", &op);
        if(op == 1)
        {
            string name;
            int x;
            cin >> name;
            scanf("%d", &x);
            node tpnew = {};
            while(x--)
            {
                string type, var;
                cin >> type >> var;
                tpnew.sub.push_back(make_pair(type, var));
                tpnew.tab = max(tpnew.tab, gettab(type));
            }
            tps[name] = tpnew;
            printf("%d %d\n", size(name), tpnew.tab);
        }
        else if(op == 2)
        {
            string type, var;
            cin >> type >> var;
            printf("%d\n", cur);
            make(type, var);
        }
        else if(op == 3)
        {
            string name;
            cin >> name;
            printf("%d\n", pos[name]);
        }
        else
        {
            int pos;
            scanf("%d", &pos);
            if(pos >= cur)
            {
                printf("ERR\n");
            }
            else
            {
                cout << mem[pos] << "\n";
            }
        }
    }
	return 0;
}
