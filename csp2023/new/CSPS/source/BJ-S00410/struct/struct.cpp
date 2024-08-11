#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int tps, els;
long long address;
map <string, int> mt;
map <string, int> me;
struct types {
    int tn;
    long long adt, ads;
    map <string, int> mp;
    long long ade[105];
    int kne[105];
    string tna;
    string names[105];
} t[105];
struct elements {
    long long add;
    int ty;
    string na;
} e[105];
void init() {
    mt["byte"] = 1;
    mt["short"] = 2;
    mt["int"] = 3;
    mt["long"] = 4;
    tps = 4;
    t[1].tn = t[2].tn = t[3].tn = t[4].tn = 0;
    t[1].adt = 1;
    t[2].adt = 2;
    t[3].adt = 4;
    t[4].adt = 8;
    t[1].ads = 1;
    t[2].ads = 2;
    t[3].ads = 4;
    t[4].ads = 8;
    t[1].tna = "byte";
    t[2].tna = "short";
    t[3].tna = "int";
    t[4].tna = "long";
}
int searchine (long long ad) {
    int l = 1, r = els;
    while(l < r) {
        int mid = (l + r) / 2;
        if(e[mid].add < ad) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int searchint (int tp, long long ad) {
    int l = 1, r = t[tp].tn;
    while(l < r) {
        int mid = (l + r) / 2;
        if(t[tp].ade[mid] < ad) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
int main () {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    init();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            tps++;
            string s;
            cin >> s;
            scanf("%d", &k);
            t[tps].tn = k;
            t[tps].tna = s;
            mt[s] = tps;
            for(int j = 1; j <= k; j++) {
                string s1, s2;
                cin >> s1 >> s2;
                t[tps].names[j] = s2;
                t[tps].mp[s2] = j;
                int kindi = mt[s1];
                long long add1 = t[kindi].ads, add2 = t[kindi].adt, add3 = t[tps].ads;
                t[tps].kne[j] = kindi;
                if(j == 1) {
                    t[tps].adt = add2;
                    t[tps].ads = add1;
                    t[tps].ade[1] = 0;
                    continue;
                }
                t[tps].ade[j] = ((add3 + add2 - 1) / add2) * add2;
                t[tps].ads = t[tps].ade[j] + add1;
                t[tps].adt = max(t[tps].adt, add2);
            }
            printf("%d %d\n", ((t[tps].ads + t[tps].adt - 1) / t[tps].adt) * t[tps].adt, t[tps].adt);
        }
        if(op == 2) {
            els++;
            string s1, s2;
            cin >> s1 >> s2;
            me[s2] = els;
            int kinde = mt[s1];
            e[els].na = s2;
            e[els].ty = kinde;
            long long ad1 = t[kinde].ads, ad2 = t[kinde].adt;
            if(els == 1) {
                e[els].add = 0;
                address = ad1;
                printf("0\n");
                continue;
            }
            e[els].add = ((address + ad2 - 1) / ad2) * ad2;
            address = e[els].add + ad1;
            printf("%d\n", e[els].add);
        }
        if(op == 3) {
            char chh[1105];
            scanf("%s", chh);
            int len = strlen(chh), adn = 0, j = 0, tn = 0;
            string s;
            for(;j < len && chh[j] != '.'; j++) s += chh[j];
            int en = me[s];
            adn = e[en].add;
            tn = e[en].ty;
            for(; j < len; j++) {
                string s1;
                if(chh[j] == '.') j++;
                for(;j < len && chh[j] != '.'; j++) s1 += chh[j];
                en = t[tn].mp[s1];
                adn += t[tn].ade[en];
                tn = t[tn].kne[en];
            }
            printf("%d\n", adn);
        }
        if(op == 4) {
            long long x;
            scanf("%lld", &x);
            if(x > address + t[tps].ads) {
                printf("ERR\n");
                continue;
            }
            int tn1 = searchine(x);
            if(x >= e[tn1].add + t[e[tn1].ty].ads) {
                printf("ERR\n");
                continue;
            }
            x -= e[tn1].add;
            string ans;
            ans += e[tn1].na;
            tn1 = e[tn1].ty;
            bool flag = 1;
            while(tn1) {
                if(t[tn1].tn == 0) break;
                ans += '.';
                int en = searchint(tn1, x);
                x -= t[tn1].ade[en];
                ans += t[tn1].names[en];
                tn1 = t[tn1].kne[en];
                if(x >= t[tn1].ads) {
                    printf("ERR\n");
                    //printf("%d ", tn);
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) cout << ans;
        }
    }
    return 0;
}//longlong