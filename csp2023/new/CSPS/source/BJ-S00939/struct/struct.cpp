#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

struct Variable {
    // string name;
    vector<Variable*> children;
    vector<string> children_name;
    long long size;
    long long width;
};

long long getAlign(long long pos, long long width) {
    return (pos + width - 1) / width * width;
}

long long getAddress(long long start, const Variable* v, const char* name) {
    if (*name == '.') ++name;
    if (*name == '\0') return start;
    long long end_pos = 0;
    while(name[end_pos] != '\0' && name[end_pos] != '.') ++end_pos;
    string child_name = string(name, end_pos);
    for (int i = 0; i < v->children.size(); ++i) {
        const Variable* p = v->children[i];
        start = getAlign(start, p->width);
        if (child_name == v->children_name[i]) {
            return getAddress(start, p, name + end_pos);
        }
        start += p->size;
    }
    return -1;
}

long long getVariable(long long start, long long target, const Variable* v, string& name) {
    if (v->children.size() == 0) return 1;
    for (int i = 0; i < v->children.size(); ++i) {
        const Variable* p = v->children[i];
        start = getAlign(start, p->width);
        if (start > target) return -1;
        long long end = start + p->size;
        if (end > target) {
            name += "." + v->children_name[i];
            return getVariable(start, target, p, name);
        }
        start = end;
    }
    return -1;
}

unordered_map<string, Variable*> name_to_var;
Variable vars[2000];


long long vars_n;
unordered_map<string, Variable> name_to_prime;

void initNameToPrime() {
    name_to_prime["byte"] = Variable{{}, {}, 1, 1};
    name_to_prime["short"] = Variable{{}, {}, 2, 2};
    name_to_prime["int"] = Variable{{}, {}, 4, 4};
    name_to_prime["long"] = Variable{{}, {}, 8, 8};
}


void updateSizeAndWidth(long long& size, long long& width, long long child_size, long long child_width) {
    if (size % child_width != 0) size = getAlign(size, child_width);
    size += child_size;
    width = max(width, child_width);
}

long long addChild(Variable& v, const string& t, const string& name) {
    auto it = name_to_prime.find(t);
    long long start = 0;
    long long child_width;
    if (it != name_to_prime.end()) {
        start = getAlign(v.size, it->second.width);
        updateSizeAndWidth(v.size, v.width, it->second.size, it->second.width);
        v.children.push_back(&it->second);
        v.children_name.push_back(name);
        child_width = it->second.width;
    } else {
        auto vit = name_to_var.find(t);
        start = getAlign(v.size, vit->second->width);
        updateSizeAndWidth(v.size, v.width, vit->second->size, vit->second->width);
        v.children.push_back(vit->second);
        v.children_name.push_back(name);
        child_width = vit->second->width;
    }

    return child_width;
}

void defineVariable() {
    long long k;
    string s;
    cin >> s >> k;
    Variable& v = vars[vars_n++];
    name_to_var[s] = &v;
    v.size = 0;
    v.width = 0;
    for (long long i = 0; i < k; ++i) {
        string t, name;
        cin >> t >> name;
        addChild(v, t, name);
    }
    v.size = getAlign(v.size, v.width);
}

Variable g;
void defineInstance() {
    string t, name;
    cin >> t >> name;
    long long start = g.size;
    long long w = addChild(g, t, name);
    start = getAlign(start, w);
    cout << start << endl;
}

int main()
{
    initNameToPrime();
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    while (n--) {
        long long ops;
        cin >> ops;
        if (ops == 1) {
            defineVariable();
            cout << vars[vars_n-1].size << " " << vars[vars_n - 1].width << endl;
        } else if (ops == 2) {
            defineInstance();
        } else if (ops == 3) {
            string str;
            cin >> str;
            long long address = getAddress(0, &g, str.c_str());
            cout << address << endl;
        } else {
            string path;
            long long address;
            cin >> address;
            if (g.children.size() == 0 || getVariable(0, address, &g, path) < 0) {
                cout << "ERR" << endl;
            } else {
                cout << path.substr(1) << endl;
            }
        }
    }
    return 0;
}
