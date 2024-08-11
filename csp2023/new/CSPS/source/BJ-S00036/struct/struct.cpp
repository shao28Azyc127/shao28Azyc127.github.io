#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 10000 + 5;
int n;
string t, nam, s;
LL duancnt;
struct Node{
    LL l, r;
    string nam;
} duan[N];
map<string, Node> mp;
void Bina_s(int ad) {
    LL l = 1, r = duancnt+1;
    while (r - l > 1) {
        LL mid = (l + r) / 2;
        if (duan[mid].l <= ad) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (duan[l].r < ad) cout << "ERR\n";
    else cout << duan[l].nam << '\n';
}
LL strsiz, strdq, k;
string nn[N], tt[N];
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%d", &n);
    LL lastad = 0;
    for(int i = 1; i <= n; i++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            string tmp;
            cin >> tmp;
            cin >> k;
            LL beg = lastad, duiqi = -1, lst = lastad;
            for(int j = 1; j <= k; j++) {
                cin >> tt[j] >> nn[j];
                if (tt[j] == "byte") duiqi = max(duiqi, (LL)1);
                else if (tt[j] == "short") duiqi = max(duiqi, (LL)2);
                else if (tt[j] == "int") duiqi = max(duiqi, (LL)4);
                else if (tt[j] == "long") duiqi = max(duiqi, (LL)8);
            }
            for(int j = 1; j <= k; j++) {
                if (tt[j] == "byte") {
                    while (lst % duiqi) lst ++;
                    lst++;
                } else if (tt[j] == "short") {
                    while (lst % duiqi) lst ++;
                    lst+=2;
                } else if (tt[j] == "int") {
                    while (lst % duiqi) lst ++;
                    lst+=4;
                } else if (tt[j] == "long"){
                    while (lst % duiqi) lst ++;
                    lst+=8;
                }
            }
            cout << lst - beg << " " << duiqi << '\n';
            strsiz = lst - beg, strdq = duiqi;
        } else if (opt == 2) {
            cin >> t >> nam;
            if (t == "byte") {
                mp[nam] = (Node){lastad, lastad};
                duan[++duancnt] = (Node){lastad, lastad, nam};
                lastad++;
            } else if (t == "short") {
                while (lastad % 2) lastad++;
                mp[nam] = (Node){lastad, lastad+1};
                duan[++duancnt] = (Node){lastad, lastad+1, nam};
                lastad+=2;
            } else if (t == "int") {
                while (lastad % 4) lastad++;
                mp[nam] = (Node){lastad, lastad+3};
                duan[++duancnt] = (Node){lastad, lastad+3, nam};
                lastad+=4;
            } else if (t == "long") {
                while (lastad % 8) lastad++;
                mp[nam] = (Node){lastad, lastad+7};
                duan[++duancnt] = (Node){lastad, lastad+7, nam};
                lastad+=8;
            } else {
                for(int j = 1; j <= k; j++) {
                    string nownam = nam + '.' + nn[j];
                    if (tt[j] == "byte") {
                        while (lastad % strdq) lastad++;
                        mp[nownam] = (Node){lastad, lastad};
                        duan[++duancnt] = (Node){lastad, lastad, nownam};
                        lastad++;
                    } else if (tt[j] == "short") {
                        while (lastad % strdq) lastad++;
                        mp[nownam] = (Node){lastad, lastad+1};
                        duan[++duancnt] = (Node){lastad, lastad+1, nownam};
                        lastad+=2;
                    } else if (tt[j] == "int") {
                        while (lastad % strdq) lastad++;
                        mp[nownam] = (Node){lastad, lastad+3};
                        duan[++duancnt] = (Node){lastad, lastad+3, nownam};
                        lastad+=4;
                    } else if (tt[j] == "long"){
                        while (lastad % strdq) lastad++;
                        mp[nownam] = (Node){lastad, lastad+7};
                        duan[++duancnt] = (Node){lastad, lastad+7, nownam};
                        lastad+=8;
                    }
                }
            }
        } else if (opt == 3) {
            cin >> s;
            cout << mp[s].l << '\n';
        } else {
            int x;
            cin >> x;
            Bina_s(x);
        }
    }
    return 0;
}
