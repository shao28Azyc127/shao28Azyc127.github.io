#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],u[100005],v[100005],t[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    bool f=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        cin>>u[i]>>v[i];
        if(u[i]!=i || v[i]!=i+1){
            f=0;
        }
    }
    if(f==1){
        int day=0;
        int sy=n;
        while(sy>0){
            day++;
            for(int i=1;i<=min(n,day);i++){
                t[i]+=max(1,b[i]+c[i]*day);
                if(t[i]>=a[i]){
                    sy--;
                    a[i]=1e9;
                    t[i]=-1e9;
                }
            }
        }
        cout<<day;
    }
    return 0;
}
