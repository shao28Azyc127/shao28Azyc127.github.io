#include <cstdio>
int n,a[5],cnt[100000],ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 5;j++){
            scanf("%d",&a[j]);
        }
        for(int j = 0;j < 5;j++){
            for(int k = 1;k < 10;k++){
                a[j] = (a[j] + k) % 10;
                cnt[a[0] * 10000 + a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4]]++;
                a[j] = (a[j] + 10 - k) % 10;
            }
        }
        for(int j = 0;j < 4;j++){
            for(int k = 1;k < 10;k++){
                a[j] = (a[j] + k) % 10;
                a[j + 1] = (a[j + 1] + k) % 10;
                cnt[a[0] * 10000 + a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4]]++;
                a[j] = (a[j] + 10 - k) % 10;
                a[j + 1] = (a[j + 1] + 10 - k) % 10;
            }
        }
    }
    for(int i = 0;i < 100000;i++){
        ans += (cnt[i] == n);
    }
    printf("%d",ans);
    return 0;
}
