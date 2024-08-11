#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int n;
int nums[20][10];
int num[10];
int sum;
int delta;

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= 5;j++){
            cin >> nums[i][j];
        }
    }
    for (int r = 0;r <= 99999;r++){
        int i = r;
        num[5] = i%10;i/=10;
        num[4] = i%10;i/=10;
        num[3] = i%10;i/=10;
        num[2] = i%10;i/=10;
        num[1] = i;
        int pass = 0;
        for (int j = 1;j <= n;j++){
            int len = 0;
            int lastchange = 0;
            delta = 0;
            for (int k = 1;k <= 5;k++){
                if (num[k] != nums[j][k]){
                    len++;
                    int cha = num[k]-nums[j][k];
                    if (delta == 0){
                        delta = abs(cha);
                        lastchange = k;
                    }
                    else if (k-lastchange != 1) continue;
                    else if (delta==cha || delta==cha+10 || delta ==cha-10) delta = 0;
                }
            }
            if (len==1||(len==2&&delta==0)) pass++;
        }
        if (pass == n){
            sum++;
        }
    }
    cout << sum;
    return 0;
}
