#include<cstdio>
#include<iostream>
using namespace std;
int n, ans, len;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(n != 0){
        if(n % 3 == 0){

            int o = n / 3 * 2;
            n = o;
        }
        else if(n % 3 == 1){
            n = n / 3 * 2;
            if(len == 0) len = ans + 1;
        }
        else if(n % 3 == 2) n = n / 3 * 2 + 1;
        ans++;
        //cout << n << " ";
    }
    cout << ans << " " << len;
    return 0;
}
