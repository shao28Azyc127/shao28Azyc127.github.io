#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, cnt, bcnt, ccnt;
struct node{
    int beg, ed;
    string name;
}a[N];
struct node1{
    int beg[N], ed[N];
    string name;
}c[N];
struct stu{
    string name[N];
    int k, sz, beg[N], ed[N];
}b[N];
map<char, int>f;
signed main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool flag = 0;
    cin >> n;
    f['b'] = 1, f['s'] = 2, f['i'] = 4, f['l'] = 8;
    a[0].ed = -1;
    int pre = 1;
    while(n--){
        int op;
        cin >> op;
        if(op == 1){
            cin >> b[1].name[0] >> b[1].k;
            int lst = 0;
            b[1].sz = 0;
            for(int i = 1;i <= b[1].k;i++){
                string name, typ;
                cin >> typ >> name;
                b[1].sz = max(b[1].sz, f[typ[0]]);
                int sz = f[typ[0]];
                b[1].beg[i] = ((lst + 1) % sz == 0)?lst + 1:((lst + 1) / sz + 1) * sz;
                b[1].ed[i] = b[1].beg[i] + sz - 1;
                b[1].name[i] = name;
                lst = b[1].ed[i];
            }
            pre = 2;
            cout << b[1].ed[b[1].k] + 1 << " " << b[1].sz << "\n";
        }
        else if(op == 2){
            string name, typ;
            cin >> typ >> name;
            if(typ == b[1].name[0]){
                int lst = ((pre == 1)?a[cnt].ed:c[ccnt].ed[b[1].k]);
                c[++ccnt].name = name;
                for(int i = 1;i <= b[1].k;i++){
                    c[ccnt].beg[i] = (lst) + b[1].beg[i];
                    c[ccnt].ed[i] = lst + b[1].ed[i];
                }
                continue;
            }
            int lst = ((pre == 1)?a[cnt].ed:c[ccnt].ed[b[1].k]), sz = f[typ[0]];
            a[++cnt].name = name, a[cnt].beg = ((lst + 1) % sz == 0)?lst + 1:((lst + 1) / sz + 1) * sz, a[cnt].ed = a[cnt].beg + sz - 1;
        }else if(op == 3){
            string name;
            cin >> name;
            string pre = "", nxt = "";
            bool flag = 0;
            for(int i = 0;i < name.length();i++){
                if(name[i] == '.')flag = 1;
                else if(!flag){
                    pre += name[i];
                }else{
                    nxt += name[i];
                }
            }
            if(!flag)
                for(int i = 1;i <= cnt;i++){
                    if(a[i].name == name){
                        cout << a[i].beg << "\n";
                        break;
                    }
                }
            else{
                for(int i = 1;i <= ccnt;i++){
                    if(c[i].name == pre){
                        for(int j = 1;j <= b[1].k;j++){
                            if(b[1].name[j] == nxt){
                                cout << c[i].beg[j] << "\n";
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }else{
            int x;
            cin >> x;
            bool flag = 0;
            for(int i = 1;i <= cnt;i++){
                if(a[i].beg > x){
                    break;
                }
                if(a[i].ed >= x){
                    cout << a[i].name << "\n";
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                bool flag1 = 0;
                for(int i = 1;i <= ccnt;i++){
                    if(c[i].beg[1] > x){
                        break;
                    }
                    if(c[i].ed[b[1].k] <= x){
                        for(int j = 1;j <= b[1].k;j++){
                            if(c[i].beg[j] > x)break;
                            if(c[i].ed[j] <= x){
                                cout << c[i].name << "." << b[j].name << "\n";
                                flag1 = 1;
                                break;
                            }
                        }
                    }
                }
                if(!flag1){
                    cout << "ERR\n";
                }
            }
        }
    }
    return 0;
}
