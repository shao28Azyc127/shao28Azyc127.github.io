#include <bits/stdc++.h>
#define int long long
/*
    long long
    freopen
*/
using namespace std;

int n, op;

struct node{
    string name;
    int siz, ask;
    vector <pair<string,string> > yuansu;

};
vector <node> type;

signed main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    type.push_back(node{"byte",1,1,{}});
    type.push_back(node{"int",4,4,{}});
    type.push_back(node{"short",2,2,{}});
    type.push_back(node{"long",8,8,{}});
    for (int i = 1;i <= n;++i){
        cin >> op;
        if (op == 1){
            node tmp;
            tmp.siz = 0;
            tmp.ask = 0;
            tmp.yuansu.clear();
            cin >> tmp.name;
            int g;
            cin >> g;
            string t1, t2;
            for (int i = 1;i <= g;++i){
                cin >> t1 >> t2;
                for (int i = 0;i < type.size();++i){
                    if (type[i].name == t1){
                        tmp.ask = max(tmp.ask, type[i].ask);
                    }
                }
                tmp.yuansu.push_back(make_pair(t1, t2));
            }
            int ans = 0, now = 0;
            for (int i = 0;i < tmp.yuansu.size();++i){
                int siz = 0;
                for (int j = 0;j < type.size();++j){
                    if (tmp.yuansu[i].first == type[j].name){
                        siz = type[j].siz;
                    }
                }
                if (now + siz > tmp.ask){
                    now = siz;
                    ans += tmp.ask;
                }
                else now += siz;
            }
            if (now > 0) ans += tmp.ask;
            type.push_back(tmp);
            cout << ans << " " << tmp.ask << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
