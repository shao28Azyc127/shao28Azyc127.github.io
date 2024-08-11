#include<iostream>
using namespace std;
int v[100005],a[100005];
long long s[100005],ans=0x3f3f3f3f3f3f3f3f;
/*struct Three{
    int cur,tot;
    double gas;
} book2[100005];*/
int n,d,lenb;
void dfs(int cur,int tot,double gas){
    if(tot>=ans){
        return;
    }
    if(cur==n){
        ans=tot;
        return;
    }
    double tmp=gas-v[cur]*1.0/d;
    if(tmp>=0){
        dfs(cur+1,tot,tmp);
    }
    for(int i=1;i*d<=s[cur];i++){
        if(tmp+i>=0){
            dfs(cur+1,tot+i*a[cur],tmp+i);
        }
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=1;i--){
        s[i]=s[i+1]+v[i];
    }
    dfs(1,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
