#include <cstdio>
int n,cnt,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n){
        cnt++;
        if(!ans && n % 3 == 1){
            ans = cnt;
        }
        n -= n / 3 + (bool)(n % 3);
    }
    printf("%d %d",cnt,ans);
    return 0;
}
