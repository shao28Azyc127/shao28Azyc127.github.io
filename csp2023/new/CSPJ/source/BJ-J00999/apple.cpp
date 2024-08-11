#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);

    int ans1=0,ans2=0;
    int tmp=n;
    while (tmp>0){
        ans1++;
        if (tmp%3==0) tmp-=tmp/3;
        else tmp-=(tmp/3+1);
    }

    printf("%d ",ans1);

    while (n>0){
        ans2++;
        if (n%3==1) break;
        if (n%3==0) n-=n/3;
        else n-=(n/3+1);
    }

    printf("%d",ans2);
    return 0;
}