#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int m=n,cnt=0,ans=0;
    while (m){
        cnt++;
        if ((m-1)%3==0 && !ans) ans=cnt;
        m=m-(m-1)/3-1;
    }
    printf("%d %d",cnt,ans);
    return 0;
}
