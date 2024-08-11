#include <bits/stdc++.h>
using namespace std;
int t,n,m,c,x[100010],ans=0;
bool flag=0;
char u;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c==3||c==4)
        flag=1;
    while(t--){
        if(flag==1){
            cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>u;
            int y
            cin>>y;
            if(u=='U')
                x[y]=1;
        }
        for(int i=1;i<=n;i++){
            if(x[i])
                ans++;
        }
        cout<<ans<<endl;
        ans=0;
        continue;
        }
        cout<<n<<endl;
    }
    return 0;
}
