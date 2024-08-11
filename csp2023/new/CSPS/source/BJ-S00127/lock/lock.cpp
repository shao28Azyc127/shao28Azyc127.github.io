#include <iostream>
#include <cstdio>
using namespace std;
long long a[10][10],fanwei[10][12][12][12][12][12];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long long n,sum = 0;
    cin>>n;
    for (int i = 1;i <= n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= 5;j++){
            for (int k = 1;k <= 9;k++){
                long long t = a[i][j];
                a[i][j] += k;
                a[i][j] %= 10;
                fanwei[i][a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]] = 1;
                a[i][j] = t;
            }
        }
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= 4;j++){
            for (int k = 1;k <= 9;k++){
                long long t1 = a[i][j];
                long long t2 = a[i][j+1];
                a[i][j] += k;
                a[i][j+1] += k;
                a[i][j] %= 10;
                a[i][j+1] %= 10;
                fanwei[i][a[i][1]][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;
                a[i][j] = t1;
                a[i][j+1] = t2;
            }
        }
    }
    for (int i = 0;i <= 9;i++){
        for (int j = 0;j <= 9;j++){
            for (int k = 0;k <= 9;k++){
                for (int l = 0;l <= 9;l++){
                    for (int m = 0;m <= 9;m++){
                        long long check = 0;
                        for (int q = 1;q <= n;q++){
                            if (fanwei[q][i][j][k][l][m] == 1){
                                check++;
                            }
                        }
                        if (check == n){
                            sum++;
                        }
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
