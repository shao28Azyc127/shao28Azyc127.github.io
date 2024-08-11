#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n;

struct Variable;

struct Struct {
    string name;
    vector<Variable> child;
    long long siz;//siz for each child

    Struct(string s = string()) {
        name = s;
        child.clear();
        siz = 0;
    }

    long long getSize() {
        if(child.empty()) return siz;
        return siz * child.size();
    }

    long long getSingleSize() {
        return siz;
    }
};

map<string, Struct> Types;

long long ROM;

struct Variable {
    string name;
    Struct *type;

    Variable(string nam = string(), string typ = string()) {
        name = nam;
        type = &Types[typ];
    }
};

char name[101], type[101];
int op, k;

Variable v[101];
long long p[101];
int top;
long long ADDR;

void genType(Struct *s, long long siz) {
    s->siz = siz;
    Types[s->name] = *s;
}

void genType(string name, long long siz) {
    Struct *s = new Struct(name);
    genType(s, siz);
}

string stk[1001];
int stkTop;

long long calcSiz(Variable var) {
    if(var.type->child.empty()) return var.type->getSingleSize();
    return var.type->getSize() - var.type->getSingleSize() + calcSiz(var.type->child[var.type->child.size() - 1]);
}

bool dfsByAddr(Variable var, int addr) {
    if(calcSiz(var) < addr) return false;
    stk[++stkTop] = var.name;
    Struct *st = var.type;
    if(st->child.empty()) return true;
    long long siz = st->siz;
    if(dfsByAddr(st->child[addr / siz], addr % siz)) return true;
    return false;
}

string sp[1001];
int spTop;

void split(string name) {
    string s = "";
    spTop = 0;
    for(int i = 0;i < name.size();i++) {
        if(name[i] == '.') {
            sp[++spTop] = s;
            s = "";
            continue;
        }
        s += name[i];
    }
    sp[++spTop] = s;
}

long long dfsByStr(int dep, Variable var) {
    if(dep > spTop) return 0;
    long long siz = var.type->getSingleSize();
    long long t = 0;
    for(Variable ch : var.type->child) {
        if(ch.name == sp[dep]) {
            return t + dfsByStr(dep + 1, ch);
        }
        t += siz;
    }
    return -1;
}

int main() {
    genType("byte", 1);
    genType("short", 2);
    genType("int", 4);
    genType("long", 8);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%d", &n);
    Struct *st;
    Variable *var;
    while(n--) {
        scanf("%d", &op);
        long long siz = 0;
        switch(op) {
        case 1:
            scanf("%s%d", name, &k);
            st = new Struct(string(name));
            Types[name] = *st;
            for(int i = 0;i < k;i++) {
                scanf("%s%s", type, name);
                var = new Variable(string(name), string(type));
                siz = max(siz, var->type->getSize());
                st->child.emplace_back(*var);
            }
            printf("%lld %lld\n", siz * k, siz);
            genType(st, siz);
            break;
        case 2:
            scanf("%s%s", type, name);
            p[++top] = ADDR;
            v[top] = Variable(string(name), string(type));
            siz = v[top].type->getSingleSize();
            ADDR += (siz - ADDR % siz) % siz;
            printf("%lld\n", ADDR);
            ADDR += siz * v[top].type->getSize();
            break;
        case 3:
            scanf("%s", name);
            split(name);
            for(int i = 1;i <= top;i++) {
                if(v[i].name == sp[1]) {
                    printf("%lld\n", dfsByStr(2, v[i]));
                    break;
                }
            }
            break;
        case 4:
            scanf("%d", &k);
            for(int i = 1;i <= top;i++) {
                if(k >= p[i]) {
                    stkTop = 0;
                    if(!dfsByAddr(v[i], k - p[i])) printf("ERR\n");
                    else {
                        for(int i = 1;i <= stkTop;i++) {
                            cout << stk[i];
                            putchar((i == stkTop) ? '\n' : '.');
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
