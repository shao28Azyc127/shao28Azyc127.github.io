#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in" , "r"  , stdin);
    freopen("apple.out" , "w" , stdout);
    int n , da = 0 , pn = 0;
    scanf("%d" ,&n);
    int tn = n;
    while(tn){
        da++;
        if(tn < 3)tn-=1;
        else if(tn % 3 == 0) tn -= tn / 3;
        else tn-=(tn+3-(tn%3))/3;
    }
    if(n%3==1)pn = 1;
    else if(n%3 == 2)pn = da;
    else if(n == 3)pn = 3;
    else {
        while(n){
            pn++;
            if(n%3 == 1)break;
            if(n < 3)n-=1;
            else if(n % 3 == 0) n -= n / 3;
            else n-=(n+3-(n%3))/3;
        }
    }
    printf("%d %d" , da , pn);
    return 0;
}
