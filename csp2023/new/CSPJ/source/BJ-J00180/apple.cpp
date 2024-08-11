#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n){
        if(n%3==1)printf("%d ",ans+1);
        n-=ceil(n/3);
        ans++;
    }
    printf("%d",ans);
    return 0;
}