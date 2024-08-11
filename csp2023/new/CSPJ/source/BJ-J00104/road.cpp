#include <iostream>
#include <cstring>
using namespace std;
int n,d,a[100005],v[100005],ans=2147483646,b[100005],maxa=-1;
void dfs(int x,int cost,int r){
    if(cost-maxa>b[x]) return;
    b[x]=cost;
    if(x==n){
        ans=min(ans,cost);
    }
    int l=0;
    for(int i = x;i<=n-1;i++){
        l+=v[i];
        int cc=(l-r+d-1)/d;
        dfs(i+1,cost+a[x]*cc,cc*d+r-l);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    int sum=0;
    for(int i = 1;i<=n-1;i++){
        cin >> v[i];

        sum+=v[i];
    }
    bool flag=false;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        maxa=max(maxa,a[i]);
        if(a[i]<a[1]){
            flag=true;
        }
    }
    if(!flag){
        int c=(sum+d-1)/d*a[1];
        cout << c;
        return 0;
    }
    memset(b,0x3f,sizeof(b));
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
