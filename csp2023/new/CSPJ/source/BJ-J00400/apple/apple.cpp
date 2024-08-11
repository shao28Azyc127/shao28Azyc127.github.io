#include<cstdio>
using namespace std;

int n,ans1,ans2,f;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n!=0){
        ans1++;
        if(n%3==1 && f==0){
            ans2=ans1;
            f=1;
        }
        n-=(n+2)/3;
    }
    printf("%d %d",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
