#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    long long  d=0,s=0,summ=0,l=0x3f3f3f3f;
    for(int i=1;i<=n-1;i++){
        if(l>b[i]){
            l=b[i];
        }
        int buy=0;
        if((a[i]-s)%m==0){
            buy+=(a[i]-s)/m;
            s=0;
        }
        else{
            buy+=(a[i]-s)/m+1;
            s=m-(a[i]-s)%m;
        }
        summ+=buy*l;
    }
    cout<<summ;
    return 0;
}
