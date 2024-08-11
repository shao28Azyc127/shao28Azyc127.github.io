#include<bits/stdc++.h>
using namespace std;

int n, vs = 0;
long long lstad = -1;
struct type_name {
    string type, name;
};
struct address {
    int v;
    type_name x;
    long long l, r;
};

map<string, long long> l;
vector<address> tree[10005];//地址树
map<string, vector<type_name> > str;//存结构体
map<long long, string> add;//存地质对应的元素
//map<type_name, address> valu;//存元素对应的地质
vector<type_name> v;
void update(int v, string t, string na, int left)
{
    tree[v].push_back((address){++vs, (type_name){t, na}, left, left + l[t] - 1});
    if(t == "int" || t == "long" || t == "byte" || t == "short")
    {
        for(long long i = lstad + 1; i <= lstad + l[t]; i++)
        {
            if(add[i] != "")    add[i] += '.';
            add[i] += na;
        }
    }
    else
    {
        for(int i = 0; i < str[t].size(); i++)
        {
            string tt = str[t][i].type, nana = str[t][i].name;
            if(tt == "int" || tt == "long" || tt == "byte" || tt == "short")
                tree[vs].push_back((address){++vs, str[t][i], lstad + 1, lstad + l[t]});
            else    update(vs, tt, nana, left);
            lstad += l[tt];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    l["int"] = 4, l["long"] = 8, l["byte"] = 1, l["short"] = 2;
    while(n--)
    {
        int op;
        cin >> op;
        string t, na;
        if(op == 1)
        {
            string s;int k;
            cin >> s >> k;
            v.clear();
            for(int i = 1; i <= k; i++) cin >> t >> na, v.push_back((type_name{t, na})), l[s] = max(l[s], l[t]);
            str[s] = v;
            //for(int i = 0; i < str[s].size(); i++)  cout << str[s][i].type << " " << str[s][i].name << endl;
            //cout << l[s] << endl;
        }
        else if(op == 2)
        {
            cin >> t >> na;
            update(0, t, na, lstad + 1);
        }
        else if(op == 3)
        {
            string s, nam, lst;
            int start, root = 0;
            cin >> s;
            int l = s.size();s = '#' + s;
            for(int i = 1; i <= l; i++)
            {
                while(1)
                {
                    if(s[i] == '.' || i > l) break;
                    nam += s[i], i++;
                }
                for(int i = root; i < tree[root].size(); i++)
                {
                    string tt = tree[root][i].x.type;
                    if(tree[root][i].x.name == nam)
                    {
                        root = tree[root][i].v;
                        if(i == l)  cout << tree[root][i].l << endl;
                        break;
                    }
                }
            }
        }
        else
        {
            long long addr;
            cin >> addr;
            if(add[addr] == "") cout << "ERR" << endl;
            else    cout << add[addr] << endl;
        }
    }
    /*for(int j = 0; j <= 5; j++)
    {
        for(int i = j; i < tree[j].size(); i++)
            cout << tree[j][i].v << " "<< tree[j][i].x.type << " " << tree[j][i].x.name <<" "<< tree[j][i].l << " "<< tree[j][i].r << endl;
        cout << endl;
    }*/
    return 0;
}
