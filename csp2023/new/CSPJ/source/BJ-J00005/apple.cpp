#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<stack>
#define int long long
#define ull unsigned long long
using namespace std;
int n,ans1,ans2;
bool flag;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    while(n){
        ans1++;
        if(n%3==1&&!flag){
            ans2=ans1;
            flag=true;
        }
        if(n%3==0)n-=n/3;
        else n-=n/3+1;
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}
