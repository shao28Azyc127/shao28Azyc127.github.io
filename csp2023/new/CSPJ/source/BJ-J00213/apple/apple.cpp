#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int ans1=0,ans2=0,tmpn=n;
    while (n){
        n-=(n+2)/3;
        ans1++;
    }
    n=tmpn-1;
    while (n%3!=0){
        n-=(n+2)/3;
        ans2++;
    }
    n=tmpn;
    printf("%d %d\n",ans1,ans2+1);
    return 0;
}
