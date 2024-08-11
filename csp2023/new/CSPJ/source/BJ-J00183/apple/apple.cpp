#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,n2,ans=1,day=0;
    bool flag=false;
    scanf("%d",&n);
    n2=n;
    while(n%3!=1){
        n-=((n+2)/3);
        ans++;
    }
    while(n2!=0){
        n2-=((n2+2)/3);
        day++;
    }
    printf("%d %d",day,ans);
}
