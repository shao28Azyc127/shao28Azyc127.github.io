#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100010],a[100010];
double s,mon,gas;
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
    int j=1;
    while(s<n){
        for(int i=j+1;i<=n;i++){
            if(a[i]>a[j]||i==2){
                s+=v[i];
                mon+=ceil(s/a[j]);
                s+=(int(s)%a[j])*d;
            }else{
                j++;break;
            }
        }
    }
    cout<<mon;
    return 0;
}
