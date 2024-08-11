#include<cstdio>
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans,i=1,flag=0;
    scanf("%d",&n);
    while(n>0){
        if((n-1)%3==0&&flag==0){
            ans=i;
            flag=1;
        }
        n-=(n+2)/3;
        i++;
    }
    printf("%d %d",i-1,ans);
    return 0;
}
