#include<bits/stdc++.h>
using namespace std;

int n,d,a[100005],u[100005],s,w;
long long cnt;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=2; i<=n; i++){
        cin >> u[i];
    }
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    s=1;
    if(u[2]%d==0){
        cnt=u[2]/d*a[1];
    }
    else{
        cnt=u[2]/d*a[1]+a[1];
        w=d-u[2]%d;
    }
    for(int i=2; i<n; i++){
        if(w>=u[i+1]){
            w=w-u[i+1];
            if(a[i]<a[s]){
                s=i;
            }
            continue;
        }
        if(a[i]<a[s]){
            s=i;
            if((u[i+1]-w)%d==0){
                cnt+=(u[i+1]-w)/d*a[s];
                w=0;
            }
            else{
                cnt+=(u[i+1]-w)/d*a[s]+a[s];
                w=d-(u[i+1]-w)%d;
            }
        }
        else{
            if((u[i+1]-w)%d==0){
                cnt+=(u[i+1]-w)/d*a[s];
                w=0;
            }
            else{
                cnt+=(u[i+1]-w)/d*a[s]+a[s];
                w=d-(u[i+1]-w)%d;
            }
        }
    }
    cout << cnt;

    return 0;
}
