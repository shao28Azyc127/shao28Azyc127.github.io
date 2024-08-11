#include<bits/stdc++.h>
using namespace std;
int n,cnt,lst;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    scanf("%d",&n);
    while(n){
        cnt++;
        if(n%3==1&&lst==0)lst=cnt;
        n-=(n+2)/3;
    }
    printf("%d %d",cnt,lst);
    return 0;
}
