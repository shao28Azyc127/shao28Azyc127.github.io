#include<bits/stdc++.h>
using namespace std;

int n;
int num[10][10];
int aa[10];
int ans;

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 5;j++){
            cin >> num[i][j];
        }
    }
    if(n == 1){
        cout << 81;
        return 0;
    }
    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 9;j++){
            for(int k = 1;k <= 5;k++){
                aa[k] = num[1][k];
            }
            aa[i] += j;
            aa[i] %= 10;
            int f = 0;
            for(int k = 2;k <= n;k++){
                for(int m = 1;m <= 5;m++){
                    if(aa[m] != num[k][m]){
                        if(aa[m+1]-num[k][m+1] == aa[m]-num[k][m]){
                            f++;
                            m++;
                        }
                        else{
                            f++;
                        }
                    }
                }
                if(f != 1){
                    break;
                }
                f = 0;
                if(k == n){
                    ans++;
                }
            }

        }
    }
    for(int i = 1;i < 5;i++){
        for(int j = 1;j <= 9;j++){
            for(int k = 1;k <= 5;k++){
                aa[k] = num[1][k];
            }
            aa[i] += j;
            aa[i+1] += j;
            aa[i] %= 10;
            aa[i+1] %= 10;
            int f = 0;
            for(int k = 2;k <= n;k++){
                for(int m = 1;m <= 5;m++){
                    if(aa[m] != num[k][m]){
                        if(aa[m+1]-num[k][m+1] == aa[m]-num[k][m]){
                            f++;
                            m++;
                        }
                        else{
                            f++;
                        }
                    }
                }
                if(f != 1){
                    break;
                }
                f = 0;
                if(k == n){
                    ans++;
                }
            }

        }
    }
    cout << ans;
}
