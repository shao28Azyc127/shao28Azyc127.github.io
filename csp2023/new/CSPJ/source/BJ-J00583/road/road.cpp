#include<bits/stdc++.h>
using namespace std;
struct node{
    int golong,money;
}port[100005];
int main(){
	  freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>port[i].golong;
    }
    for(int i=1;i<=n-1;i++){
        cin>>port[i].money;
    }
    int x;
    cin>>x;
    int howlong=port[1].golong,cnt1=1;
    for(int i=2;i<=n-1;i++){
        cnt1++;
        if(port[i].money>=port[1].money){
            howlong+=port[i].golong;
        }
        else{
            break;
        }
    }
    int cnt=cnt1;
    int ans=howlong/d*port[1].money+(howlong%d!=0)*port[1].money;
    cout<<ans<<" ";
    for(int i=cnt1;i<=n-1;i++){
        int howlong1=port[i].golong;
        for(int j=i+1;j<=n;j++){
            cnt++;
            if(port[j].money>=port[i].money){
                howlong1+=port[j].golong;
            }
            else{
                break;
            }
        }
        ans+=howlong1/d*port[i].money+(howlong1%d!=0)*port[i].money;
        cout<<ans<<" ";
        i=cnt;
    }
    if(cnt==n-1)
        ans+=port[n-1].golong/d*port[n-1].money+(port[n-1].golong%d!=0)*port[n-1].money;
    cout<<ans;
	return 0;
}