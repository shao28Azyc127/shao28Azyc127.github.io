#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
bool v=true;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    int i=0;
    int a=0;
    while(n!=0){
        int ans=n-1;
        if(ans%3==0&&v){
            a=i+1;
            v=false;
        }
        ans/=3;
        n-=ans;
        n-=1;
        i++;
    }
    printf("%d %lld",i,a);
    return 0;
}
