#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//哈哈大模拟
//先不整他，看一下数据范围拿30左右就不打了
//T2炸了，先写这个的部分分

struct node//一个结构体类型
{
    string name;
    string typ[110], ele[110];///元素类型，名称
    int adr[110];//每个元素的起始地址
    int siz, ops, maxa, pos;//这个结构体占据的大小/元素个数/结构体的起始地质
}e[110];

int cnt;

map <string, int> kj;

int n, adr;

struct bruh
{
    string typ, na;
};

map <bruh, int> k;

map <int, string> di;


signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    srand(time(0) + 2327);
    cin >> n;
    kj["short"] = 2;
    kj["byte"] = 1;
    kj["int"] = 4;
    kj["long"] = 8;
    while(n--)
    {
        int op;
        cin >> op;
        if(op == 2)
        {
            string typ;
            cin >> typ;
            string na;
            cin >> na;
            if(typ == "byte")
            {
                di[adr] = na;
                kj[na] = adr;
                adr++;
            }
            if(typ == "short")
            {
                if(adr % 2 == 1)adr++;
                di[adr] = na;
                kj[na] = adr;
                di[++adr] = na;
            }
            if(typ == "int")
            {
                adr += (4 - (adr % 4)) % 4;
                kj[na] = adr;
                di[adr] = na;
                di[++adr] = na;
                di[++adr] = na;
                di[++adr] = na;
            }
            if(typ == "long")
            {
                adr += (8 - (adr % 8)) % 8;
                kj[na] = adr;
                di[adr] = na;
                di[++adr] = na;
                di[++adr] = na;
                di[++adr] = na;
                di[++adr] = na;
                di[++adr] = na;
                di[++adr] = na;
                di[++adr] = na;
            }
            adr++;
        }
        if(op == 3)
        {
            string s;
            cin >> s;
            cout << kj[s] << "\n";
        }
        if(op == 4)
        {
            string s;
            int addr = read();
            if(di[addr] != "")
            {
                cout << di[addr] << "\n";
            }
            else
            {
                cout << "ERR\n";
            }
        }
    }
    return 0;
}