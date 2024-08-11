#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int dis[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int sum=0;
    for(int i=1;i<n;i++){
        cin>>dis[i];
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int mn=arr[1];
    for(int i=1;i<n;i++){
        mn=min(mn,arr[i]);
        if(dis[i]%d==0){
            sum+=(dis[i]/d)*mn;
        }
        else{
            sum+=(dis[i]/d+1)*mn;
            dis[i+1]-=(dis[i]/d+1)*d-dis[i];
        }
    }
    cout<<sum;
    return 0;
}
