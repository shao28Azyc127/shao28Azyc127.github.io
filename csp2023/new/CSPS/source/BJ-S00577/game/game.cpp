#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define MAXN 2000005
typedef long long ll;
int n;
char s[MAXN];
ll ans;
namespace work1{
    bool f[8005][8005];
    vector<int> nxt[8005];
    void solve(){
        for(int i=1;i<n;i++) if(s[i]==s[i+1]){
            f[i][i+1]=1;
            nxt[i].push_back(i+1);
            ans++;
        }
        for(int r,len=2;len<=n;len++){
            if(len&1) continue;
            for(int l=1;l+len-1<=n;l++){
                r=l+len-1;
                if(l+1<r-1&&f[l+1][r-1]&&s[l]==s[r]){
                    f[l][r]=1;
                    nxt[l].push_back(r);
                    ans++;
                    continue;
                }
                for(auto v:nxt[l]){
                    if(v>=r) break;
                    if(f[v+1][r]){
                        f[l][r]=1;
                        nxt[l].push_back(r);
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("%lld",ans);
    }
}
namespace work2{
    void solve(){

    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    // if(n<=8000) work1::solve();
    // else work2::solve();
    work1::solve();
    return 0;
}