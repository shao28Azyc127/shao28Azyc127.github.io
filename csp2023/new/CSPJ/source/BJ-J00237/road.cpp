#include<bits/stdc++.h>
using namespace std;
int n,d,u[100010],a[100010];
long long min_price,some_more,ans1,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    n--;int j=0;
    while(j<n){
        j++;
        if(j==1){
            ans1=u[j]/d*a[j]+(u[j]%d!=0)*a[j];
            min_price=1;
        }
        else {
            u[j]=u[j]-some_more;
            if(u[j]/d*a[min_price]+(u[j]%d!=0)*a[min_price]>u[j]/d*a[j]+(u[j]%d!=0)*a[j])
                min_price=j;
            ans1=u[j]/d*a[min_price]+(u[j]%d!=0)*a[min_price];
        }
        some_more=(ans1/a[min_price])*d-u[j];
        ans+=ans1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
