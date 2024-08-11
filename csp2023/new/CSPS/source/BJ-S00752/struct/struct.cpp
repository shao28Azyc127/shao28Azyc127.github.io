#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct new_struct {
    string name;
    int member_cnt;
    long long _size;
    int type[105];
    string member[105];
}structs[110];

int len_s;
map<string, int> mp;
int addr_start[110];

void solve_create_struct() {
    int tp;
    long long dq=0;
    string t;
    len_s++;

    cin >> structs[len_s].name >> structs[len_s].member_cnt;
    mp[structs[len_s].name]=len_s;

    for (int i=1; i<=structs[len_s].member_cnt; i++) {
        cin >> t >> structs[len_s].member[i];
        tp=mp[t];
        structs[len_s].type[i]=tp;

        if (structs[len_s]._size%structs[tp]._size == 0)
            structs[len_s]._size+=structs[tp]._size;
        else {
            structs[len_s]._size+=2*structs[tp]._size-structs[len_s]._size%structs[tp]._size;
        }
        dq=max(dq, structs[tp]._size);
    }

    cout << structs[len_s]._size << ' ' << dq << '\n';
}

void Init() {
    //create byte
    structs[++len_s]._size=1;
    structs[len_s].name="byte";
    structs[len_s].member_cnt=0;
    mp["byte"]=1;

    //create short
    structs[++len_s]._size=2;
    structs[len_s].name="short";
    structs[len_s].member_cnt=0;
    mp["short"]=2;

    //create int
    structs[++len_s]._size=4;
    structs[len_s].name="int";
    structs[len_s].member_cnt=0;
    mp["int"]=3;

    //create long
    structs[++len_s]._size=8;
    structs[len_s].name="long";
    structs[len_s].member_cnt=0;
    mp["long"]=4;
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    Init();

    int n, op;

    cin >> n;
    while (n--) {
        cin >> op;

        if (op == 1) {
            solve_create_struct();
        }
    }
    return 0;
}
