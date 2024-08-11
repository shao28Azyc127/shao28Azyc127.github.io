#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int a[maxn];
int v[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,s;
    cin>>n>>s;
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>v[i];
    int use=v[1];
    int ans=0;
    int l=0;
    float oil=0;
    for(int i=2;i<=n;i++){
        l+=a[i-1];
        if(v[i]<use){
            float k=0;
            k=l*1.00/s;
            if(ceil(k-oil)<ceil(k)){
                    if(oil>k){
                        k=0;
                        oil-=k;
                    }else{
                        k-=oil;
                        oil=0;
                    }
            }
            oil+=ceil(k)-k;
            k=ceil(k);
            ans+=use*k;
            use=v[i];
            l=0;
        }
    }
    cout<<ans;
}
