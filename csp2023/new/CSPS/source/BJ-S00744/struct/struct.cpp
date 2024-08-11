#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 105;
int n, op, k, top;
string types[MAXN], names[MAXN];
int addrs[MAXN],ssize[MAXN];
int pos = 0;

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    int n;
    cin >> n;
    while (n --) {
        cin >> op;
        if (op == 2){
            cin >> types[top] >> names[top];
            addrs[top] = pos;
            cout << pos << endl;
            if (types[top] == "byte")
                pos += 1, ssize[top] = 1;
            else if (types[top] == "short")
                pos += 2, ssize[top] = 2;
            else if (types[top] == "int")
                pos += 4, ssize[top] = 4;
            else if (types[top] == "long")
                pos += 8, ssize[top] = 8;
            top ++;
        } else if (op == 3){
            string name;
            cin >> name;
            for (int i = 0; i < top; i ++){
                if (names[i] == name)
                    cout << addrs[i] << endl;

            }
        } else if (op == 4){
            int cpos, i;
            cin >> cpos;
            for (i = 0; i < top; i ++){
                if (addrs[i] <= cpos && addrs[i]+ssize[i] > cpos){
                    cout << names[i] << endl;
                    break;
                }
            }
            if (i == top){
                cout << "ERR" << endl;
            }
        }

    }

    return 0;
}
/*

*/
