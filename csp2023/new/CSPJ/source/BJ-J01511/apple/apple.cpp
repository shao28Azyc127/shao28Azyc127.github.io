#include <bits/stdc++.h>
using namespace std;
int n,a,sum,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    a=n;
    bool fff=0;
    while(n){
        if((n-1)%3==0&&fff==0) ans=sum+1,fff=1;
        n-=1+(n-1)/3;
        sum++;
    }
    printf("%d %d",sum,ans);
    return 0;
}
