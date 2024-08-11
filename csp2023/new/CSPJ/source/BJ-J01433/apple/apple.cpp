#include<bits/stdc++.h>
using namespace std;
bool f[1000010];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    scanf("%lld",&n);
    if(n<=3){
        printf("%lld %lld",n,n);
    }
    long long cnt=0,ans=0,last=n;
    while(last>3){
        ans++;
        long long temp=0,coun=0;
        for(long long i=1;i<=n;i++){
            if(f[i]==0){
                temp++;
                if(temp%3==1){
                    f[i]=1;
                    coun++;
                    if(i==n)cnt=ans;
                }
            }
        }
        last-=coun;
    }
    if(f[n]==0){
        cnt=ans+last;
    }
    ans+=last;
    printf("%lld %lld",cnt,ans);
    return 0;
}
