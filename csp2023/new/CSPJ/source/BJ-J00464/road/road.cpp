#include<bits/stdc++.h>
using namespace std;
int n,d;
int v[100005],zc[100005];
int a[100005];
int zhan[100005],top=0,top1=0,lc=0,ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        zc[i+1]=zc[i]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    zhan[++top]=a[1];
    for(int i=2;i<n;i++){
        if(a[i]<zhan[top]){
            zhan[++top]=a[i];
            if((zc[i]-lc)%d==0){
//            cout<<zhan[top-1]<<" "<<(zc[i]-lc)/d<<" "<<zc[i]-lc<<endl;
                ans+=(zc[i]-lc)/d*zhan[top-1];
                lc+=(zc[i]-lc);
            }else{
//                cout<<zhan[top-1]<<" "<<(zc[i]-lc)/d+1<<" "<<zc[i]-lc<<endl;
                ans+=((zc[i]-lc)/d+1)*zhan[top-1];
                lc+=((zc[i]-lc)/d+1)*d;
            }
        }
    }
//    cout<<lc<<" "<<zc[n-1]<<endl;
    if(lc<zc[n]){
        if((zc[n]-lc)%d==0){
                ans+=(zc[n]-lc)/d*zhan[top];
                lc+=(zc[n]-lc);
            }else{
                ans+=((zc[n]-lc)/d+1)*zhan[top];
                lc+=((zc[n]-lc)/d+1)*d;
            }
    }
    cout<<ans;
    return 0;
}
