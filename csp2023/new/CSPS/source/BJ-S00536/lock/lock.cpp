#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll a[10];
}s[10];
ll ans=0;
ll v[10];
ll n;
void dfs(ll x){
    if(x>5){
        bool flag=1;
        for (int i=1;i<=n;i++){
            ll cntdif=0;
            for (int j=1;j<=5;j++){
                if(v[j]!=s[i].a[j]){
                    cntdif++;
                }
            }
            if(cntdif>2){
                flag=0;
                break;
            }
            if(cntdif==0){
                flag=0;
                break;
            }
            if(cntdif==1){
                continue;
            }
            if(cntdif==2){
                bool ai=0;
                ll wei1,wei2;
                for(int j=1;j<=4;j++){
                    if(v[j]!=s[i].a[j]&&v[j+1]!=s[i].a[j+1]){
                        wei1=j,wei2=j+1;
                        ai=1;
                        break;
                    }
                }
                if(!ai){
                    flag=0;
                    break;
                }
                bool ok=0;
                ll tmp1=v[wei1],tmp2=v[wei2];
                for (int j=1;j<=10;j++){
                    tmp1++;
                    tmp1%=10;
                    tmp2++;
                    tmp2%=10;
                    if(tmp1==s[i].a[wei1]&&tmp2==s[i].a[wei2]){
                        ok=1;
                        break;
                    }
                }
                if(!ok){
                    flag=0;
                    break;
                }
            }
        }
        ans+=flag;
        return ;
    }
    for (int i=0;i<=9;i++){
        v[x]=i;
        dfs(x+1);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        scanf("%lld%lld%lld%lld%lld",&s[i].a[1],&s[i].a[2],&s[i].a[3],&s[i].a[4],&s[i].a[5]);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
