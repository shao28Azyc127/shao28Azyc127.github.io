#include<bits/stdc++.h>
using namespace std;
struct station{
    int distance;
    int prize;
}q[100005];
long long n,d,ans,rdistance,minprize;
int main(){
    std::ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>q[i].distance;
    }
    for(int i=0;i<n;i++){
        cin>>q[i].prize;
    }
    minprize=q[0].prize;
    rdistance=q[0].distance;
    for(int i=1;i<n-1;i++){
        if(q[i].prize<minprize){
            ans+=ceil((double)rdistance/d)*minprize;
            minprize=q[i].prize;
            rdistance=rdistance-ceil((double)rdistance/d)*d;
        }
        rdistance+=q[i].distance;
    }
    ans+=ceil((double)rdistance/d)*minprize;
    cout<<ans<<endl;
    return 0;
}
