#include<bits/stdc++.h>
using namespace std;
double n,d,v[100010],a[100010],minn=1,f=1,s,flagg[100010],xx;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        s+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[1]>a[i]) f=0;
    }
    if(f==1){
        cout<<a[1]*(s/d);
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(v[j]<v[i]){
                double aa=0;
                for(int t=i;t<=j-1;t++){
                    aa+=v[t];
                }
                int min2=aa/d;
                if(a[i]*(aa/d)!=a[i]*min2){
                    minn+=a[i]*(min2+1);
                }
                else{
                    minn+=a[i]*(aa/d);
                }
                break;
            }
        }
    }
    cout<<minn;
    return 0;
}
