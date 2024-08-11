#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int day = 0,ans = 0;
    int t = n;
    while(t){
        if(t % 3 == 0)t -= (t / 3);
        else t -= ((t / 3) + 1);
        ++day;
    }
    if(n % 3 == 1)ans = 1;
    else if(n % 3 == 2)ans += day;
    else if(n % 3 == 0){
        int n1 = n - (n / 3);
        if(n1 % 3 == 2)ans += day;
        else if(n1 % 3 == 1)ans += 2;
        else if(n1 % 3 == 0){
            while(n1){
                    ans++;
                    n1 -= (n1 / 3);
            }
        }
    }
    printf("%d %d",day,ans);
    return 0;
}
