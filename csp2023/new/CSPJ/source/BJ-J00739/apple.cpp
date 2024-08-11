#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int m = n - 1;
    int days = 0,day_n = -1;
    while(m >= 0){
        days++;
        if(m % 3 == 0 && day_n == -1){
            day_n = days;
        }
        m -= (m / 3 + 1);
    }
    printf("%d %d",days,day_n);
    return 0;
}
