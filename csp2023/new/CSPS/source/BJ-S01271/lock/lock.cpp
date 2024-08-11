#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll n;
char b[10][10];
string c[10];
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;

    for (int i = 1;i <= n;i ++){
        for (int j = 1;j <= 5;j ++){
            cin >> b[i][j];
            c[i][j] = b[i][j];
        }
    }
    if (n == 1){
        cout << 81;
        return 0;
    }

    return 0;
}
