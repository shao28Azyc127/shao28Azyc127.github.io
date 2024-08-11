#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int cnt=0,d=-1;
    while(n){
        if(n%3==1&&d==-1){
            d=cnt+1;
        }
        n-=ceil(1.0*n/3);
        cnt++;
    }
    printf("%d %d",cnt,d);
    return 0;
}
