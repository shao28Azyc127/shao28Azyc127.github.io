#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[10000005];
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    memset(a, 0, sizeof(a));
    cin >>n;
    int x = n, ans1 = 0;
    while(x){
        ans1++;
        x -= (x - 1) / 3 + 1;
    }
    cout << ans1 << " ";
    int d = n, cnt = 0, ans = 0;
    while(n){
            cnt++;
        int f = 0;
        for(int i = 1; i <= d; i++){
                //cout <<((f <= 0) && (a[i] == 0)) << " " << a[i]<< endl;
                //cout << i << " " << f << " " << a[i] << " " << endl;
            if((f <= 0) && (a[i] == 0)){
                    if(i == d){
                            cout << cnt;
                        return 0;
                    }
                a[i] = 1;
                f = 2;
                n--;
            }
            if(a[i] == 0) f--;
        }
    }
    return 0;
}
