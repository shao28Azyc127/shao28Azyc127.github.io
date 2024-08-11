#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int T,T1;
    cin>>T;
    cin>>T1;
    while(T1--){
        int ans=0;
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char temp;
            cin>>temp;
                if(temp=='T'){
                    int u;
                    cin>>u;
                    vis[u]=0;
                }
                if(temp=='F'){
                    int u;
                    cin>>u;
                    vis[u]=0;
                }
                if(temp=='U'){
                    int u;
                    cin>>u;
                    vis[u]=1;
                }
        }
        for(int i=1;i<=n;i++){
            if(vis[i])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


