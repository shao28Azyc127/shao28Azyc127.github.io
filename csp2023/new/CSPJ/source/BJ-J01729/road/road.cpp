#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[100005],v[100005];
int ans,x=1,is=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int j=i+1;
        if(i==1||a[i]>a[j]){
            while(x*d<v[i]){
                x++;
            }
            ans+=x*a[i];
        }else if(a[i]<a[j]){
            while(x*d<2*v[i]){
                x++;
            }
            ans+=x*a[i];
            is=1;
            }
    }
    cout<<ans;
    return 0;
}
