#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
char Int[8] = "int", Long[8] = "long", Short[8] = "short", Byte[8] = "byte";
int flag;
struct str {
    char s[110]; int len;
    void read(void) {
        char ch = getchar(); len = 0;
        while(ch < 'a' || ch > 'z') ch = getchar();
        while('a' <= ch && ch <= 'z') s[++len] = ch, ch = getchar();
        flag = (ch == '.');
    }
    void write(void) { for(int i = 1; i <= len; i++) putchar(s[i]); }
    bool operator < (str t) const {
        if(len != t.len) return len < t.len;
        for(int i = 1; i <= len; i++)
                if(s[i] != t.s[i]) return s[i] < t.s[i];
        return 0;
    }
    str(void) {}
    str(char ss[]) {
        len = strlen(ss);
        for(int i = 1; i <= len; i++) s[i] = ss[i - 1];
    }
} temp;
map<pair<int, str>, int> mp;
map<str, int> Tp, en;
struct Struct {
    int k, sum, tab, typ[110];
    int l[110], r[110];
    str name, ele[110];
} st[110]; int tot;
int num, typ[110], beg[110];
str nme[110];
void work1(void) {
    st[++tot].name.read();
    scanf("%d", &st[tot].k); st[tot].tab = 0;
    for(int i = 1; i <= st[tot].k; i++) {
        temp.read(); int tp = st[tot].typ[i] = Tp[temp]; st[tot].ele[i].read();
        int tb = (tp > 0) ? st[tp].tab : (-tp);
        st[tot].tab = max(st[tot].tab, tb);
        st[tot].l[i] = (i == 1) ? 0 : ((1 + st[tot].r[i - 1] / tb) * tb);
        st[tot].r[i] = st[tot].l[i] - 1 + ((tp > 0) ? st[tp].sum : (-tp));
        mp[make_pair(tot, st[tot].ele[i])] = i;
    } st[tot].l[st[tot].k + 1] = st[tot].sum = (1 + st[tot].r[st[tot].k] / st[tot].tab) * st[tot].tab; Tp[st[tot].name] = tot;
    printf("%d %d\n", st[tot].sum, st[tot].tab);
}
void work2(void) {
    temp.read(); typ[++num] = Tp[temp]; nme[num].read();
    en[nme[num]] = num;
    if(num > 1) beg[num] = beg[num - 1] + ((typ[num - 1] > 0) ? st[typ[num - 1]].sum : (-typ[num - 1]));
    printf("%d\n", beg[num]);
}
void work3(void) {
    temp.read(); int id = en[temp];
    int res = beg[id], tp = typ[id], tb = (tp > 0) ? st[tp].tab : (-tp);
    while(flag) {
        temp.read();
        int id = mp[make_pair(tp, temp)];
        res += st[tp].l[id]; tp = st[tp].typ[id];
    } printf("%d\n", res);
}
queue<int> q;
void work4(void) {
    int ad; scanf("%d", &ad); beg[num + 1] = inf;
    int id = upper_bound(beg + 1, beg + num + 2, ad) - beg - 1;
    int tp = typ[id], idd; beg[num + 1] = 0;
    while(!q.empty()) q.pop();
    while(tp > 0) {
        if(ad >= st[tp].sum) return void(printf("ERR\n"));
        int idd = upper_bound(st[tp].l + 1, st[tp].l + st[tp].k + 2, ad) - st[tp].l - 1;
        ad -= st[tp].l[idd];
        tp = st[tp].typ[idd]; q.push(idd);
    }
    if(ad >= -tp) return void(printf("ERR\n"));
    nme[id].write(); tp = typ[id];
    while(!q.empty()) {
        int idd = q.front(); q.pop(); putchar('.');
        st[tp].ele[idd].write(); tp = st[tp].typ[idd];
    } putchar('\n');
}
int main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n; scanf("%d", &n);
    Tp[str(Byte)] = -1, Tp[str(Short)] = -2;
    Tp[str(Int)] = -4, Tp[str(Long)] = -8;
    while(n--) {
        int op; scanf("%d ", &op);
        if(op == 1) work1();
        else if(op == 2) work2();
        else if(op == 3) work3();
        else work4();
    }
    return 0;
}
