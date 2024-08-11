#include <bits/stdc++.h>
using namespace std;
int n,d,a[10005],v[10005],sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out"," w",stdout);
    cin>>n>>d;
    for (int i=1;i<n;i++){
        cin>>v[i];
    }
    for (int i=0,i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++){
        if (a[i]<a[i+1]){
            if ((v[i+1]+v[i+2])%d!=0){
                sum+=(((v[i+1]+v[1+2])/d)+1)*a[i];
            }
            else{
                sum+=((v[i+1]+v[1+2])/d)*a[i];
            }
        }
        else{
            if (v[i+1]%d!=0){
                sum+=((v[i+1]/d)+1)*a[i];
            }
            else{
                sum+=(v[i+1]/d)*a[i];
            }
        }
    }
    cout<<sum;
}