#include<bits/stdc++.h>
using namespace std;
int v[100005]={},a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    long long m=0,yl=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(v[i]<yl){
            yl-=v[i];
            continue;
        }
        else{
            int longy=v[i]-yl;
            for(int j=i+1;j<n;j++){
                if(a[i]>=a[j]){
                    break;
                }
                else{
                    longy+=v[j];
                }
            }
            if(longy%d==0){
                yl+=longy;
                m+=longy/d*a[i];
            }
            else{
                yl+=(longy/d+1)*d;
                m+=(longy/d+1)*a[i];
            }
        }
        yl-=v[i];
    }
    cout<<m;
    return 0;
}
