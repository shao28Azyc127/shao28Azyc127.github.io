#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,sum=0,ans=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int minn=100000000;
    for(int i=1;i<=n;i++){
        minn=min(minn,b[i]);
    }
    for(int i=1;i<=n;i++){//station
        if(b[i]==minn){//
            for(int j=i;j<n;j++){//sum add
                sum+=a[j];
            }
            for(int j=1;j<=9999999;j++){//ans
                if(d*j>=sum){
                        ans+=b[i]*j/2;
                break;    }   ///////////////
            }
            cout<<ans;
        }else{
            if(b[i]>b[i+1]){
                    for(int j=1;j<=9999999;j++){//ans
                        if(d*j>=sum){
                        ans+=b[i]*j/2;
                        break;
                    }   ///////////////
                }
            }
        }
    }
    return 0;
}
