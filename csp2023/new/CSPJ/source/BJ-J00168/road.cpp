#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=1e5+5;
int n,d;
int dis[N];
int price[N];
int mn[N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    mn[0]=1e9;
    for(int i=1;i<n;i++)cin>>dis[i];
    for(int i=1;i<=n;i++){
        cin>>price[i];
        mn[i]=min(mn[i-1],price[i]);
    }
    ll ans=0;
    for(int i=1;i<n;i++){
        int tmp=ceil(1.0*dis[i]/d),mr;//the oil needed
        mr=tmp*d-dis[i];
        for(int j=i+1;j<n;j++){ //the extra fuel(actully O(1))
            if(dis[j]<=mr){
                mr-=dis[j];
                dis[j]=0;
            }
            else{
                dis[j]-=mr;
                mr=0;
                break;
            }
        }
        ans+=(1ll*tmp*mn[i]);
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
