#include<bits/stdc++.h>
using namespace std;
int n,d,a[100005],b[100005],c,t=1,flag,h[100005],ans,tmp;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        h[i]=h[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    while(t<=n){
        flag=0;
        for(int i=t+1;i<n;i++){
            if(b[i]<b[t]){
                flag=1;
                if(c>=h[i]-h[t]){
                    c-=h[i]-h[t];
                    t=i;
                }else{
                    tmp=h[i]-h[t]-c;
                    ans+=ceil(tmp*1.0/d)*b[t];
                    c+=ceil(tmp*1.0/d)*d;
                    c-=h[i]-h[t];
                    t=i;
                }
            }
        }
        if(flag==0){
            if(c>=h[n]-h[t]){
                cout<<ans;
                return 0;
            }else{
                tmp=h[n]-h[t]-c;
                ans+=ceil(tmp*1.0/d)*b[t];
                cout<<ans;
                return 0;
            }
        }
    }
    return 0;
}
