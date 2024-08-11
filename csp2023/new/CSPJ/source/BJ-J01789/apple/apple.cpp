#include<bits/stdc++.h>
using namespace std;
long long n,day=0,ans,number=0,cn=0;
bool a[1000000010];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    while(number<n){
        cn=0;
        day++;
        for(int i=1;i<=n;i++){
            if(a[i])continue;
            cn%=3;
            if(cn==0){
                a[i]=1;
                if(i==n)ans=day;
                number++;
            }
            cn++;
        }
    }
    printf("%lld%lld",day,ans);
    return 0;
}
