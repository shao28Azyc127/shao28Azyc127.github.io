#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,a[100005],v[100005],nes;
    long long sum=0,ans=0,l=0;
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>v[i];
    }
    v[n-1]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    nes=a[0];
    for(int i=0;i<n;i++){
        ans+=v[i];
        if(l>=ans-((ans/d)*d)){
            ans=((ans/d)*d);
            l-=(ans-(ans/d)*d);
        }
        if(a[i]<nes){
            if(ans%d==0){
                sum+=ans/d*nes;
            }
            else{
                sum+=((ans/d)+1)*nes;
            }
            l+=d*((ans/d)+1)-ans;
            nes=a[i];
            ans=0;
        }
    }
    cout<<sum;
    return 0;
}