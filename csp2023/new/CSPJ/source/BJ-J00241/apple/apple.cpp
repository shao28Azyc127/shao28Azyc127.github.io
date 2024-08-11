#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,cnt,ans;
bool flag;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    int x=n;
    while(x){
        ++cnt;
        if(x%3==1&&!flag){
            ans=cnt;
            flag=true;
        }
        int p=x/3;  
        if(x%3)++p;
        x-=p;
    }
    printf("%lld %lld\n",cnt,ans);
    return 0;
}