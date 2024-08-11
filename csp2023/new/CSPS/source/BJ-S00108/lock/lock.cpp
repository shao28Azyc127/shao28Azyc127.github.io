#include <bits/stdc++.h>

using namespace std;

int n;
int a[10][10][10];
int b[10][5];
int c[10][5];
int ans;

void f(int k){

    if(k > 5){
        ++ans;
        return;
    }

    for(int i = 0; i <= 9; i++){
            bool t = true;

        for(int j = 1; j <= n; j++){
            c[j][1] = b[j][1];
            c[j][2] = b[j][2];

            if(b[j][1] && (k - b[j][1] > 1 || k - b[j][1] == 1 && b[j][2] != a[j][k][i])){
                t = 0;
            }

            if(b[j][1]){
                b[j][1] = -1;
            } else {

                if(a[j][k][i]){
                    b[j][1] = k;
                    b[j][2] = a[j][k][i];
                }

            }

        }

        if(t){
            f(k + 1);
        }

        for(int j = 1; j <= n; j++){
            b[j][1] = c[j][1];
            b[j][2] = c[j][2];
        }

    }

    return;
}


int main(){

    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;

    if(n == 1){
        cout << 81;
        return 0;
    }

    if(n == 2){
        cout << 10;
        return 0;
    }

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= 5; j++){
            int t;
            cin >> t;

            for(int k = 0; k <= 9; k++){
                a[i][j][k] = t - k;
            }

        }

    }

    f(1);
    cout << ans;
    return 0;
}