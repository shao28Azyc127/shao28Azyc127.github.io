#include <iostream>
#include <cstdio>
using namespace std;
int f[9][6] ,n;
bool turnTo(int a[], int n){
    int sum = 0,b = 999,b1, c= -1;
    bool flag = true;
    for (int i = 1; i <= 5; i++){
        if(f[n][i] == a[i]){
            sum++;
        }else{
            if(b == 999){
                b =a[i] - f[n][i];
                c = i;
            }else {
                if(c+1 == i){
                    b1 = a[i] - f[n][i];
                    if(b1 > 0 && b< 0){
                        b = b * -1;
                        if(b1 + b == 10){
                            flag = false;
                        }
                    }else if(b1 < 0 && b > 0){
                        b1 =  b1 * -1;
                        if(b1 + b == 10){
                            flag =false;
                        }
                    }else {
                         if(b == b1){
                            flag = false;
                         }
                    }
                }
            }
        }


    }
    if(sum == 4){
        return true;
    }else if(sum == 3){
        return !flag;
    }else {
        return false;
    }
}
bool YorN(int a[]){
    for (int i = 1; i <= n; i++){
        if(turnTo(a, i) == false){
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int a[6];
    int ans = 0;
    cin >> n;
    for (int i = 1; i <=n; i++){
        cin >> f[i][1]>>f[i][2]>>f[i][3]>>f[i][4]>>f[i][5];
    }
    for (int o = 0; o <= 9; o++){
        for (int t = 0; t <= 9; t++){
            for (int th = 0; th<= 9; th++){
                for (int fo = 0; fo<=9 ;fo++){
                    for (int fi = 0; fi<= 9; fi++){
                        a[1] = o;
                        a[2] = t;
                        a[3] = th;
                        a[4] = fo;
                        a[5] = fi;
                        if(YorN(a)){
                            ans++;
                        }
                    }
                }
            }
        }
    }

    cout <<ans;
    return 0;
}
