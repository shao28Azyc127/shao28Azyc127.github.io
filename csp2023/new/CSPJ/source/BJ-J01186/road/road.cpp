#include <bits/stdc++.h>
using namespace std;
int n,d,last,minn,tmp;
long long ans;
int t;
const int maxn=1e5;
int v[maxn],a[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    minn=a[1];
    for(int i=1;i<=n-1;i++){
            if(min(a[i],minn)==minn){
                t=(v[i]-last)/d;
                if(t*d<v[i]-last)    t++;
                ans+=t*minn;
                tmp=last;
                last=t*d-v[i]+tmp;
            }else{
                minn=a[i];
                t=(v[i]-last)/d;
                if(t*d<v[i]-last)    t++;
                ans+=t*minn;
                tmp=last;
                last=t*d-v[i]+tmp;
            }
    }
    cout<<ans;
    return 0;
}