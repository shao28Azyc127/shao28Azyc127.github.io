#include<bits/stdc++.h>
using namespace std;
//CSP-S 2023 RP ++!!!
int n, a[10][10], f1, f2;

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    if(n == 1){
        printf("81");
    }else if(n == 2){
        for(int i = 1; i <= 2; i ++){
            for(int j = 1; j <= 5; j ++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 1; i <= 5; i ++){
            if(a[1][i] != a[2][i]){
                if(f1 == 0){
                    f1 = i;
                }else{
                    f2 = i;
                }
            }
        }
        if(f1 == 0 && f2 == 0){
            printf("81");
        }else if(f2 == 0){
            if(f1 == 1 || f1 == 5){
                printf("10");
            }else{
                printf("12");
            }
        }else{
            if(f2 == f1 + 1){
                if(a[1][f2] - a[1][f1] == a[2][f2] - a[2][f1]){
                    printf("10");
                }else{
                    printf("6");
                }
            }else if(f2 == f1 + 2){
                if(a[1][f1] + a[1][f2] == a[2][f1] + a[2][f2]){
                    printf("4");
                }else{
                    printf("2");
                }
            }else{
                printf("2");
            }
        }
    }else{
        for(int i = 1; i <= 5; i ++){
                for(int j = 1;  j < n; j ++){
                    if(a[j][i] != a[j + 1][i]){
                if(f1 == 0){
                    f1 = i;
                }else{
                    f2 = i;
                }
            }
                }
            
        }
        if(f2  ==0){
            printf("%d", 10 - n);
            return 0;
        }
        printf("1");
    }
    return 0;
}
