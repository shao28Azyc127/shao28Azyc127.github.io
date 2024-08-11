#include <iostream>
using namespace std;

int a[1000000005];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, x, y = 0;
    bool f = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    int len = n;
    while(len){
        int t = 0;
        for(int i = 1; i <= len; i++){
            if(i%3 != 1){
                t++;
                a[t] = a[i];
            }
        }
    //        for(int i = 1; i <= t; i++){
    //            cout << a[i] << ' ';
    //        }
    //        cout << endl;
        len = t;
        y++;
        if(a[t] != n && !f){
            x = y;
            f = 1;
        }
    }
    cout << y << ' ' << x << endl;
}
