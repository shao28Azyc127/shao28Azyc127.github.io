#include<bits/stdc++.h>
using namespace std;

int n,ans,i;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for(i=1;n;i++){
        if(n%3==1&&!ans)ans=i;
        n-=(n+2)/3;
    }
    printf("%d %d",i-1,ans);
    return 0;
}
