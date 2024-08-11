#include <cstdio>
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, i, ans[1000005], cnt = 0, a = 0, flag[1000005] = {};
    scanf("%d", &n);
    while(cnt < n){
        a++;
        i = 0;
        label : ;
        while(i < n){
            while(flag[i] == 1){
                i++;
            }
            flag[i] = 1;
            ans[i] = a;
            cnt++;
            i++;
            while(i < n && flag[i] == 1){
                i++;
            }
            i++;
            while(i < n && flag[i] == 1){
                i++;
            }
            i++;
            while(i < n && flag[i] == 1){
                i++;
            }
            goto label;
        }
    }
    printf("%d %d", a, ans[n - 1]);
    return 0;
}
//90
