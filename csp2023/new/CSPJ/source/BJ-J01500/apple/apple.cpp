#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,n_;
int ans1,ans2;

signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    scanf("%lld",&n);

    while(n){

        if(ans2 == 0){
            if(n == (n/3)*3+1)ans2 = ans1+1;
        }

        int m=0;
        if(n%3!=0){
            m++;
        }
        n-=(m+n/3);
        ans1++;

    }

    printf("%lld %lld\n",ans1,ans2);

    return 0;
}
