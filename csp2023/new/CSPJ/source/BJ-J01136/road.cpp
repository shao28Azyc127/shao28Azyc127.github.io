#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005],maxs[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,ma=0,sum=0;
    cin>>n>>d;
    for(int i=0;i<=n+5;i++){
        maxs[i]=1e9;
    }
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxs[i]=min(maxs[i-1],a[i]);
        ma=min(ma,a[i]);
    }
    if(a[1]==ma){
        if(sum%d==0){
            cout<<(sum/d)*a[1];
            return 0;
        }
        else{
            cout<<(sum/d+1)*a[1];
            return 0;
        }
    }
    long long cnt=0;
    double sy=0;
    int tmp=0;
    for(int i=1;i<n;i++){
        if(v[i]%d==0){
            tmp=sy/d;
            cnt+=(v[i]/d-tmp)*maxs[i];
            sy=sy-tmp;
        }
        else{
            if((v[i]/d+sy)>=(v[i]*1.0/d)){
                cnt+=(v[i]/d-tmp)*maxs[i];
                sy-=(v[i]*1.0/d)-v[i]/d;
            }
            else{
                tmp=sy/d;
                cnt+=(v[i]/d-tmp+1)*maxs[i];
                sy=sy-tmp;
                sy+=(v[i]/d+1)-(v[i]*1.0/d);
            }
        }
    }
    cout<<cnt;
    return 0;
}
