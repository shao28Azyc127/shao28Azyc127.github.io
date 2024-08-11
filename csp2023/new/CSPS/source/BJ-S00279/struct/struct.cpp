#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

map<ll,string> mp;
map<string,ll> pm;
struct node
{
    int m;//结构体内成员数量
    string type[110],name[110];
    int maxp = 0,mem = 0;//对齐和所占内存
    string nm;
}a[10010];
int aa = 0;

map<string,ll> nm;

ll n,pos = 0;

void makedir(int aa,string nam)
{
    for(int i = 1;i <= a[aa].m;i++)
    {
        if(a[aa].type[i] == "long")
        {
            for(int j = 0;j < 8;j++)
                mp[pos + j] = nam + "." + a[aa].name[i];
            pm[nam + "." + a[aa].name[i]] = pos;
            pos += 8;
        }
        else if(a[aa].type[i] == "int")
        {
            for(int j = 0;j < 4;j++)
                mp[pos + j] = nam + "." +  a[aa].name[i];
            pm[nam + "." + a[aa].name[i]] = pos;
            for(int j = 4;j < a[aa].maxp;j++)
                mp[pos + j] = "0";
            pos += a[aa].maxp;
        }
        else if(a[aa].type[i] == "short")
        {
            for(int j = 0;j < 2;j++)
                mp[pos + j] = nam + "." + a[aa].name[i];
            pm[nam + "." + a[aa].name[i]] = pos;
            for(int j = 2;j < a[aa].maxp;j++)
                mp[pos + j] = "0";
            pos += a[aa].maxp;
        }
        else if(a[aa].type[i] == "byte")
        {
            for(int j = 0;j < 1;j++)
                mp[pos + j] = nam + "." + a[aa].name[i];
            pm[nam + "." + a[aa].name[i]] = pos;
            for(int j = 1;j < a[aa].maxp;j++)
                mp[pos + j] = "0";
            pos += a[aa].maxp;
        }
        else
        {
            string dirr = "." + a[aa].name[i];
            makedir(nm[ a[aa].type[i]],nam + dirr);
        }
    }
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    while(n--)
    {
        int op;
        string ans = "";
        cin >> op;
        if(op == 1)
        {
            aa++;
            string s;
            int m,memm = 0;
            cin >> s >> m;
            nm[s] = aa;
            a[aa].m = m;
            a[aa].nm = s;
            for(int i = 1;i <= m;i++)
            {
                cin >> a[aa].type[i] >> a[aa].name[i];
                if(a[aa].type[i] == "long")
                {
                    a[aa].maxp = max(8,a[aa].maxp);
                }
                else if(a[aa].type[i] == "int")
                {
                    a[aa].maxp = max(4,a[aa].maxp);
                }
                else if(a[aa].type[i] == "short")
                {
                    a[aa].maxp = max(2,a[aa].maxp);
                }
                else if(a[aa].type[i] == "byte")
                {
                    a[aa].maxp = max(1,a[aa].maxp);
                }
                else
                {
                    a[aa].maxp = max(a[aa].maxp,a[ nm[ a[aa].type[i] ] ].maxp);
                    a[aa].mem += a[ nm[ a[aa].type[i] ] ].mem;
                    memm++;
                }
            }
            a[aa].mem += a[aa].maxp * (a[aa].m - memm);
            cout << a[aa].mem << ' ' << a[aa].maxp << endl;
        }
        if(op == 2)
        {
            string typ,nam;
            cin >> typ >> nam;
            cout << pos <<endl;
            if(typ == "long")
            {
                for(int j = 0;j < 8;j++)
                    mp[pos + j] = nam;
                pos += 8;
            }
            else if(typ  == "int")
            {
                for(int j = 0;j < 4;j++)
                    mp[pos + j] = nam;
                pos += 4;
            }
            else if(typ  == "short")
            {
                for(int j = 0;j < 2;j++)
                    mp[pos + j] = nam;
                pos += 2;
            }
            else if(typ  == "byte")
            {
                for(int j = 0;j < 1;j++)
                    mp[pos + j] = nam;
                pos ++;
            }
            else
            {
                makedir(nm[typ],nam);
            }
        }
        if(op == 3)
        {
            string s;
            cin >> s;
            cout << pm[s] << endl;

        }
        if(op == 4)
        {
            int x;
            cin >> x;
            if(mp[x] == "0")
            {
                cout << "ERR\n";
            }
            else cout << mp[x] << endl;
        }
    }
    return 0;
}
