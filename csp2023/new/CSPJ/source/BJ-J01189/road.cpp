#include<bits/stdc++.h>
using namespace std;
int u[1000001],a[1000001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,s=0,ans=0;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>u[i];
        s+=u[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(s%d==0){
        ans=s/d;
    }else{
        ans=s/d+1;
    }
    ans*=a[1];
    cout<<ans<<endl;;
    fclose(stdin);
    fclose(stdout);
    return 0;
}