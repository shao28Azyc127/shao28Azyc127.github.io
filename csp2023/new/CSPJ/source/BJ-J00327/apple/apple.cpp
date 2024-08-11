#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n,cnt=0,ans=-1;
    scanf("%lld",&n);
    while(n>0){
        cnt++;
        if(n%3==1&&ans==-1){
            ans=cnt;
        }
        n=n-(n+2)/3;
    }
    printf("%lld %lld",cnt,ans);
    return 0;
}
