#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

struct Type
{
    string type[101];
    int st[101];
    int sz[101];
    int maxn;
};

struct Document
{
    string type;
    int st, sz;
};

map <string, Document> d;
map <string, Type> tp;
string du[110];
int Cur = 0;

int fnd(string name, int dis)
{
    int cur = 0;
    while (tp[name].type[++cur] != "")
    {
        if (tp[name].st[cur] <= dis && tp[name].st[cur] + tp[name].sz[cur] - 1 >= dis)
        {
            if (name == "abyte" || name == "ashort" || name == "aint" || name == "along") return tp[tp[name].type[cur]].st[0];
            else return tp[tp[name].type[cur]].st[0] + fnd(tp[name].type[cur], dis - tp[name].st[cur]);
        }
    }
    return -1000000000;
}

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    tp["abyte"].sz[0] = tp["abyte"].maxn = 1;
    tp["ashort"].sz[0] = tp["ashort"].maxn = 2;
    tp["aint"].sz[0] = tp["aint"].maxn = 4;
    tp["along"].sz[0] = tp["along"].maxn = 8;
    int n, cur = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string name;
            name = "a" + name;
            int k, CUR = 0;
            cin >> name >> k;
            for (int j = 1; j <= k; j++)
            {
                cin >> tp[name].type[j] >> tp[name].name[j];
                tp[name].name[j] = "a" + tp[name].name[j];
                int sz = tp[tp[name].type[j]].sz[0];
                tp[name].sz[j] = sz;
                CUR = (CUR + sz - 1) / sz * sz;
                tp[name].st[j] = CUR;
                CUR += sz;
                tp[name].maxn = max(tp[name].maxn, tp[tp[name].type[j]].maxn);
                {/*if (tp[name].type[j] == "byte")
                {
                    d[cur].st = sum;
                    sum++;
                    d[cur].sz = 1;
                    d[cur].maxn = 1;
                }
                else if (tp[name].type[j] == "short")
                {
                    sum = (sum + 1) / 2 * 2;
                    d[cur].st = sum;
                    sum += 2;
                    d[cur].sz = 2;
                    d[cur].maxn = 2;
                }
                else if (tp[name].type[j] == "int")
                {
                    sum = (sum + 3) / 4 * 4;
                    d[cur].st = sum;
                    sum += 4;
                    d[cur].sz = 4;
                    d[cur].maxn = 4;
                }
                else
                {
                    sum = (sum + 7) / 8 * 8;
                    d[cur].st = sum;
                    sum += 8;
                    d[cur].sz = 8;
                    d[cur].maxn = 8;
                }
                d[now].cur++;
                d[now].p[d[now].cur] = cur;
                d[now].pname[d[now].cur] = d[cur].name;
                d[now].maxn = max(d[now].maxn, d[cur].sz);*/}
            }
            tp[name].sz[0] = (CUR + maxn - 1) / maxn * maxn;
        }
        if (op == 2)
        {
            string type, name;
            cin >> type >> name;
            du[++Cur] = name;
            d[name].type = type;
            d[name].sz = tp[type].sz[0];
            //d[name].maxn = tp[type].maxn;
            sum = (sum + d[name].sz - 1) / d[name].sz * d[name].sz;
            d[name].st = sum;
            sum += d[name].sz;
        }
        if (op == 3)
        {
            string s, sub;
            int fd = 0;
            cin >> s;
            s = s + ".";
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != '.')
                {
                    sub = sub + s[i];
                }
                if (s[i] == '.')
                {
                    if (fd == 0) fd = d[sub].st;
                    else fd = fd + tp[sub].st[0];
                }
            }
            cout << fd << endl;
        }
        if (op == 4)
        {
            int addr;
            cin >> addr;
            for (int j = 1; j <= Cur; j++)
            {
                if (d[du[j]].st <= addr && d[du[j]].st + d[du[j]].sz - 1 >= addr)
                {
                    int ans =  d[du[j]].st + fnd(du[j], addr - d[du[j]].st);
                }
            }
        }
    }
    return 0;
}