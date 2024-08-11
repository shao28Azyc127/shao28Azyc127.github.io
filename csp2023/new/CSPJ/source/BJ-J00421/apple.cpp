#include <bits/stdc++.h>
using namespace std;
int n,cnt,ans;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n){
        int x=n/3;
        if(n%3) x++;
        if(n%3==1) if(ans==0) ans=cnt+1;
        cnt++;
        n-=x;
        //printf("%d %d\n",n,x);
    }
    printf("%d %d",cnt,ans);
    return 0;
}
