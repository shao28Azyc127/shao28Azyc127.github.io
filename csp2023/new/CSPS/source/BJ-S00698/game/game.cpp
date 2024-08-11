#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=8005;
int n;
char s[N];
int st[N],top;
bool chk(int l,int r){
    top=0;
    for(int i=l;i<=r;i++){
        if(top&&st[top]==s[i]) top--;
        else st[++top]=s[i];
    }
return top==0;
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld%s",&n,s+1);
    int ans=0;
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            ans+=chk(i,j);
    cout<<ans<<endl;
    return 0;
}
