#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tp = 0, bs = 0;
ll lst = -1;
inline ll gr(ll l, int a) {
    ll t = l + 1;
    while (t % a != 0)
        ++t;
    return t;
}                           //找到对齐后的开始位置
struct Type {
    string s;               //类型名称
    int k;                  //元素个数
    string t[105], nm[105]; //具体每个元素
    ll S;
    int a;               
} type[105];
map<string, int> mtype;
void getS(Type &x) {
    ll ml = -1;
    for (int i = 1; i <= x.k; ++i) {
        if (x.t[i] == "byte") 
            ml = gr(ml, 1);
        else if (x.t[i] == "short")
            ml = gr(ml, 2) + 1;
        else if (x.t[i] == "int")
            ml = gr(ml, 4) + 3;
        else
            ml = gr(ml, 8) + 7;
    }
    while ((ml + 1) % x.a != 0)
        ++ml;
    x.S = ml + 1;
}
void getA(Type &x) {
    x.a = 0;
    for (int i = 1; i <= x.k; ++i) {
        if (x.t[i] == "byte")
            x.a = max(x.a, 1);
        else if (x.t[i] == "short")
            x.a = max(x.a, 2);
        else if (x.t[i] == "int")
            x.a = max(x.a, 4);
        else
            x.a = max(x.a, 8);
    }
}
struct Basic {
    string s;               //b, s, i, l
    string nm;              //提前处理好点
    ll st, ed;
} bsc[20005];
map<string, int> mb;
void crBasic(string s, string nm) {
    ++bs;
    bsc[bs].s = s, bsc[bs].nm = nm;
    mb[nm] = bs;
    if (s == "byte")
        bsc[bs].st = gr(lst, 1), lst = bsc[bs].ed = bsc[bs].st;
    else if (s == "short")
        bsc[bs].st = gr(lst, 2), lst = bsc[bs].ed = bsc[bs].st + 1;
    else if (s == "int")
        bsc[bs].st = gr(lst, 4), lst = bsc[bs].ed = bsc[bs].st + 3;
    else
        bsc[bs].st = gr(lst, 8), lst = bsc[bs].ed = bsc[bs].st + 7;
    printf("%lld\n", bsc[bs].st);
}
void crStruct(string s, string n) {
    int id = mtype[s];
    lst = gr(lst, type[id].a) - 1;
    ll st = lst + 1;
    printf("%lld\n", st);
    for (int i = 1; i <= type[id].k; ++i) {
        ++bs;
        bsc[bs].s = type[id].t[i];
        bsc[bs].nm = n + '.' + type[id].nm[i];
        mb[bsc[bs].nm] = bs;
        if (type[id].t[i] == "byte")
            bsc[bs].st = gr(lst, 1), lst = bsc[bs].ed = bsc[bs].st;
        else if (type[id].t[i] == "short")
            bsc[bs].st = gr(lst, 2), lst = bsc[bs].ed = bsc[bs].st + 1;
        else if (type[id].t[i] == "int")
            bsc[bs].st = gr(lst, 4), lst = bsc[bs].ed = bsc[bs].st + 3;
        else 
            bsc[bs].st = gr(lst, 8), lst = bsc[bs].ed = bsc[bs].st + 7;
    }
    lst = st + type[id].S - 1;
}
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int T, op;
    string t, n, s;
    ll addr;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &op);
        if (op == 1) {
            ++tp;
            cin >> type[tp].s;
            mtype[type[tp].s] = tp;
            scanf("%d", &type[tp].k);
            for (int i = 1; i <= type[tp].k; ++i)
                cin >> type[tp].t[i] >> type[tp].nm[i];
            getA(type[tp]), getS(type[tp]);
            printf("%lld %d\n", type[tp].S, type[tp].a);
        }
        else if (op == 2) {
            cin >> t >> n;
            if (t == "byte" || t == "short" || t == "int" || t == "long")
                crBasic(t, n);
            else
                crStruct(t, n);
        }
        else if (op == 3) {
            cin >> s;
            int id = mb[s];
            printf("%lld\n", bsc[id].st);
        }
        else {
            scanf("%lld", &addr);
            bool flag = false;
            for (int i = 1; i <= bs && bsc[i].st <= addr; ++i) 
                if (addr <= bsc[i].ed) {
                    cout << bsc[i].nm;
                    puts("");
                    flag = true;
                }
            if (!flag) 
                puts("ERR");
        }
    }
    return 0;
}