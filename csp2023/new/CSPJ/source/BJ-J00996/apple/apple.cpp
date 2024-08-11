#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int ans=0,cnt=0;
    while(n){
        if(ans==0&&n%3==1){
            ans=cnt+1;
        }
        n-=(n/3+min(n%3,1));
        cnt++;
    }
    printf("%d %d",cnt,ans);

}
