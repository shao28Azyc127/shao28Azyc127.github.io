#include<bits/stdc++.h>
using namespace std;
long long n,d,v,ans,c=2,u[100000],a[100001];
double yx;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++)cin>>u[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;){
        do{
            v+=u[c];
        }while(a[i]<a[c++]);
        yx+=(v%d==0?v/d:v/d+1);
        ans+=(v%d==0?v/d:v/d+1)*a[i];
        yx-=v*1.0/d;
        cout<<i<<' '<<(v%d==0?v/d:v/d+1)<<endl;
        i=c+1;
    }
    cout<<ans;
    return 0;
}
