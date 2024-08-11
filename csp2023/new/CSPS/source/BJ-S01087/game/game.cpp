#include<bits/stdc++.h>
using namespace std;
int n,top;
char c[2000005],zhan[2000005];
long long ans;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)cin>>c[i];
    if(n>11000){
        for(register int i=1;i<n;++i)
            if(c[i]==c[i+1])++ans;
        return printf("%lld",ans),0;
    }
    for(register int i=1;i<=n;++i){
        top=0;
        for(register int j=i;j<=n;++j){
            if(c[j]!=zhan[top])zhan[++top]=c[j];
            else --top;
            if(top==0)++ans;
        }
    }
    return printf("%lld",ans),0;
}