#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,c,m;
ll x,y,kx,ky,ix,iy;
ll a[500005],b[500005],ta[500005],tb[500005];
void init(){
    for(int i=1;i<=n;i++){
        ta[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        tb[i]=b[i];
    }
}
bool pd(){//fuhe?
    if(ta[1]==tb[1]) return false;
    else if(ta[1]>tb[1]){
        int j=1;
        for(int i=1;i<=n-1;i++){
            while(ta[i]>tb[j]&&j<m-1) j++;
            if(ta[j]>tb[j]) j++;//pd last
        }
        for(int i=j;i<=m;i++){
            if(ta[n]<=tb[i]) return false;
        }
        return true;
    } else{
        int j=1;
        for(int i=1;i<=m-1;i++){
            while(tb[i]>ta[j]&&j<n-1) j++;
            if(tb[j]>ta[j]) j++;//pd last
        }
        for(int i=j;i<=n;i++){
            if(tb[m]<=ta[i]) return false;
        }
        return true;
    }

}
bool pd_first(){//fuhe?
    if(a[1]==b[1]) return false;
    else if(a[1]>b[1]){
        int j=1;
        for(int i=1;i<=n-1;i++){
            while(a[i]>b[j]&&j<m-1) j++;
            if(a[j]>b[j]) j++;//pd last
        }
        for(int i=j;i<=m;i++){
            if(a[n]<=b[i]) return false;
        }
        return true;
    } else{
        int j=1;
        for(int i=1;i<=m-1;i++){
            while(b[i]>a[j]&&j<n-1) j++;
            if(b[j]>a[j]) j++;//pd last
        }
        for(int i=j;i<=n;i++){
            if(b[m]<=a[i]) return false;
        }
        return true;
    }

}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&b[i]);
    }
    if(pd_first()==true) printf("1");
    else printf("0");
    while(q--){
        scanf("%lld%lld",&kx,&ky);
        init();
        while(kx--){
            scanf("%lld%lld",&ix,&x);
            ta[ix]=x;
        }
        while(ky--){
        scanf("%lld%lld",&iy,&y);
        tb[iy]=y;
        }
   //     for(int i=1;i<=n;i++) cout<<ta[i]<<" ";
    //    cout<<endl;
    //    for(int j=1;j<=m;j++) cout<<tb[j]<<" ";
     //   cout<<endl;
       if(pd()==true) printf("1");
        else printf("0");
    }

    return 0;
}
