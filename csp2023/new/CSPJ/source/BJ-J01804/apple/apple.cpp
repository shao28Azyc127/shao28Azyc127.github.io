#include<bits/stdc++.h>
using namespace std;
//CSP-J 2023 RP ++ !!!;
int n, num, ans, a[1000010], tot, flag, nn;

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    nn = n;
    while(nn > 0){
        num = ceilf(float(nn) / 3.0);
        ans += 1;
        nn -= num;
    }
    printf("%d ", ans);
    for(int i = 1; i <= n; i ++){
        a[i] = 1;
    }
    for(int i = 1; i <= ans; i ++){
        tot = 0;
        flag = 2;
        //for(int j = 1; j <= n; j ++){
        //    if(a[j]){
        //        cout << j << " ";
        //    }
        //}
        while(tot <= n){
            tot ++;
            if(a[tot] == 1){
                flag ++;
            }
            if(flag == 3){
                if(tot == n){
                    printf("%d", i);
                    return 0;
                }
                a[tot] = 0;
                flag = 0;
            }
        }
    }
    return 0;
}
