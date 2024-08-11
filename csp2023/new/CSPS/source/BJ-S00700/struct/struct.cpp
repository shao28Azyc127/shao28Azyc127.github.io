#include <iostream>
#include <vector>
#include <map>
using namespace std;
long long n, op, k, addr;
string s, t, name;
struct Object
{
    Struct *type;
    string name;
    long long s = 0, a = 0, o = 0;
} global;
struct Struct
{
    string name;
    vector<Object *> ob;
    map<string, Object *> os;
    long long s = 0, a = 0;
} Global;
map<string, Struct *> ss;
int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    ss["byte"] = {"byte", {}, {}, 1, 1};
    ss["short"] = {"short", {}, {}, 2, 2};
    ss["int"] = {"int", {}, {}, 4, 4};
    ss["long"] = {"long", {}, {}, 8, 8};
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> s >> k;
            static Struct st;
            st.name = s;
            ss[s] = &st;
            for (int i = 1; i <= k; i++)
            {
                static Object ob;
                st.ob.push_back(&ob);
                cin >> t;
                ob.type = ss[t];
                cin >> ob.name;
                st.os[ob.name] = &ob;
                ob.s = ob.type->s;
                ob.a = ob.type->a;
                ob.o = (st.s + ob.a - 1) / ob.a * ob.a;
                st.a = max(st.a, ob.a);
                st.s = ob.o + ob.s;
            }
            cout << st.s << " " << st.a << endl;
            break;
        case 2:
            static Object ob;
            Global.ob.push_back(&ob);
            cin >> t;
            ob.type = ss[t];
            cin >> ob.name;
            Global.os[ob.name] = &ob;
            ob.s = ob.type->s;
            ob.a = ob.type->a;
            ob.o = (Global.s + ob.a - 1) / ob.a * ob.a;
            Global.a = max(Global.a, ob.a);
            Global.s = ob.o + ob.s;
            cout << ob.o << endl;
            break;
        case 3:
            Object *now = global;
            cin >> s;
            s += ".";
            name = "";
            addr = 0;
            for (char c : s)
            {
                if (c == '.')
                {
                    now = now->type->os[name];
                    name = "";
                    addr += now->o;
                }
                else
                    name += c;
            }
            cout << addr << endl;
            break;
        case 4:
            Object *now = global;
            cin >> addr;

            cout << "ERR" << endl;
        }
    }
    return 0;
}
