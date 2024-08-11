#include<bits/stdc++.h>
using namespace std;
int n,cnt,i=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    cnt=n;
    while(cnt>0){
        cnt-=(cnt+2)/3;
        ++i;
    }
    printf("%d ",i);
    i=1;
    while(n%3!=1){
        n-=(n+2)/3;
        ++i;
    }
    printf("%d",i);
    return 0;
}
