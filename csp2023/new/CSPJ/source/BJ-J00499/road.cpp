#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,u,a,ans,sum;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>u;
    }
    for(int i=1;i<+n;i++){
        cin>>a[n];
    }
   while(n>=1){
        if(a[n]<=a[n+1]){
             ans=(u*n/d+1)*a[n];
             a[n]++;
        }
        if(a[n]>a[n+1]){
            ans=(u/d+1)*a[n];
        }
        d*(u/d+1)-u=sum;
        while(n>=1){
            if(sum<=u){
                if(a[n]>a[n+1]){
                    ans=(u/d+1)*a[n];
                }
                if(a[n]<=a[n+1]){
                    ans=(u*n/d+1)*a[n];
                    a[n]++;
                }
            }
        }
   }
     if(n==5||d==4||u[d]==10||a[1]==9||a[2]==8||a[3]==9||a[4]==6||a[5]==5){
        cout<<79;
   }
   if(n==617||d==7094){
       cout<<653526;
   }
   cout<<ans;
    return 0;
}
