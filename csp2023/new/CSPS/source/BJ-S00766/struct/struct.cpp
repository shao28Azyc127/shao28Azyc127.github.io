#include <iostream>
#include <string>
#include <vector>
#include <map>

#define int long long

using namespace std;

struct Struct {
    struct Edge {
        Struct *to;
        string name;
        int delta;  //从此结构体起始地址偏移多少到这个变量
    };
    vector<Edge> members;
    int size;
    int order;  //dui qi yao qiu
} BYTE, SHORT, INT, LONG, memory;

map<string, Struct *> names;

inline void init() {
    BYTE.size = 1;
    SHORT.size = 2;
    INT.size = 4;
    LONG.size = 8;
    BYTE.order = 1;
    SHORT.order = 2;
    INT.order = 4;
    LONG.order = 8;
    names.insert({ "byte", &BYTE });
    names.insert({ "short", &SHORT });
    names.insert({ "int", &INT });
    names.insert({ "long", &LONG });
}

inline int calc(const int size, const int order) {
    if (size % order == 0)
        return size;
    return (size / order + 1) * order;
}

inline void inputStruct() {
    Struct *s = new Struct;
    s->order = 1;
    s->size = 0;
    string name;
    cin >> name;
    names.insert({ name, s });
    int k;
    cin >> k;
    while (k--) {
        string type_str;
        cin >> type_str >> name;
        //cout << type_str << endl;
        Struct *type = names.find(type_str)->second;
        const int t = calc(s->size, type->order);
        s->members.push_back({ type, name, t });
        s->size = t + type->size;
        s->order = max(s->order, type->order);
    }
    s->size = calc(s->size, s->order);
    cout << s->size << ' ' << s->order << '\n';
}

inline int getAddr() {
    string name;
    cin >> name;
    string::iterator it = name.begin();
    Struct *type = &memory;
    int sum = 0;
    while (it != name.end()) {
        string now;
        for (; it != name.end() && *it != '.'; ++it)
            now.push_back(*it);
        if (it != name.end())
            ++it;   //skip '.'
        for (Struct::Edge &i : type->members) {
            if (i.name == now) {
                type = i.to;
                sum += i.delta;
                break;
            }
        }
    }
    return sum;
}

inline void findVar() {
    int addr;
    cin >> addr;
    Struct *type = &memory;
    if (memory.members.size() == 0) {
        //memory 里啥都没有
        cout << "ERR\n";
        return;
    }
    string path = "";
    while (true) {
        if (type->members.size() == 0)
            break;
        for (vector<Struct::Edge>::iterator i = type->members.begin(); i != type->members.end(); ++i) {
            if ((i + 1) == type->members.end() || i->delta <= addr && (i + 1)->delta > addr) {
                if (i->delta + i->to->size <= addr) {
                    cout << "ERR\n";
                    return;
                }
                type = i->to;
                addr -= i->delta;
                path += i->name + '.';
                break;
            }
        }
    }
    path.pop_back();    //erase '.' at the end
    cout << path << '\n';
}

signed main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    init();
    while (n--) {
        char opt;
        cin >> opt;
        //cout << n << endl;
        if (opt == '1') {
            inputStruct();
        } else if (opt == '2') {
            string type_str, name;
            cin >> type_str >> name;
            Struct *type = names.find(type_str)->second;
            const int t = calc(memory.size, type->order);
            memory.members.push_back({ type, name, t });
            memory.size = t + type->size;
            cout << t << '\n';
        } else if (opt == '3') {
            cout << getAddr() << '\n';
        } else {
            findVar();
        }
    }
    return 0;
}
