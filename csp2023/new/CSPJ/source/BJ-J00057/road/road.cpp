#include <iostream>
#include <iomanip>
using namespace std;

long long n,d,v[100005],a[100005],l,b=0,ans=0,f=0;

int main(){
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    cin >> n >> d;
    for (int i=1;i<n;i++){
        cin >> v[i];
    }
    int l;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (i==1) l=a[i];
        else if (a[i]<l){
            if ((b-f)%d==0) ans+=(b-f)/d*l;
            else ans+=((b-f)/d+1)*l,f=((b-f)/d+1)*d-b+f;
            l=a[i];
            b=0;
        }
        b+=v[i];
    }
    cout << ans;
}
