#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int u[maxn],a[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,l,ans=0,x=1,f,s,m=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(1){
        f=1;
        s=0;
       for(int i=x+1;i<=n;i++){

        if(a[x]>a[i]){
            l=i;
            f=0;
            break;
        }
       }
       if(f)
            l=n;
       for(int i=x;i<=l-1;i++){
        s+=u[i];
       }
       while(m<s){
        m+=d;
        ans+=a[x];

       }
       m-=s;
       x=l;
       if(x==n)
            break;
    }
    cout<<ans;
return 0;
}

