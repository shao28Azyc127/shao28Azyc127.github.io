#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int v[10000001],a[10000001];
int ans;double ol=0.0;
int main()
{

    int i,j,k,n,d;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    i=1;
    while(1){
        int dis=0;
        for(j=i+1;j<=n;j++){
            dis+=v[j-1];
            int need;double l;
            if(a[j]<a[i]||j==n){
                l=(((dis*1.0)-(ol*(d*1.0)))/(d*1.0));
                need=((dis*1.0)-(ol*(d*1.0)))/(d*1.0);
                if(l - need >0.0){
                    need++;
                }



                //cout<<need<<" "<<ol<<endl;
                ol+=1.0*need;
                ans+=(int)need*a[i];
                ol-=(1.0*dis)/(d*1.0);
                i=j;
                break;
            }
        }
        if(i==n){
            break;
        }
    }
    cout<<ans;
    return 0;
}
