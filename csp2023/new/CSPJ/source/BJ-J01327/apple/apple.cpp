#include<bits/stdc++.h>
using namespace std;
long long n,h=0,ans=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    while(n!=0){
        ++h;
        if(((n-1)%3==0)&&(ans==-1)){
            ans=h;
        }
        n=n-((n-1)/3)-1;
    }
    printf("%lld %lld",h,ans);
    return 0;
}
