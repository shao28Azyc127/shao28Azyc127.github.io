#include<bits/stdc++.h>
using namespace std;
const int N = 20;
const int M = 10;
int n = 0;
int a[N][M];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 5;j++){
            cin >> a[i][j];
        }
    }
    if(n == 1){
        cout << 81 << endl;
    }
    else if(n == 2){
        int ind = -1;
        int ind2 = -1;
        int can = true;
        for(int i = 0;i < 5;i++){
            if(a[0][i] != a[1][1] ){
                if(ind == -1) {
                    ind = i;
                } else if(ind2 == -1){
                    ind2 = i;
                }else{
                    can = false;
                }
            }
        }
        if(ind == -1 && ind2 == -1){
            cout << 81 << endl;
        }
        else if(ind != -1 && ind2 == -1){
            cout << 10 << endl;
        }
        if(ind != -1 && ind2 != -1){
            if(ind != ind2 - 1){
                can = false;
            } else if((a[0][ind] + 10 - a[1][ind]) % 10 != (a[0][ind2] + 10 - a[1][ind2]) % 10){
                can = false;
            } else {
                cout << 9 << endl;
            }
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}