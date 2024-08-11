#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,i,cnt=0;
    scanf("%d",&n);
    for(i=1;n;i++){
        if(n%3==1 && !cnt) cnt=i;
        n=n-(n+2)/3;
    }
    printf("%d %d",i-1,cnt);
    return 0;
}