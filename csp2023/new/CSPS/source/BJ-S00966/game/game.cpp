#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000010;
ll n,dp[N],p[N],ans,l;
string s;
void tell(){
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return ;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    cin>>s;
    s=' '+s;
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1]){
            dp[i]++;
            p[i]=2;
            if(i-2>=1){
               dp[i]+=dp[i-2];
                p[i]+=p[i-2];
            }
        }else if(i-p[i-1]-1>=1){
            if(s[i-p[i-1]-1]==s[i]&&p[i-1]){
                dp[i]+=dp[i-p[i-1]-2]+1;
                p[i]=p[i-p[i-1]-2]+p[i-1]+2;
            }
        }
        ans+=dp[i];
    }
    //tell();
    printf("%lld",ans);
    return 0;
}

