#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
struct Struct
{
    string name;
    int k,mem,len;
    string t[110],n[110];
};
map<string,Struct> st;
map<string,string> memory;
map<string,int> ele;
struct Elements{string name,str;};
map<long long,Elements> memo;
long long ans;
string anss;
void dfs1(int pos,string s,int data)
{
    cout << pos << "," << data << "\n";
    if (pos >= s.length())
    {
        ans = data;
        return;
    }
    string name = "";
    while(pos < s.length() && s[pos] != '.')
    {
        name += s[pos];
        pos++;
    }
    dfs1(pos + 1,s,data + st[memory[name]].len);
}
void dfs2(int addr,string s,string str,int data)
{
    int i = 1;
    while(i < st[str].k && data < addr)
        data += st[st[str].t[i++]].len;
    if (data < addr)
    {
        anss = "ERR";
        return;
    }
    data -= st[st[str].t[i]].len;
    i--;
    if (st[str].k == 0)
    {
        anss = s;
        return;
    }
    s += ".";
    s += st[str].n[i];
    dfs2(addr,s,st[str].t[i],data);
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int T,n1 = 0;
    long long data = 0;
    scanf("%d",&T);
    st["byte"] = {"byte",0,1,1,{},{}};
    st["short"] = {"short",0,2,2,{},{}};
    st["int"] = {"int",0,4,4,{},{}};
    st["long"] = {"long",0,8,8,{},{}};
    while(T--)
    {
        int op;
        scanf("%d",&op);
        if (op == 1)
        {
            string name;
            cin >> name >> st[name].k;
            st[name].name = name;
            for (int i = 1;i <= st[name].k;i++)
            {
                cin >> st[name].t[i] >> st[name].n[i];
                memory[st[name].n[i]] = st[name].t[i];
                st[name].mem = max(st[name].mem,st[st[name].t[i]].mem);
                st[name].len += st[st[name].t[i]].len;
            }
            st[name].len = (st[name].len / st[name].mem + (st[name].len % st[name].mem > 0 ? 1 : 0)) * st[name].mem;
            printf("%d %d\n",st[name].len,st[name].mem);
        }
        if (op == 2)
        {
            string str,name;
            cin >> str >> name;
            ele[name] = data;
            memo[data] = {name,str};
            data += st[str].len;
            printf("%lld\n",ele[name]);
        }
        if (op == 3)
        {
            string s;
            cin >> s;
            int pos = 0;
            string name = "";
            while(pos < s.length() && s[pos] != '.')
            {
                name += s[pos];
                pos++;
            }
            ans = 0;
            dfs1(pos + 1,s,ele[name]);
            printf("%lld\n",ans);
        }
        if (op == 4)
        {
            int addr;
            scanf("%d",&addr);
            int x = addr;
            while(!memo.count(x)) x--;
            anss = memo[x].name;
            dfs2(addr,anss,memo[x].str,x);
            cout << anss << endl;
        }
    }
    return 0;
}
