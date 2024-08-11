#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int a[N],b[N],c[N];
int u,v;
int n;

int gtt(int a,int b,int c,int tme){
    int l=1,r=tme;
    while(l<r){
        int mid=(l+r)>>1;
        if(mid*b+mid*mid*c-mid*c>a)r=mid;
        else l=mid+1;
    }return l;
}

void test(){
    cin>>n;int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(c[i]>=0){
            ans=max(ans,i+gtt(a[i],b[i],c[i],a[i]));
        }else{
            c[i]=-c[i];
            int tme=(b[i]-1)/c[i];
            if(a[i]<b[i]*tme-tme*tme*c[i]+tme*c[i])ans=max(ans,i+gtt(a[i],b[i],c[i],tme));
            else ans=max(ans, i+a[i]-b[i]*tme-tme*tme*c[i]+tme*c[i]+tme);
        }
    }cout<<ans<<endl;
}

signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    test();
    return 0;
}
