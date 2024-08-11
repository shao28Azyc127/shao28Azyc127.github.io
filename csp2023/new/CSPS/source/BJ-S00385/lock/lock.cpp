#include <bits/stdc++.h>
using namespace std;
int v[10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    memset(v,0,sizeof(v));
    int n,a,ans=0; cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++){
            cin>>a; v[i][a]=1;
        }
    for(int j=0;j<9;j++){
        int sum=0;
        for(int i=1;i<=n;i++)
            sum+=v[i][j];
        v[n+1][j]=sum;
        if(sum>1) ans=10-sum;
    }
    if(n==1) cout<<81<<endl;
    else cout<<ans<<endl;
    fclose(stdin); fclose(stdout);
    return 0;
}
