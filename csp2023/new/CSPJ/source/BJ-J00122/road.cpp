#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int s[100005],a[100005];
    s[0]=0;
    for(int i=1;i<n;i++){
        int k;
        cin>>k;
        s[i]=s[i-1]+k;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=-a[i];
    }
    int p=0,sum=0;
    int z=0;
    while(1){
        int u=lower_bound(a+p,a+n+1,a[p])-a;
        if(u==n||u==n-1){
            int x=s[n-1]-s[p];
            int bu=x/d;
            if(bu*d+z<x){
                bu++;
            }
            z=bu*d+z-x;
            if(z>=d){
                bu-=z/d;
                z=z%d;
            }
            sum+=bu*(-a[p]);
            break;
        }
        else{
            int x=s[u]-s[p];
            int bu=x/d;
            if(bu*d+z<x){
                bu++;
            }
            z=bu*d+z-x;
            if(z>=d){
                bu-=z/d;
                z=z%d;
            }
            sum+=bu*(-a[p]);
            p=u;
        }
    }
    cout<<sum;
    return 0;
}
