#include<iostream>
#include<map>

using namespace std;

const int N = 1e6 + 5;

int arr[N];
string lit[N];
map<string, int> M;

int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n, idx = 0;
    string s, c, f;
    cin >> n;
    M["byte"] = 1;
    M["short"] = 2;
    M["int"] = 4;
    M["long"] = 8;
    while(n --){
        int a;
        cin >> a;
        if(a == 2){
            cin >> s >> c;
            cout << idx << endl;
            for(int i = 0; i < M[s]; i++){
                lit[idx++] = c;
            }
        }
        if(a == 3){
            cin >> f;
            for(int i = 0; i < idx; i++){
                if(lit[i] == f){
                    cout << i << endl;
                    break;
                }
            }
        }
        if(a == 4){
            int q;
            cin >> q;
            cout << lit[q] << endl;
        }
    }
    return 0;
}
