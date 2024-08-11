#include<bits/stdc++.h>
using namespace std;

int n,d;
double v[100005];
int a[100005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=0;i<n-1;i++){
        cin >>v[i];
    }
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    int flag=0,cnt=0;
    double yu;
    long long ans=0;
    for(int i=1;i<n;i++){
        cnt+=v[i-1];
        if(a[i]<a[flag]){
            double tmp=(cnt-yu*d)/d;
            if(int(tmp)<int(tmp+0.9)){
                yu=int(tmp+0.9)-tmp;
            }
            ans+=int(tmp+0.9)*a[flag];
            cnt=0;
            flag=i;
            continue;
        }
    }
    cout << ans;
    return 0;
}