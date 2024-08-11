#include<bits/stdc++.h>
using namespace std;

int vis[500005];
bool ml[500005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        memset(vis,-2,sizeof(vis));
        int n,m;
        cin>>n>>m;
        while(m--){
            char a;
            int x,y;
            cin>>a;
            if(a=='U'){
                cin>>x;
                vis[x]=0;
            }
            else if(a=='T'){
                cin>>x;
                vis[x]=1;
            }
            else if(a=='F'){
                cin>>x;
                vis[x]=-1;
            }
            else if(a=='-'){
                cin>>x>>y;

            }
            else if(a=='+'){
                cin>>x>>y;
                vis[x]=vis[y];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0) ans++;
        }
  //      for(int i=1;i<=n;i++){
    //        cout<<vis[i]<<" ";
    //    }
     //   cout<<endl;
        cout<<ans<<endl;
    }

    return 0;
}
