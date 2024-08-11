#include <bits/stdc++.h>
using namespace std;


struct Node
{
    string name;
    long long daxiao;
    int yaoqiu;
    string names[105];
    long long yl[105];
    long long yr[105];
    int yyaoqiu[105];
    int yy[105];
    string types[105];
};
struct YS
{
    string type;
    string name;
    long long sl,sr;
};
Node alls[105];
YS dy[105];
int mdy;
int m;
int n;
long long nowp;
int findnames(string s)
{
    if(s == "byte") return 1;
    if(s == "short") return 2;
    if(s == "int") return 4;
    if(s == "long") return 8;
    for(int i = 1;i <= n;i++)
        if(s == alls[i].name) return -alls[i].yaoqiu;
    return 0;
}
void op1()
{
    string s; int k;
    cin >> s >> k;
    Node a; a.name = s;
    int maxny = 0;
    for(int T = 1;T <= k;T++)
    {
        string t,n; cin >> t >> n;
        a.names[T] = n;
        a.types[T] = t;
        int c = findnames(t);
        if(c < 0)
        {
            c = -c;
            maxny = max(maxny,c);
            for(int i = 1;i <= m;i++)
                if(t == alls[i].name) a.yy[T] = alls[i].daxiao;
            a.yyaoqiu[T] = c;
            continue;
        }
        maxny = max(maxny,c);
        a.yy[T] = c;
        a.yyaoqiu[T] = c;
    }
    a.yaoqiu = maxny;
    long long t = 0;
    for(int T = 1;T <= k;T++)
    {
        while(t % (long long)(a.yyaoqiu[T]) != 0) t++;
        a.yl[T] = t;
        a.yr[T] = (long long)(t + (long long)(a.yy[T]) - 1);
        t += (long long)(a.yy[T]); 
    }
    while(t % (long long)(a.yaoqiu) != 0) t++;
    a.daxiao = t;
    m++;
    alls[m] = a;
    cout << a.daxiao << " " << a.yaoqiu << endl;
}

void op2()
{
    string t,n;
    cin >> t >> n;
    mdy++;
    dy[mdy].name = n;
    dy[mdy].type = t;
    int c = findnames(t);
    int dx = 0,yq = 0;
    if(c < 0)
    {
        for(int i = 1;i <= m;i++)
            if(t == alls[i].name)
            {
                dx = alls[i].daxiao;
                yq = alls[i].yaoqiu;
            }
    }
    long long k = nowp;
    while(k % yq != 0) k++;
    dy[mdy].sl = k;
    dy[mdy].sr = k+dx-1;
    nowp = k + dx;
    cout << dy[mdy].sl << endl;
}

long long findop3(string s,int T,int p)
{
    int len = 0;
    string name; int t = T;
    for(t;s[t] != '.' && t < s.length();t++) name += s[t];
    t++;
    int i;
    for(i = 1;i <= 100;i++)
    {
        if(alls[p].yl[i] == 0 && i != 1) break;
        alls[p].names[i] == name;
        int c = findnames(alls[p].types[i]);
        if(c > 0) return alls[p].yl[i];
        else
        {
            int j;
            for(j = 1;j <= m;j++)
                if(alls[j].name == alls[p].types[i])
                    break;
            return alls[p].yl[i] + findop3(s,t,j);
        }
    }  
    return 0;
}
void op3()
{
    string s; cin >> s;
    int t = 0;
    int startp = 0;
    string name;
    for(t;s[t] != '.' && t < s.length();t++) name += s[t];
    t++;
    int i;
    for(i = 1;i <= mdy;i++)
        if(dy[i].name == name)
        {
            startp = dy[i].sl;
            break;
        }
    string type = dy[i].type;
    int c = findnames(type);
    if(c > 0) cout << startp << endl;
    else
    {
        int j;
        for(j = 1;j <= m;j++)
            if(alls[j].name == type)
                    break;
        cout << startp + findop3(s,t,j);
    }
}
void op4()
{
    long long addr;
    cin >> addr;
    cout << "ERR" << endl;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    for(int T = 1;T <= n;T++)
    {
        int op; cin >> op;
        if(op == 1) op1();
        else if(op == 2) op2();
        else if(op == 3) op3();
        else op4();
    }



    return 0;
}