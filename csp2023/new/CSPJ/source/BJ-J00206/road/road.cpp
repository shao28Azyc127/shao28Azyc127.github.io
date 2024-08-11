#include <bits/stdc++.h>
using namespace std;
FILE *f1=fopen("road.in","r"),*f2=fopen("road.out","w");
int n,m,d,u[100008],a[100008],minn=1e9,w=1,q[100008],ans,s=0;
int f(int x){
    int m=1e9,w,ans=0;
    if(x==2){
        if(q[2]%d==0){
            ans=u[1]/d*a[1];
            return ans;
        }else{
            ans=u[1]/d*a[1];
            s=d-u[1]%d;
            return ans;
        }
    }
    for(int i=1;i<x;i++){
        if(a[i]<m){
            m=a[i];
            w=i;
        }
    }
    ans=f(w);
    if((q[x]-q[w-1]-s)%d==0){
        ans+=(q[x]-q[w-1]-s)/d*a[w];
        s=0;
    }else{
        ans+=(q[x]-q[w-1]-s)/d*a[w]+a[w];
        s=d-(q[x]-q[w-1]-s)%d;
    }
    return ans;
}
int main(){
    fscanf(f1,"%d%d",&n,&d);
    for(int i=1;i<n;i++){
        fscanf(f1,"%d",&u[i]);
        q[i+1]=u[i]+q[i];
    }
    for(int i=1;i<n;i++){
        fscanf(f1,"%d",&a[i]);
        if(a[i]<minn){
            minn=a[i];
            w=i;
        }
    }
    fscanf(f1,"%d",&a[n]);
    if(w==1){
        if(q[n]%d==0){
            ans=(q[n]/d)*a[1];
        }else{
            ans=(q[n]/d+1)*a[1];
        }
        fprintf(f2,"%d",ans);
        return 0;
    }
    ans=f(w);
    ans+=(q[n]-q[w-1]-s)/d*a[w];
    if((q[n]-q[w-1]-s)%d==1){
        ans+=a[w];
    }
    fprintf(f2,"%d",ans);
    return 0;
}
