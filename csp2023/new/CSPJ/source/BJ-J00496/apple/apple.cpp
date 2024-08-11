#include <iostream>
#include <cstdio>
using namespace std;

int a[100005];
bool f[100005];
int  main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n; cin >> n;
    int k = 0, cnt = 1, sum = 1, sum2 = 0, x = 1, y = 0;
    bool flag = false;
    while (k < n){
        if (cnt > n){
                flag = false;
            cnt = 1;
            sum++;
            sum2 = 0;
        }
        if (!flag)
        for (int i = x; i <= n; i++){
            if (a[i] == 0){
                a[i] = 1;
                k++;
                x = i;
                if (i == n) y = sum;
                flag = true;
                break;
            }
        }
        //cout << 1932 << endl;
        if (a[cnt] == 0) sum2++;
        if (sum2 == 3){
                //cout << cnt << " "<< k <<endl;
            a[cnt] = 1;
            k++;
            sum2 = 0;
            if (cnt == n) y = sum;
        }
        cnt++;
    }
    cout << sum << " ";
    cout << y << endl;
return 0;}