#include<bits/stdc++.h>
using namespace std;
int a[100000000],u[100000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,x=0,an=0,ans=0;
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>u[i];
    u[n]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1;
    while(l<n){
        int w=0,j=l;
        while(a[l]<=a[j]&&j<n-1){
            j++;
            w+=u[j];
        }
        //if(j==n-1) ;
        if(w%d==0) an=w/d;
        else an=w/d+1;
        ans+=an*a[l];
        x+=an*d-w;
        //cout<<x<<" ";//cout<<an<<" ";
        l=j;
        if(l==n-1) l++;
    }
    ans+=(u[n-1]-x)/d*a[n-1];
    cout<<ans;
    return 0;
}
