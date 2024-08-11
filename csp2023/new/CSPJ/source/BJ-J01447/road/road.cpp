#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
using ll=long long;
int n,d,cnt=0,oil=0,k,bbb;
int v[100010],a[100010];
void ddd(int i){
    int res=0;
    for(int j=i+1;i<n;j++){
        res+=v[i];
        if(a[i]>a[j]){
            cnt=cnt+ceil(1.0*(res-oil)/d)*a[i];
            if(oil!=0){
                k=oil;
                oil=0;
            }else{
                k=0;
            }
            oil=oil+ceil(1.0*(res-k)/d)*d;
            oil-=(res-k);
            bbb=j;
            break;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(ll i=0;i<n-1;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1] || i==n-2){
            cnt=cnt+ceil(1.0*(v[i]-oil)/d)*a[i];
            if(oil!=0){
                k=oil;
                oil=0;
            }else{
                k=0;
            }
            oil=oil+ceil(1.0*(v[i]-k)/d)*d;
            oil-=(v[i]-k);
            //cout<<v[i]<<endl;
            //cout<<cnt<<endl;
        }else{
            ddd(i);
            i=bbb-1;
            //cout<<cnt<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
