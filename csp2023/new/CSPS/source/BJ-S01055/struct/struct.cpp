#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int n, op, ms = 0;
map<string, int> space;
vector<string> x1n, x2c;
struct Struct{
    string name;
    vector<int> space;
    vector<string> cl, n;
};
vector<Struct> s;
void op1(){
    int num, maxn = 0;
    Struct tmp;
    string name;
    cin >> name >> num;
    tmp.name = name;
    for (int j = 0; j < num; j ++){
        string cl, name2;
        cin >> cl >> name2;
        tmp.cl.push_back(cl);
        tmp.n.push_back(name2);
        maxn = max(maxn, space[cl]);
    }
    for (int j = 0; j < num; j ++){
        tmp.space.push_back(j * maxn);
    }
    space[name] = num * maxn;
    s.push_back(tmp);
    cout << num * maxn << " " << maxn << endl;
    return ;
}
void op2(){
    string cl, name;
    cin >> cl >> name;
    for (int i = 0; i < s.size(); i ++)
        if (s[i].name == cl){
            ms += space[cl];
            x1n.push_back(name);
            x2c.push_back(cl);
            break;
        }
    cout << ms - space[cl] << endl;
    return ;
}
void op3(){
    string dt_;
    cin >> dt_;
    return ;
}
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    space["byte"] = 1;
    space["short"] = 2;
    space["int"] = 4;
    space["long"] = 8;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> op;
        if (op == 1){
            op1();
        } else if (op == 2){
            op2();
        } else if (op == 3){
            op3();
        } else {
            int tmp;
            cin >> tmp;
        }
    }
    return 0;
}
