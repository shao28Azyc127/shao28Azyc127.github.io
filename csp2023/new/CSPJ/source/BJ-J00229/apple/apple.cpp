#include <iostream>
using namespace std;
int n,ans1,ans2=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n>0){
        ans1++;
        if(n%3==1&&ans2==-1) ans2=ans1;
        n-=n/3+(n%3>0?1:0);
    }
    printf("%d %d",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}