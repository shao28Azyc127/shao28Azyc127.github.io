#include<bits/stdc++.h>
using namespace std;
int a[10][6], ans, n, b[10][6];
int ash[100000];
int zhi(int x){
    int res = 0, wei = 1;
    for(int i=1;i<=5;i++){
        res += a[x][i] * wei;
        wei *= 10;
    }
    return res;
}
void out(){
    for(int i=1;i<=99999;i++){
        if(ash[i] == n) ans+=1;
    }
    printf("%d\n", ans);
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        ans = 0;
        int x = 0, y = 1;
        for(int j=1;j<=5;j++){
           scanf("%d", &a[i][j]);
           b[i][j] = a[i][j];
        }
        for(int j=1;j<=5;j++){
            for(int k=0;k<=9;k++){
                if(k==b[i][j]) continue;
                a[i][j] = k;
                ash[zhi(i)]++;
            }
            a[i][j] = b[i][j];
        }
        for(int j=1;j<=5;j++) a[i][j] = b[i][j];
        for(int j=1;j<=4;j++){
            for(int k=1;k<=9;k++){
                a[i][j] += 1;
                if(a[i][j]>9) a[i][j] = a[i][j] - 10;
                a[i][j+1] += 1;
                if(a[i][j+1]>9) a[i][j+1] = a[i][j+1] - 10;
                if(ash[zhi(i)]) cout<<zhi(i)<<endl;
                ash[zhi(i)]++;
            }
            a[i][j] = b[i][j];
            a[i][j+1] = b[i][j+1];
        }




    }
    out();
    return 0;

}
