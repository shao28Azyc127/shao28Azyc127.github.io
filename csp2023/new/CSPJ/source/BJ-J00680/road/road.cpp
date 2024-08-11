#include<bits/stdc++.h>
using namespace std;
int n,d,ans,l1[100000],l2[100000],x;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>l1[i];
        ans+=l1[i];
    }
    for(int i=0;i<n;i++){
        cin>>l2[i];
    }
    if(ans%d!=0){
        x=ans/d+1;
        x*=l2[0];
    }
    else{
        x=ans/d;
        x*=l2[0];
    }
    cout<<x;
    return 0;
}
