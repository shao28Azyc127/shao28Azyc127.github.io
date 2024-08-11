#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, m, k=0;
    cin >> n;
    m=n;
    while(n>6){
        k++;
        if(n%3==0){
            n=n/3*2;
        }else{
            n=n-n/3-1;
        }
    }
    while(n>3){
        k++;
        n-=2;
    }
    printf("%d ", k+n);
    k=0,n=m;
    while(n%3!=1 and n>3){
        k++;
        if(n%3==0){
            n=n/3*2;
        }else{
            n=n-n/3-1;
        }
    }
    if(n<=3){
        printf("%d", k+n);
    }else{
        printf("%d", k+1);
    }
    return 0;
}

