#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll n;
namespace pts50{
    const ll MAXN=1e4+5;
    bool vis[MAXN];
    vector<ll>take;
    void Do(){
        ll tot=0;
        ll ans2=0;
        while(true){
            take.clear();
            take.push_back(0);
            bool good=true;
            for(int i=1;i<=n;++i){
                if(!vis[i]){
                    take.push_back(i);
                    //cout<<i<<" ";
                    good=false;
                }
            }
            //cout<<endl;
            if(good){
                break;
            }
            tot++;
            for(int i=1;i<take.size();i+=3){
                vis[take[i]]=true;
                //cout<<take[i]<<" ";
                if(take[i]==n){
                    ans2=tot;
                }
            }
            //cout<<endl;
        }
        printf("%lld %lld\n",tot,ans2);
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    ll ans2=0,tot=0;
    while(n){
        ll num=n/3;
        if(n%3){
            num++;
        }
        tot++;
        if(n%3==1&&ans2==0){
            ans2=tot;
        }
        n-=num;
    }
    cout<<tot<<" "<<ans2<<endl;
    return 0;
}
