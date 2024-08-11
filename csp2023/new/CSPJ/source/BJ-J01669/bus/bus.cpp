#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,sum=0;cin>>n>>d;
    int a[100005],b[100005];
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if(sum%d==0){
        cout<<(sum/d)*b[0];
    }else{
        cout<<(sum/d+1)*b[0];
    }
    return 0;
}
