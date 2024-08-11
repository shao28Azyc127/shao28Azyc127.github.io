#include<cstdio>
int divide(int a,int b){
    if(a%b==0)
        return a/b;
    else
        return a/b+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int ans1=0,ans2=-1;
    for(;n>0;ans1++){
        if(ans2==-1&&n%3==1)
            ans2=ans1+1;
        n-=divide(n,3);
    }
    printf("%d %d",ans1,ans2);
    return 0;
}