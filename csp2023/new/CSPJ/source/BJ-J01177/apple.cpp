#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n){
        ans1++;
        if((n+2)%3==0 && ans2==-1){
            ans2=ans1;
        }
        n-=(n+2)/3;
    }
    printf("%d %d",ans1,ans2);
    return 0;
}
