#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int MAXN = 105, MAXK = 105, MAXADDR = 80005;
int n, tot, tot1, totaddr;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') flag = 0;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
map<string, int> id;
map<string, int> occupied_id;
map<string, int> getmaxl;
struct st
{
    map<string, int> id1;
    string name;
    int k;
    int type[MAXK];
    string name1[MAXK];
    int maxl, overall, start[MAXK]; //相对起始位置
} a[MAXN];
struct occupied_st
{
    map<string, int> id1;
    string type, name;
    int k;
    int maxl, overall, start[MAXK]; //绝对起始位置
    bool is_single;
} b[MAXN];
int getmaxl(string s)
{
    if(s == "byte") return 1;
    else if(s == "short") return 2;
    else if(s == "int") return 4;
    else if(s == "long") return 8;
    else return a[id[s]].maxl;
}
bool isbasic(string s)
{
    if(s == "byte" || s == "short" || s == "int" || s == "long") return 1;
    return 0;
}
void calc(int x)
{
    int tmp = 0;
    for(int i = 1; i <= a[x].k; ++i)
    {
        tmp = max(tmp, getmaxl(name1[i]));
    }
    a[x].maxl = tmp;
    int tmpaddr = 0;
    for(int i = 1; i <= a[x].k; ++i)
    {
        if(isbasic(name1[i]))
        {
            a[x].start[i] = tmpaddr + 1;
            tmpaddr += maxl;
        }
        else //也是结构体
        {
            a[x].start[i] = tmpaddr + 1;
            tmpaddr += a[id[name1[i]].overall;
        }
    }
    a[x].overall = tmpaddr;
}
void occupy(int x, string name)
{
    int tmp = id[b[x].type];
    b[x].k = a[tmp].k;
    if(b[x].is_single)
    {
        b[x].start[1] = totaddr + 1;
        totaddr += getmaxl(b[x].type);
        modify(1, 1, maxn, start[i], totaddr, name + "." + b[x].name);
        return;
    }
    for(int i = 1; i <= a[tmp].k; ++i)
    {
        if(isbasic(a[tmp].type[i]))
        {
            b[x].start[i] = totaddr + 1;
            totaddr += getmaxl(a[tmp].type[i]);
            modify(1, 1, maxn, start[i], totaddr, name + "." + a[tmp].name1[i]);
        }
        /*else
        {
            start[i] = totaddr + 1;
            totaddr += a[id[a[tmp].type[i]]].overall;
            occupy()
        }*/
    }
}
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; ++i)
    {
        int op = read();
        if(op == 1)
        {
            ++tot;
            cin >> a[tot].name;
            a[tot].k = read();
            for(int j = 1; j <= a[tot].k; ++j)
            {
                cin >> a[tot].type[j] >> a[tot].name1[j];
                a[tot].id1[a[tot].name1[j]] = j;
            }
            calc(tot);
            id[a[tot].name] = tot;
            printf("%d %d\n", a[tot].overall, a[tot].maxl);
        }
        if(op == 2)
        {
            ++tot1;
            cin >> b[tot1].type >> b[tot1].name;
            if(isbasic(b[tot1].type)) b[tot1].is_single = 1;
            occupy(tot1, totaddr);
            occupied_id[b[tot1].name] = tot1;
            printf("%d %d\n", b[tot1].start);
        }
        if(op == 3)
        {
            cin >> s;
            int last = 0, ans = 0;
            string name0 = ".", name1; //定义.为超级根
            int tmpid;
            for(int i = 0; i < s.length(); ++i)
            {
                if(s[i] == '.')
                {
                    name1 = s.substr(last, i - last);
                    tmpid = occupied_id[name0];
                    ans += b[tmpid].start[b[tmpid].id1[name1]];
                    name0 = name1;
                }
            }
            name1 = s.substr(last, i - last);
            ans += b[occupied_id[name0]].start[b[tmpid].id1[name1]];
            printf("%d\n", ans);
        }
        if(op == 4)
        {
            int addr = read();
            cout << query(addr);
            puts("");
        }
    }
    return 0;
}
