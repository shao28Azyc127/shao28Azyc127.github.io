#include<bits/stdc++.h>
using namespace std;
int n,d,v[10005],a[10005];
bool pass[10005];
long long t=0,ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n-1;i++){
        if(pass[i])continue;
        int j,e=0;
        for(j=i+1;j<=n;j++){
            e+=v[j-1];

            if(a[j]<a[i]){
                break;
            }
                pass[j]=1;

        }
        //cout<<ceil(double(e-t)/double(d))<<" "<<t<<" "<<a[i]<<endl;
        ans+=ceil(double(e-t)/double(d))*a[i];
        t=t+ceil(double(e-t)/double(d))*d-e;


    }
    cout<<ans;



    return 0;
}