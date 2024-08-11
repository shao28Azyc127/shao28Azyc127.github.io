#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans1,ans2=0;
    bool f=0;
    scanf("%d",&n);
    while(n>=0){
        if((n%3)==1 && !f){ans1=ans2;f=1;}
        n-=n/3;
        ans2++;
    }
    printf("%d %d",ans2,ans1);
    return 0;
}
