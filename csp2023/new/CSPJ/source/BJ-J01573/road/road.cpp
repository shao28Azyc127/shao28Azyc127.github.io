#include<bits/stdc++.h>
using namespace std;

const int maxn=114514;
int n,d,dp[maxn],v[maxn],a[maxn],ans;

struct p{
    int name;
    int xia;
    int xia_l;
    int shang;
    int shang_l;
}pt[maxn];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        pt[i].xia_l=v[i];
        pt[i].name=i;
        pt[i].shang=i-1;
        pt[i].shang_l=v[i-1];
        pt[i].xia=i+1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int n2=n;
    for(int i=2;i<n;i++){
        if(a[pt[i].shang]<=a[i]){
            pt[pt[i].shang].xia_l+=pt[i].xia_l;
            pt[pt[i].xia].shang_l+=pt[i].xia_l;
            pt[pt[i].shang].xia=pt[i].xia;
            pt[pt[i].xia].shang=pt[i].shang;
            n2--;
        }
    }
    int z=0;
    for(int i=1;i!=n;i=pt[i].xia){
        int ptxl=pt[i].xia_l;
        ptxl-=min(z,ptxl);
        z-=min(z,ptxl);
        if(ptxl){
            if(ptxl%d==0){
                ans+=ptxl/d*a[i];
            }
            else{
                ans+=(ptxl/d+1)*a[i];
            }
            z+=(ptxl/d+1)*d-ptxl;
        }
    }
    cout<<ans;
    return 0;
}
