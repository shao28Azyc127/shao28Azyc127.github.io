#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int t=n;
    while(n>=(n-1)/3+1) n-=(n-1)/3+1,ans1++;
    n=t;
    while(n%3!=1) n=n*2/3,ans2++;
    printf("%d %d\n",ans1,ans2);
    return 0;
}
