#include<iostream>
#include<cstdio>
using namespace std;
int n,d;
int a[10005];
int v[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=1;
    int s=0;
    int cnt=0;
    int sy=0;
    for(int i=1;i<=n;i++){
        if(a[i]<a[t]||i==n){
            if((s-sy)%d==0){
                cnt+=(s-sy)/d*a[t];
                sy=0;
            }else{
                cnt+=((s-sy)/d+1)*a[t];
                sy=0;
                sy+=(s/d+1)*d-s;
            }
            t=i;
            s=0;
        }
        s+=v[i];
    }
    cout<<cnt;
    return 0;
}
