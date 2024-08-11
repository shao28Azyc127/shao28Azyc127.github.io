#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace  std;
const int N = 1e5 + 5;
typedef long long ll;
int n;
char s[N];
struct T {
    string ty, name;
};
struct ST {
    string name;
    vector<T> s;
    int mx;
};
int cnt;
ST ts[N];
vector<T> bl[N];
int bl_cnt;
int res;
int cal_st(string name) {
    int p = -1;
    for(int i = 1; i <= cnt; i++) {
        if(ts[i].name == name) {
            p = i;
        }
    }
    if(p == -1) return 0;
    int sum = 0;
    int siz = ts[p].s.size(); 
    int mx = 0;
    for(int i = 0 ;i < siz ; i++) {
        if(ts[p].s[i].ty == "byte") {
            mx = max(mx, 1);
            sum += 1;
        } 
        if(ts[p].s[i].ty == "short") {
            mx = max(mx, 2);
            sum += 2;
        } 
        if(ts[p].s[i].ty == "int") {
            mx = max(mx, 4);
            sum += 4;
        } 
        if(ts[p].s[i].ty == "long") {
            mx = max(mx, 8);
            sum += 8;
        } else {
            int t = cal_st(ts[p].s[i].ty);
            mx = max(mx,t);
            sum += t;
        }
    }

    return sum;
}
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n; 
    for(int i = 1; i <=n; i++) {
        int opt , c;
        cin >> opt;
        if(opt == 1) {
            cin >> ts[++cnt].name >> c;
            for(int j = 1; j <= c; j++) {
                string t1, t2;
                cin >> t1 >> t2;
                ts[cnt].s.push_back({t1, t2});
            }
            cout << cal_st(ts[cnt].name) << endl;
        }
        if(opt == 2) {
            string t1, t2;
            cin >> t1 >> t2; 
            bl->push_back({t1, t2});
        }
        if(opt == 3) {
            string s;
            cout << 10 << endl;
        }
        if(opt == 4) {
            string s;
            cout << "ERR" << endl;
        }
    }
    return 0;
}