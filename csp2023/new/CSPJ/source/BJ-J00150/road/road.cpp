#include<bits/stdc++.h>
using namespace std;
int n,d,r,maxn,ans,minn=2147483646;
int road[100005];
int y[100005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>road[i];
    }
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }
    for(int i=1;i<n;){
        int py=n;
        for(int j=i;j<=n;j++){
            if(y[j]<y[i]){
                py=j;
                break;
            }
        }
        for(int j=i;j<py;j++){
            maxn+=road[j];
        }
        for(;r<maxn;){
            r+=d;
            ans+=y[i];
        }
        r-=maxn;
        i=py;
        maxn=0;
    }
    cout<<ans;
    return 0;
}