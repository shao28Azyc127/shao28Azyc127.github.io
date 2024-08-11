#include <bits/stdc++.h>
using namespace std;
int n,cnt = 4;
long long space;
int s[110];
int memory[110];
map <string,int> mp;
map <string,int> mp1;
map <string,string> mp2;
struct node
{
    string name;
    int start;
};
vector <node> v;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    mp["byte"] = 1,mp["short"] = 2,mp["int"] = 3,mp["long"] = 4;
    s[1] = 1,s[2] = 2,s[3] = 4,s[4] = 8;
    for(int _ = 1;_ <= n;_++)
    {
        int op;
        scanf("%d",&op);
        if(op == 1) continue;
        if(op == 2)
        {
            string opt,name;
            cin >> opt >> name;
            mp2[name] = opt;
            int pre = space;
            space = ceil(1.0 * space / s[mp[opt]]) + s[mp[opt]];
            mp1[name] = pre;
            v.push_back({name,pre});
        }
        else if(op == 3)
        {
            string s;
            cin >> s;
            cout << mp1[s] << "\n";
        }
        else
        {
            bool flag = false;
            int x;
            cin >> x;
            for(int i = 0;i < v.size();++i)
            {
                node nd = v[i];
                if(nd.start + s[mp[mp2[nd.name]]] >= x)
                {
                    if(nd.start > x) printf("ERR\n");
                    else cout << nd.name << "\n";
                    flag = true;
                    break;
                }
            }
            if(!flag) printf("ERR\n");
        }
    }
    return 0;
}
/*
6
2 int x
2 short y
2 long w
3 x
4 10
4 20
*/
