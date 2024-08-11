#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long int n,d,a[100005],b[100005],sum=0;
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n-1;i++){
        sum+=a[i];
    }
    cout<<sum/d*b[0];
return 0;
}
