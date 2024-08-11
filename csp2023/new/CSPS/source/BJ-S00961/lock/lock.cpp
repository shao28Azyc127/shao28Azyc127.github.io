#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int n;
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.ans", "w", stdout)
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 5; j ++){
            scanf("%d", &a[i][j]);
        }
    }
    if(n == 1){
        printf("81");
        return 0;
    }
    int cnt = 0;
    int fd = -1;
    for(int k = 1; k <= 5; k ++){
        bool flag = true;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(a[i][k] != a[j][k]) {
                    flag = false;
                    fd = k;
                }
            }
        }
        if(flag) cnt ++;
    }
    if(cnt == 5){
        printf("81");
        return 0;
    }
    if(cnt == 3){
        bool flag = true;
        for(int i = 1; i <= n; i ++){
            if(a[i][fd] != a[i][fd+1]){
                flag = false;
            }
        }
        if(flag){
            printf("10");
            return 0;
        }
        else{
            printf("0");
            return 0;
        }
    }
    if(cnt == 4){
        printf("10");
        return 0;
    }
    return 0;
}
