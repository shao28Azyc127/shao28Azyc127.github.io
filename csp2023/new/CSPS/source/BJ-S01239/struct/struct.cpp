#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
struct Struct
{
    string name;
    string contains[110], names[110];
    int l[110], r[110];
    int cnt;
    int sz, stan;
};
vector <Struct> s;
Struct finder (string name)
{
    for (auto x : s) if (x.name == name) return x;
}
void print()
{
    for (auto st : s)
    {
        cout << "name: " << st.name << endl << "contains: ";
        for (int i = 1; i <= st.cnt; i++) cout << st.contains[i] << " " << st.names[i] << endl;
        cout << "size: " << st.sz << endl << "standard: " << st.stan << endl;
    }
    return;
}
void init()
{
    Struct BYTE;
    BYTE.name = "byte", BYTE.sz = BYTE.stan = 1; BYTE.cnt = 0;
    s.push_back(BYTE);
    Struct SHORT;
    SHORT.name = "short", SHORT.sz = SHORT.stan = 2; SHORT.cnt = 0;
    s.push_back(SHORT);
    Struct INT;
    INT.name = "int", INT.sz = INT.stan = 4; INT.cnt = 0;
    s.push_back(INT);
    Struct LONG;
    LONG.name = "long", LONG.sz = LONG.stan = 8; LONG.cnt = 0;
    s.push_back(LONG);
    return;
}
int remain(int x, int y)
{
    if (x == y) return 0;
    if (x % y == 0) return 0;
    int d = x / y;
    x = x - d * y;
    int ret = y - x;
    return ret;
}
signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    Struct root;
    root.name = "root", root.sz = root.stan = 0; root.cnt = 0;
    init();
    cin >> T;
    while (T--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            Struct newstruct;
            newstruct.cnt = 0;
            newstruct.sz = 0;
            string name; int k;
            cin >> name >> k;
            newstruct.name = name;
            for (int i = 1; i <= k; i++)
            {
                string type, type_name;
                cin >> type >> type_name;
                Struct x = finder(type);
                newstruct.contains[++newstruct.cnt] = type;
                newstruct.names[newstruct.cnt] = type_name;
                newstruct.stan = max(newstruct.stan, x.stan);
                int rem = remain(newstruct.sz, x.stan);
                newstruct.sz = newstruct.sz + (rem != x.stan) * rem + x.sz;
            }
            int rem = remain(newstruct.sz, newstruct.stan);
            newstruct.sz += (rem != newstruct.stan) * rem;
            cout << newstruct.sz << " " << newstruct.stan << endl;
            s.push_back(newstruct);
            //print();
        }
        if (op == 2)
        {
            string type, type_name;
            cin >> type >> type_name;
            Struct x = finder(type);
            root.contains[++root.cnt] = type;
            root.names[root.cnt] = type_name;
            cout << root.sz << endl;
            root.sz = root.sz + x.sz;
        }
        if (op == 3)
        {
            cout << "a";
        }
        if (op == 4)
        {
            cout << "ERR";
        }
    }
    return 0;
}
