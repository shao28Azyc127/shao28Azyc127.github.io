#include<bits/stdc++.h>
using namespace std;

struct node{
    int v,w;
}road[1000005];

int n,d,ans,x;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>road[i].v;
    }
    for(int i=1;i<=n;i++){
        cin>>road[i].w;
    }
    int minn=0x3f3f3f3f;
    for(int i=1;i<n;i++){
        if(minn>road[i].w){
            if(x%d==0){
                ans+=(x/d)*minn;
            }
            else{
                ans+=(x/d+1)*minn;
                x=-(d-(x%d));
            }
            x+=road[i].v;
            minn=road[i].w;
        }
        else x+=road[i].v;
    }
    if(x%d==0){
            ans+=(x/d)*minn;
        }
    else{
        ans+=(x/d+1)*minn;
    }
    cout<<ans<<endl;
    return 0;
}

