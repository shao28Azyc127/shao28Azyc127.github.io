#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    #ifndef JZQ
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    #endif
    scanf("%d",&n);
    int cnt=0;
    int ans2=0;
    while(n){
        cnt++;
        if(n%3==1&&ans2==0) ans2=cnt;
        n=n*2/3;
    }
    printf("%d %d",cnt,ans2);
    return 0;
}