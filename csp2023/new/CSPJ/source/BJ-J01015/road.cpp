#include<bits/stdc++.h>
using namespace std;
int ans=0,s=0,n,d,a[100001],b[100001]={};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=1;i<=n-1;i++){
        cin >> b[i];
    }
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    /*for(int i=1;i<=n-1;i++){
        if(s<b[i]){
            cout  << a[i] << ' ' << a[i+1];
            if(a[i]>=a[i+1]){
                cout << "f";
                s+=(b[i]-s)/d;
                ans+=(b[i]-s)/d*a[i];
                s*=d;
                s-=b[i];
            }
            else{
                cout << "e1";
                s+=(b[i]-s)/d;
                s*=d;
                for(int j=i+1;j<=n;j++){
                    if(a[i]<a[j]){
                        s+=(b[j]-s)/d;
                        ans+=(b[j]-s)/d*a[i];
                        s*=d;
                        s-=b[j];
                    }
                }
            }
        }
        else{
            if(a[i]<a[i+1]){
                cout << "e2";
                s+=(b[i]-s)/d;
                s*=d;
                for(int j=i+1;j<=n;j++){
                    if(a[i]<a[j]){
                        s+=(b[j]-s)/d;
                        ans+=(b[j]-s)/d*a[i];
                        s*=d;
                        s-=b[j];
                    }
                }
            }

        }
        cout << "#" << s << ' ' << ans << endl;
    }*/
    for(int i=1;i<=n-1;i++){
        s+=b[i];
    }
    ans=s/d*a[1];
    cout << s << ' ' << a[1] << ' ' << ans;
    return 0;
}
