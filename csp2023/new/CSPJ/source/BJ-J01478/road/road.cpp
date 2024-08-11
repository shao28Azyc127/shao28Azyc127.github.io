#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005];
long long s[100005];
int main(){
    freopen("road.in","r","stdin");
    freopen("road.out","w","stdout");
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        s[i+1]=s[i]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int m=0,ans=0,i=1;
    while(i<n){
        int f=0;
        for(int j=i+1;j<=n-1;j++){
            if(a[i]>a[j]){
                f=1;
                int x=s[j]-s[i];
                if(x>m){
                    int t=(x-m)/d;
                    if(t*d+m<x) t++;
                    ans+=t*a[i];
                    m+=t*d;
                }
                m-=x;
                i=j;
                break;
            }
        }
        if(f==0){
            int x=s[n]-s[i];
            int t=(x-m)/d;
            if(t*d+m<x) t++;
            ans+=t*a[i];
            i=n;
        }
    }
    cout<<ans;
    return 0;
}