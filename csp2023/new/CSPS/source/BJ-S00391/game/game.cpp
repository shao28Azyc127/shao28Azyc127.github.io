#include<iostream>

using namespace std;

const int N = 2e6 + 5;
char c[N];

int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int a;
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> c[i];
    }
    cout << a / 2 + 1;
    return 0;
}
