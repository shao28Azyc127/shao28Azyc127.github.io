#include<iostream>
#include<climits>
using namespace std;
long long n,ans,a[200001],v,mina[200001],mmm,sumv[200001],d,pos,s;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i = 1;i<n;i++){
        cin>>v;
        sumv[i]=sumv[i-1]+v;
    }
    mmm=LLONG_MAX;
    for(long long i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=mmm){
            mmm=a[i];
            mina[i]=i;
        }
        else mina[i]=mina[i-1];
    }
    if(false/*mina[n]==1*/){
        sumv[n-1]+=d-1;
        sumv[n-1]/=d;
        sumv[n-1]*=a[1];
        cout<<sumv[n-1];
    }
    else{
        pos=1;
        for(int i = 0;i*d<sumv[n-1];i++){
            while(sumv[pos]<=i*d)pos++;
            ans+=a[mina[pos]];
            //cout<<pos<<endl;
            //cout<<mina[pos]<<endl;
            //cout<<a[mina[pos]]<<endl;
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
