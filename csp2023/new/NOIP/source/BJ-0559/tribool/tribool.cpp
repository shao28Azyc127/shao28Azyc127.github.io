#include<bits/stdc++.h>
using namespace std;
#define ll long long
//no unknowns
ll t,n,ans=0,cc,m;
char opt,c[100005];
void init(){
    for(int i=1;i<=n;i++){
        c[i]='T';
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%lld%lld",&cc,&t);

    while(t--){
        scanf("%lld%lld",&n,&m);
        ll x;
        ans=0;
        init();
        for(int i=1;i<=m;i++){
            cin>>opt;
            if(opt=='U'){
                scanf("%lld",&x);
                c[x]='U';
            }
            else if(opt=='T'){
                scanf("%lld",&x);
                c[x]='T';
            }
            else if(opt=='F'){
                scanf("%lld",&x);
                c[x]='F';
            }
        }
        for(int i=1;i<=n;i++){
            if(c[i]=='U')ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


