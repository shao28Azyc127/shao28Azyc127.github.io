#include<iostream>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll n;
string s;
void init(){
    scanf("%lld",&n);
    cin>>s;
    s=" "+s;
}
namespace pts35{
    const ll MAXN=800+5;
    bool dp[MAXN][MAXN];
    void Do(){
        ll ans=0;
        rep(i,1,n-1){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                //cout<<i<<" "<<i+1<<endl;
                ans++;
            }
        }
        rep(l,3,n){
            for(int i=1;i+l-1<=n;++i){
                ll j=i+l-1;
                if(dp[i+1][j-1]&&s[i]==s[j]){
                    dp[i][j]=true;
                    //cout<<i<<" "<<j<<endl;
                    ans++;
                }else{
                    rep(k,i+1,j-1){
                        if(dp[i][k]&&dp[k+1][j]){
                            dp[i][j]=true;
                            //cout<<i<<" "<<j<<endl;
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    init();
    pts35::Do();
    return 0;
}
