#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

ifstream cin("struct2.in");
ofstream cout("struct.out");

struct stru {
    string name;
    long long startit;
    int stdp;
    long long size;
    vector<stru> member;
};

struct gvar {
    string name;
    string type;
    long long startit;
};

unordered_map<string, stru> struMap;
vector<gvar> ctx;

long long bq(int stdp, long long it) {
    int md = it % stdp;
    if (md == 0) {
        return it;
    }
    return it - md + stdp;
}

void addstru() {
    stru tstru;
    string name;
    int num;
    cin >> name >> num;
    tstru.member.resize(num);
    tstru.startit = 0;
    for (int i = 0; i < num; i++) {
        string type;
        tstru.member[i].member.clear();
        cin >> type >> tstru.member[i].name;

        tstru.member[i].size = struMap[type].size;
        tstru.member[i].stdp = struMap[type].stdp;
        tstru.member[i].member = struMap[type].member;
        tstru.member[i].startit = bq(tstru.member[i].stdp, tstru.size);

        tstru.stdp = max(tstru.stdp, tstru.member[i].stdp);
        tstru.size = tstru.member[i].startit + tstru.member[i].size;
    }
    struMap[name] = tstru;

    cout << tstru.size << " " << tstru.stdp << endl;
}

void addvar() {
    string type, name;
    cin >> type >> name;

    long long globalit = 0;
    if (ctx.size() != 0) {
        globalit = ctx.back().startit + struMap[ctx.back().type].size;
    }

    ctx.push_back(gvar{name, type, bq(struMap[type].stdp, globalit)});
    cout << ctx.back().startit << endl;
}

void visvar() {
    string path;
    queue<string> varname;
    while (!varname.empty()) {
        varname.pop();
    }

    cin >> path;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '.') {
            varname.push(path.substr(0, i));
            path = path.substr(i + 1);
        }
    }
    varname.push(path);

    stru tstru;
    long long beginit;
    for (auto gv : ctx) {
        if (gv.name == varname.front()) {
            varname.pop();
            beginit = gv.startit;
            tstru = struMap[gv.type];
            break;
        }
    }

    while (!varname.empty()) {
        for (auto t : tstru.member) {
            if (t.name == varname.front()) {
                varname.pop();
                beginit += t.startit;
                tstru = t;
                break;
            }
        }
    }

    cout << beginit << endl;
}

void vismem() {
    string path = "";
    long long beginit;
    cin >> beginit;

    stru tstru;
    bool has = false;
    for (auto gv : ctx) {
        if (gv.startit <= beginit &&
            beginit < gv.startit + struMap[gv.type].size) {
            tstru = struMap[gv.type];
            beginit -= gv.startit;
            has = true;
            path += gv.name;
            // cout << "YES " << path << endl;
            break;
        }
    }
    if (!has) {
        cout << "ERR" << endl;
        return;
    }

    while (tstru.member.size() != 0) {
        bool has = false;
        for (auto t : tstru.member) {
            // cout << t.name << " " << t.startit << " " << beginit << " "
            //      << beginit << " " << t.startit << " " << t.size << endl;
            if (t.startit <= beginit && beginit < t.startit + t.size) {
                tstru = t;
                beginit -= t.size;
                path += "." + t.name;
                has = true;
                // cout << "YES " << path << endl;
                break;
            }
        }
        // cout << tstru.name << " " << tstru.member.size() << " " << has << endl;
        if (!has) {
            cout << "ERR" << endl;
            return;
        }
    }

    cout << path << endl;
}

int main() {
    struMap.clear();
    struMap["byte"].member.clear();
    struMap["byte"].size = 1;
    struMap["byte"].stdp = 1;
    struMap["byte"].startit = 0;

    struMap["short"].member.clear();
    struMap["short"].size = 2;
    struMap["short"].stdp = 2;
    struMap["short"].startit = 0;

    struMap["int"].member.clear();
    struMap["int"].size = 4;
    struMap["int"].stdp = 4;
    struMap["int"].startit = 0;

    struMap["long"].member.clear();
    struMap["long"].size = 8;
    struMap["long"].stdp = 8;
    struMap["long"].startit = 0;
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        switch (t) {
            case 1:
                addstru();
                break;
            case 2:
                addvar();
                break;
            case 3:
                visvar();
                break;
            case 4:
                vismem();
                break;
        }
    }
    return 0;
}
