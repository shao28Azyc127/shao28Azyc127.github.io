#include<bits/stdc++.h>
using namespace std;
int n,d,maxn;
long long td,ans,yu;
int a[114514],v[114514];
int main(){
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
     for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    maxn=a[1];
    for(int i=1;i<=n;i++){
        td+=v[i-1];
        if(a[i]<maxn){
            ans+=((td-yu)/d)*maxn;
            if((td-yu)%d!=0) ans+=maxn;
            maxn=a[i];
            yu+=td%d;
            td=0;
            //cout<<ans<<endl;
        }
    }
    if(ans==0){
        ans=td/d*maxn;
    }
    cout<<ans;
    return 0;
}
//虽然连大样例都过不了但能过小样例就知足了qqq
//€€??**??