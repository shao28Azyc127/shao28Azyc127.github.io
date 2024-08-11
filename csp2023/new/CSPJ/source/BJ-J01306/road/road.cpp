#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int t,n;
    cin>>n>>t;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int comp=b[1],dis=0,ans=0,yo=0;
    for(int i=1;i<=n;i++){
        if(comp>b[i]){
            if((dis-yo)%t==0)ans+=(dis/t)*comp;
            else{
                ans+=((dis-yo)/t+1)*comp;
                yo=dis%t;
            }
            dis=0;
            comp=b[i];
        }
        dis+=a[i];
    }
    cout<<ans;
    return 0;
}