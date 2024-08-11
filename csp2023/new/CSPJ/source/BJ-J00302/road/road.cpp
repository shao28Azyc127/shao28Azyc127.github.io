#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("road1.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,ans=0;
    int x=0;
    int v=0;
    int a[100010];
    int u[100010];
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>u[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>=a[i+1]){
            if(u[i]%d!=0){
                v+=u[i]%d;
                if(v%d==0){
                    ans+=(u[i]/d+1-v/d)*a[i];
                    v=0;
                }
                else{
                    ans+=(u[i]/d+1)*a[i];
                }

            }
            else{
                ans+=u[i]/d*a[i];
            }
        }
        else{
                x=i+1;
            while(a[i]<a[x]){
                x++;
            }
            if((u[i]*(x-i))%d!=0){
                    v+=(u[i]*(x-i))%d;
                ans+=(u[i]*(x-i)/d+1-v/d)*a[i];
            }
            else{
                ans+=u[i]*(x-i)/d*a[i];
            }
            i++;
        }

    }
    cout<<ans;
    return 0;
}
