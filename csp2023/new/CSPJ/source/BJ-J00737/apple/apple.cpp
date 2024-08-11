#include<iostream>
using namespace std;
int n, a[1000005], cnt, last, ans;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    cnt = n;
    for(int o = 1; ; o++){
        last = 2;
        for(int i = 1; i <= n; ++i){
            if(!a[i]) last++;
            if(last == 3){
                last = 0;
                a[i] = o;
                cnt--;
                if(i == n) ans = o;
            }
        }
        if(!cnt){
            printf("%d %d", o, ans);
            break;
        }
    }
    return 0;
}
