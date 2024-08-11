#include <iostream>
using namespace std;
const int len=2e6+10;
char c[len];
int n;
long long dp(int l,int r){
    if(l==r) return 0;
    if(l+1==r){
        if(c[l]==c[r]) return 1;
        if(c[l]!=c[r]) return 0;
    }
    if((r-l)%2==0) return max(dp(l,r-1),dp(l+1,r));
    if(c[l]==c[r]) return dp(l+1,r-1)+dp(l,l+1)+dp(r-1,r)+1;
    int maxn=-1;
    for(int k=l+1;k<r;k++){
        int num=dp(l,k)+dp(k+1,r)+dp(k,k+1)+1;
        if(num>maxn){
            maxn=num;
        }
    }
    return maxn;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int ans=0;
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++){
        c[i]=getchar();
    }
    ans=dp(1,n);
    cout<<ans;
    return 0;
}
