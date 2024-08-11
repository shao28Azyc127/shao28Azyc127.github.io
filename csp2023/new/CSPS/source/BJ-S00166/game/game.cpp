#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2e6+10;
int n;
ll ans;
char a[maxn],st[maxn];
inline void input(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf(" %c",&a[i]);
}
inline void solve(){
    int top;
    for(int i=1;i<=n;i++){
        top=0;
        for(int j=i;j<=n;j++){
            if(top==0)st[++top]=a[j];
            else{
                if(st[top]==a[j]){
                    --top;
                    if(top==0)++ans;
                }
                else st[++top]=a[j];
            }
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    input();
    solve();
    return 0;
}