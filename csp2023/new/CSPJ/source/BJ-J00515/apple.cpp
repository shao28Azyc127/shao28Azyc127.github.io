#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n; cin >> n;
    int x = 0,y = 0;
    bool flag = 0;
    while(n){
        x++;
        if(!flag) y++;
        if(n % 3 == 1) flag = 1;
        if(n % 3 == 0) n -= n / 3;
        else n -= n / 3 + 1;
    }
    cout << x << " " << y;
    return 0;
}