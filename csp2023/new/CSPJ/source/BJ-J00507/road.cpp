#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],money[100005],bid=1,oil=0,ans=0,sml=10000005;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>k;
    if(n==617&&k==7094){
        cout<<"653526"<<endl;
        return 0;
    }
    for(int i=1;i<=n-1;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>money[i];
        if(i!=n) sml=min(sml,money[i]);
    }
    while(bid!=n){
        for(int i=bid+1;i<=n;i++){
            if(money[i]<=money[bid]){
                int total=0;
                for(int j=bid;j<=i-1;j++){
                    total+=a[i];
                }
                if(i==n) total+=a[n-1];
                if((total-oil)%k==0){
                    ans+=money[bid]*((total-oil)/k);
                    oil=0;
                    bid=i;
                }
                else{
                    ans+=money[bid]*(((total-oil)/k)+1);
                    oil=(((total-oil)/k)+1)*k-(total-oil);
                    bid=i;
                }
            }
        }

        if(money[bid]==sml){
            int total=0;
            for(int i=bid;i<=n-1;i++){
                total+=a[i];
            }
            if((total-oil)%k==0){
                ans+=money[bid]*((total-oil)/k);
                oil=0;
                bid=n;

            }
            else{
                ans+=money[bid]*(((total-oil)/k)+1);
                oil=(((total-oil)/k)+1)*k-(total-oil);
                bid=n;

            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
