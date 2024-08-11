#include<cstdio>
int n,cnt;
int a[100000005] = {};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        a[i] = a[i - (i + 2) / 3] + 1;
    }
    printf("%d ",a[n]);
    if(n % 3 == 1) printf("1");
        else if(n % 9 == 3) printf("%d",a[n]);
            else if(n % 9 == 2||n % 9 == 6) printf("2");
                else if(n % 27 == 3||n % 27 == 9||n % 27 == 17||n % 27 == 23) printf("3");
    return 0;
}
