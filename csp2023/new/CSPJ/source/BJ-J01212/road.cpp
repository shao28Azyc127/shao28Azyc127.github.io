#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=100000+5;
struct sta{
    int m,dis;
    double o;
};
sta minn[N];
int dis[N],m[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for (int i=1;i<=n-1;i++) cin>>dis[i];
    for (int i=1;i<=n;i++) cin>>m[i];
    m[n]=-1;
    minn[1].m=m[1];
    minn[1].dis=-1;
    int mins=m[1],cur=1,n_dis=0;
    for (int i=2;i<=n;i++){
        n_dis+=dis[i-1];
        if (mins>m[i]){
            minn[++cur].m=m[i];
            minn[cur].dis=n_dis;
            minn[cur].o=1.0*n_dis/d;
            n_dis=0;
            mins=m[i];
        }
    }
    double ob=0;
    int ans=0;
    for (int i=1;i<cur;i++){
        int p_dis=minn[i+1].dis;
        ans+=(minn[i].m)*ceil(minn[i+1].o-ob);
        ob+=ceil(minn[i+1].o-ob);
        ob-=1.0*p_dis/d;
    }
    cout<<ans;
    return 0;
}
