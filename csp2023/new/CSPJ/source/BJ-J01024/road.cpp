#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,d,a[maxn],u[maxn],cnt;
inline int digui(int x,int y,int now){
    // x means begin y means kms now means cost
    if(x>=n){
        cout<<now<<endl;
        return now;
    }
    int m[n+5]={};
    for(int i=x+1;i<=n;i++){
        /*if(i==n-1){
            if((u[i]-y)%d==0){
            m[i]=digui(i+1,0,now+((u[i]-y)/d)*a[i]);
        }else{
            m[i]=digui(i+1,d-(u[i]-y)%d,(((u[i]-y)/d)+1)*a[i]+now);
        }
        }*/
        if((u[i]-y)%d==0){
            m[i]=digui(i+1,0,now+((u[i]-y)/d)*a[i]);
        }else{
            m[i]=digui(i+1,d-(u[i]-y)%d,(((u[i]-y)/d)+1)*a[i]+now);
        }
    }
    sort(m+2,m+n-1);
    return m[2];
}
inline int minn(int x,int y){
    if(x>y){
        return y;
    }
    return x;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int k=0;
    for(int i=1;i<n;i++){
        k+=u[i];
    }
    int l=0;
    if(k%d==0){
        l=(k/d)*a[1];
    }else{
        l=((k/d)+1)*a[1];
    }
    int cnt=digui(1,0,0);
    int ans=0;
    ans=minn(l,cnt);
    cout<<l<<endl;
    /*if(u[1]%d==0){
        cnt=(u[1]/d)*a[1];
        digui(2,0);
    }else{
        cnt=(u[1]/d+1)*a[1];
    }*/
    fcloseall();
    return 0;
}
