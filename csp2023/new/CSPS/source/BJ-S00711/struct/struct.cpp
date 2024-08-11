#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 105;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int T;
long long curAddr = 0;

enum Type {
    BYTE = 1,
    SHORT = 2,
    INT = 4,
    LONG = 8
};

struct Struct {
    string name;
    string defName;
    Type maxType;
    long long size;
    vector <Struct> childs;
    long long startAddr;
};

const Struct byte_ = (Struct){"", "byte", BYTE, 1, vector<Struct>(), 0};
const Struct short_ = (Struct){"", "short", SHORT, 2, vector<Struct>(), 0};
const Struct int_ = (Struct){"", "int", INT, 4, vector<Struct>(), 0};
const Struct long_ = (Struct){"", "long", LONG, 8, vector<Struct>(), 0};

map <string, Struct> DefinedStructs;
vector <Struct> ObjectStructs; 

void assignMem(Struct& curStruct) {
    if (curAddr % curStruct.maxType)
    curAddr += (curStruct.maxType - curAddr % curStruct.maxType); // align first
    if (curStruct.childs.size() == 0) {
        curStruct.startAddr = curAddr;
        curAddr += curStruct.maxType;
        return;
    }
    curStruct.startAddr = curAddr;
    for (int i = 0; i < curStruct.childs.size(); i++) {
        assignMem(curStruct.childs[i]);
        //curAddr += curStruct.childs[i].maxType;
    }
}

long long queryObj(vector <string> query, int level, Struct* curStructPtr) {
    if (curStructPtr == nullptr) {
        for (int i = 0; i < ObjectStructs.size(); i++) {
            if (ObjectStructs[i].name == query[level]) {
                if (query.size() == 1) {
                    return ObjectStructs[i].startAddr;
                }
                //cout << "obj:" << ObjectStructs[i].name << endl;
                return queryObj(query, level + 1, &ObjectStructs[i]);
            }
        }
    }
    else {
        for (int i = 0; i < curStructPtr -> childs.size(); i++) {
            if (curStructPtr -> childs[i].name == query[level]) {
                if (query.size() == level + 1) {
                    //cout << query.size() << " " << level + 1 << endl;
                    return curStructPtr -> childs[i].startAddr;
                }
                //cout << "cur:" << curStructPtr -> childs[i].name << endl;
                return queryObj(query, level + 1, &(curStructPtr -> childs[i]));
            }
        }
    }
}

string queryAddr(long long addr, string curStr, Struct* curStructPtr) {
    if (curStructPtr == nullptr) {
        int l = 0;
        int r = ObjectStructs.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ObjectStructs[mid].startAddr < addr) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }

        if (ObjectStructs[l].childs.size() == 0) {
            if (ObjectStructs[l].startAddr + ObjectStructs[l].maxType - 1 >= addr) {
                return ObjectStructs[l].name;
            }
            else {
                return "ERR";
            }
        }
        //cout << l << endl;
        return queryAddr(addr, curStr + ObjectStructs[l].name, &ObjectStructs[l]);
    }
    else {
        if (curStructPtr -> childs.size() == 0) {
            if (curStructPtr -> startAddr + curStructPtr -> maxType - 1 >= addr) {
                return curStructPtr -> name;
            }
            else {
                return "ERR";
            }
        }
        int l = 0;
        int r = curStructPtr -> childs.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (curStructPtr -> childs[mid].startAddr < addr) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        //cout << l << endl;
        return queryAddr(addr, curStr + curStructPtr -> childs[l].name, &(curStructPtr -> childs[l]));
    }
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(false);

    DefinedStructs["byte"] = byte_;
    DefinedStructs["short"] = short_;
    DefinedStructs["int"] = int_;
    DefinedStructs["long"] = long_;
    cin >> T;

    while (T--) {
        int op;
        cin >> op;
        if (op == 1) {
            string s;
            int k;
            cin >> s >> k;
            vector <Struct> tmp;
            Type maxType1 = BYTE;
            long long maxSize = 0;
            for (int i = 1; i <= k; i++) {
                string type, name;
                cin >> type >> name;
                tmp.push_back(DefinedStructs[type]);
                tmp[tmp.size() - 1].name = name;
                if (maxSize % tmp[tmp.size() - 1].maxType)
                    maxSize += (tmp[tmp.size() - 1].maxType - maxSize % tmp[tmp.size() - 1].maxType);
                maxSize = maxSize + tmp[tmp.size() - 1].size;

                if (tmp[tmp.size() - 1].maxType > maxType1) {
                    maxType1 = tmp[tmp.size() - 1].maxType;
                }
            }
            cout << maxSize << " " << maxType1 << endl;
            DefinedStructs[s] = ((Struct) {"", s, maxType1, maxSize, tmp, 0});
        }
        if (op == 2) {
            string type, name;
            cin >> type >> name;

            Struct resStruct = DefinedStructs[type];
            resStruct.name = name;
            ObjectStructs.push_back(resStruct);
            assignMem(ObjectStructs.back());
            cout << ObjectStructs.back().startAddr << endl;
        }
        if (op == 3) {
            string s;
            cin >> s;
            string cursub = "";
            vector <string> query;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '.') {
                    cursub += s[i];
                }
                else {
                    query.push_back(cursub);
                    cursub = "";
                }
            }
            query.push_back(cursub);

            cout << queryObj(query, 0, nullptr) << endl;

        }
        if (op == 4) {
            long long addr;
            cin >> addr;
            cout << queryAddr(addr, "", nullptr) << endl;
        }
        //cout << "CurAddr:" << curAddr << endl;
    }
    return 0;
}