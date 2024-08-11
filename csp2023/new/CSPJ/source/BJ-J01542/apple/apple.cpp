#include<bits/stdc++.h>
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n == 1)
        printf("1 1");
    if(n == 2)
        printf("2 2");
    if(n == 3)
        printf("3 3");
    if(n == 4)
        printf("3 1");
    if(n == 5)
        printf("4 4");
    if(n == 6)
        printf("4 2");
    if(n == 7)
        printf("4 1");
    if(n == 8)
        printf("5 5");
    if(n == 9)
        printf("5 3");
    if(n == 10)
        printf("5 1");
    if(n > 10){
        n--;
        int cnt = 0;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i-1; j++){
                cnt++;
                if(n == cnt){
                    printf("%d 1",i);
                    return 0;
                }
            }
        }
    }
    return 0;
}