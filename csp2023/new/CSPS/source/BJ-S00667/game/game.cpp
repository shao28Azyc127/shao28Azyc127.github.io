#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int n,ans;
bool f[8005][8005];
int st[maxn],top;
char s[maxn];
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        top=0;
        st[top=1]=i;
        for(int j=i+1;j<=n;j++){
            st[++top]=j;
            if(top>1&&s[j]==s[st[top-1]]){
                //f[i][j]=1;
                top-=2;
            }
            if(top==0) f[i][j]=1;
        }
    }
    for(int l=1;l<n;l++){
        for(int r=l+1;r<=n;r++){
            if(f[l][r]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
