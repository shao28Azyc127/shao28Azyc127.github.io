#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N],v[N],w[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    long long jia=0,l=0;
    for(int i=1;i<n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        w[i]=v[i];
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                w[i]+=v[j];
                v[j]=0;
            }
            if(a[j]<=a[i]) break;
        }
    }
    //for(int i=1;i<n;i++) cout<<w[i]<<" ";
    for(int i=1;i<n;i++){
        int k=w[i]-l;
        if(w[i]==0) continue;
        //cout<<l<<" ";
        //if(i==n-1) cout<<"\n"<<k<<" "<<w[i]<<" "<<l<<" ";
        if(k%d!=0){
            jia+=a[i]*(k/d+1);
            l=(k/d+1)*d-k;
        }
        else{
            jia+=a[i]*k/d;
            l=0;
        }
        //cout<<jia<<" "<<l<<" ";
    }
    cout<<jia<<"\n";
    return 0;
}

