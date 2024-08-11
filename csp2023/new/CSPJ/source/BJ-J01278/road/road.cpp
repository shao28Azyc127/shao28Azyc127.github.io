#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005],oilmoney,k,oilv,sv,av;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=0;i<n-1;i++) {
        scanf("%d",&v[i]);
    }
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n-1;i++) {
        k=0;
        if (a[i]>a[i+1]) {
            if (oilv>=v[i]) {
                oilv-=v[i];
            } else {
                sv=v[i]-oilv;
                if (sv%d==0) {
                    k=sv/d*a[i];
                    oilv=0;
                } else {
                    k=(sv/d+1)*a[i];
                    oilv=k/a[i]*d-sv;
                }
            }
        } else {
            int j;
            av=a[i];
            for (j=i+1;j<n-1;j++) {
                if (a[i]<=a[j]) {
                    av+=a[j];
                } else {
                    break;
                }
            }
            if (oilv>=av) {
                oilv-=av;
            } else {
                if (av%d==0) {
                    k=av/d*a[i];
                    oilv=0;
                } else {
                    k=(av/d+1)*a[i];
                    oilv=k/a[i]*d-av;
                }
            }
            i=j-1;
        }
        oilmoney+=k;
    }
    cout<<oilmoney;
    return 0;
}
