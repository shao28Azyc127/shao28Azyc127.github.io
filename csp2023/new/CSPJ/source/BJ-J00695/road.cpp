#include <bits/stdc++.h>
long long ans,add;
using namespace std;
#define int long long
stack<int> s;
const int xx=1e5+5;
int ba[xx],cost[xx],dis[xx],n,d,dd[xx];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>dis[i];
    }
    for(int i=n;i>=1;i--) ba[i]=ba[i+1]+dis[i],dd[i]=n;
    s.push(1);
    cin>>cost[1];
    for(int i=2;i<=n;i++) {
        cin>>cost[i];
        int t=s.top();
        while(!s.empty()&&cost[t]>cost[i]){
            s.pop();
            dd[t]=i;
            if(!s.empty())t=s.top();
        }
        s.push(i);
    }
    for(int i=1;i<n;i=dd[i]){
        ans+=(add+ba[i]-ba[dd[i]]+d-1)/d*cost[i];
        add=add+ba[i]-ba[dd[i]]-((add+ba[i]-ba[dd[i]]+d-1)/d*d);
    }
    cout<<ans;
    return 0;
}
