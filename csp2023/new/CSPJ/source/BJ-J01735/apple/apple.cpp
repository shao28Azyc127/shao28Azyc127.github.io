#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    int a[1048576];
    //printf("!");
    scanf("%d",&n);

    int ans;
    if(n %3 == 1){
        ans = 1;
    }
    //nt nx[1048576];

    int k = 0;
    for(int i = 1;i <= n;i++){
        a[i] = i;
    }
    int i;
    int day = 0;
    while(n){
        i = k+1;
        //a[i] = i;

        if(a[i] == n) ans = day;
        for(int j = i;j <= n;j++){
            a[j] = a[j+1];
        }
        n--;

        k = (k+3) % n;
        if(k == 0) day++;
    }
    printf("%d %d",day,ans);
    return 0;
}
